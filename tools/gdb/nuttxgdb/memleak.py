############################################################################
# tools/gdb/nuttxgdb/memleak.py
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################

import bisect
import time
from typing import Dict, Generator, List

import gdb

from . import memdump, mm, utils


class GlobalNode(memdump.MMNodeDump):
    def __init__(self, address: int, nodesize: int):
        self.address = address
        self.nodesize = nodesize
        self.pid = None
        self.seqno = None
        self.overhead = 0
        self.backtrace = ()

    def __repr__(self):
        return f"GlobalVar@{self.address:x}:{self.nodesize}Bytes"

    def contains(self, addr: int) -> bool:
        pass

    def read_memory(self) -> memoryview:
        return gdb.selected_inferior().read_memory(self.address, self.nodesize)


class MMLeak(gdb.Command):
    """Dump memory manager heap"""

    def __init__(self):
        self.elf = utils.import_check(
            "elftools.elf.elffile", "ELFFile", "Please pip install pyelftools\n"
        )
        if not self.elf:
            return

        super().__init__("mm leak", gdb.COMMAND_USER)
        utils.alias("memleak", "mm leak")

    def global_nodes(self) -> List[GlobalNode]:
        nodes: List[GlobalNode] = []

        longsize = utils.get_long_type().sizeof
        for objfile in gdb.objfiles():
            elf = self.elf.load_from_path(objfile.filename)
            symtab = elf.get_section_by_name(".symtab")
            symbols = filter(
                lambda s: s["st_info"]["type"] == "STT_OBJECT"
                and s["st_size"] >= longsize,
                symtab.iter_symbols(),
            )

            for symbol in symbols:
                size = symbol["st_size"] // longsize * longsize
                address = symbol["st_value"]
                nodes.append(GlobalNode(address, size))

        return nodes

    def invoke(self, arg: str, from_tty: bool) -> None:
        heaps = memdump.get_heaps("g_mmheap")
        pids = [int(tcb["pid"]) for tcb in utils.get_tcbs()]

        def is_pid_alive(pid):
            return pid in pids

        t = time.time()
        print("Loading globals from elf...", flush=True, end="")
        good_nodes = self.global_nodes()  # Global memory are all good.
        print(f" {time.time() - t:.2f}s", flush=True, end="\n")

        nodes_dict: Dict[int, memdump.MMNodeDump] = {}
        sorted_addr = set()
        t = time.time()
        print("Gather memory nodes...", flush=True, end="")
        for node in memdump.dump_nodes(heaps, {"no_pid": mm.PID_MM_MEMPOOL}):
            nodes_dict[node.address] = node
            sorted_addr.add(node.address)

        sorted_addr = sorted(sorted_addr)
        print(f" {time.time() - t:.2f}s", flush=True, end="\n")

        regions = [
            {"start": start.address, "end": end.address}
            for heap in heaps
            for start, end in heap.regions
        ]

        longsize = utils.get_long_type().sizeof

        def pointers(node: memdump.MMNodeDump) -> Generator[int, None, None]:
            # Return all possible pointers stored in this node
            size = node.nodesize - node.overhead
            memory = node.read_memory()
            while size > 0:
                size -= longsize
                ptr = int.from_bytes(memory[size : size + longsize], "little")
                if any(region["start"] <= ptr < region["end"] for region in regions):
                    yield ptr

        print("Leak analyzing...", flush=True, end="")
        t = time.time()
        for good in good_nodes:
            for ptr in pointers(good):
                if not (idx := bisect.bisect_right(sorted_addr, ptr)):
                    continue

                node = nodes_dict[sorted_addr[idx - 1]]
                if node.contains(ptr):
                    del sorted_addr[idx - 1]
                    good_nodes.append(node)

        print(f" {time.time() - t:.2f}s", flush=True, end="\n")

        leak_nodes = memdump.group_nodes(nodes_dict[addr] for addr in sorted_addr)
        memdump.print_header()
        total_blk = total_size = 0
        for node in leak_nodes.keys():
            count = len(leak_nodes[node])
            total_blk += count
            total_size += count * node.nodesize
            memdump.print_node(
                node, is_pid_alive(node.pid), count=len(leak_nodes[node])
            )

        print(f"Leaked {total_blk} blks, {total_size} bytes")
