/****************************************************************************
 * boards/misoc/lm32/misoc/include/board.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __BOARDS_MISOC_LM32_MICOS_INCLUDE_BOARD_H
#define __BOARDS_MISOC_LM32_MICOS_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* Assume default CLKDIV8 fuse setting is overridden to CLKDIV1 */

#define BOARD_XTAL_FREQ        14745600         /* 14.7456MHz crystal */
#define BOARD_CPU_CLOCK        BOARD_XTAL_FREQ  /* F_CPU = 14.7456MHz */
#define BOARD_TOSCK_CLOCK      32768            /* TOSC  = 32.768KHz */

/* LED definitions **********************************************************/

/* The Amber Web Server has a reset switch and four LEDs. The LEDs indicate
 * the status of power, programming state, Ethernet link status and reset
 * status (Active).  None are available for software use.
 */

#define LED_STARTED            0
#define LED_HEAPALLOCATE       1
#define LED_IRQSENABLED        2
#define LED_STACKCREATED       3
#define LED_INIRQ              4
#define LED_SIGNAL             5
#define LED_ASSERTION          6
#define LED_PANIC              7

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_MISOC_LM32_MICOS_INCLUDE_BOARD_H */
