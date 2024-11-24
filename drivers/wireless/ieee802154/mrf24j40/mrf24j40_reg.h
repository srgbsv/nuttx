/****************************************************************************
 * drivers/wireless/ieee802154/mrf24j40/mrf24j40_reg.h
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

#ifndef __DRIVERS_WIRELESS_IEEE802154_MRF24J40_MRF24J40_REG_H
#define __DRIVERS_WIRELESS_IEEE802154_MRF24J40_MRF24J40_REG_H

/* MRF24J40 Registers *******************************************************/

#define MRF24J40_RXMCR     0x00
#define MRF24J40_PANIDL    0x01
#define MRF24J40_PANIDH    0x02
#define MRF24J40_SADRL     0x03
#define MRF24J40_SADRH     0x04
#define MRF24J40_EADR0     0x05
#define MRF24J40_EADR1     0x06
#define MRF24J40_EADR2     0x07
#define MRF24J40_EADR3     0x08
#define MRF24J40_EADR4     0x09
#define MRF24J40_EADR5     0x0A
#define MRF24J40_EADR6     0x0B
#define MRF24J40_EADR7     0x0C
#define MRF24J40_RXFLUSH   0x0D
#define MRF24J40_ORDER     0x10
#define MRF24J40_TXMCR     0x11
#define MRF24J40_ACKTMOUT  0x12
#define MRF24J40_ESLOTG1   0x13
#define MRF24J40_SYMTICKL  0x14
#define MRF24J40_SYMTICKH  0x15
#define MRF24J40_PACON0    0x16
#define MRF24J40_PACON1    0x17
#define MRF24J40_PACON2    0x18
#define MRF24J40_TXBCON0   0x1A
#define MRF24J40_TXNCON    0x1B
#define MRF24J40_TXG1CON   0x1C
#define MRF24J40_TXG2CON   0x1D
#define MRF24J40_ESLOTG23  0x1E
#define MRF24J40_ESLOTG45  0x1F
#define MRF24J40_ESLOTG67  0x20
#define MRF24J40_TXPEND    0x21
#define MRF24J40_WAKECON   0x22
#define MRF24J40_FRMOFFSET 0x23
#define MRF24J40_TXSTAT    0x24
#define MRF24J40_TXBCON1   0x25
#define MRF24J40_GATECLK   0x26
#define MRF24J40_TXTIME    0x27
#define MRF24J40_HSYMTMRL  0x28
#define MRF24J40_HSYMTMRH  0x29
#define MRF24J40_SOFTRST   0x2A
#define MRF24J40_SECCON0   0x2C
#define MRF24J40_SECCON1   0x2C
#define MRF24J40_TXSTBL    0x2E
#define MRF24J40_RXSR      0x30
#define MRF24J40_INTSTAT   0x31
#define MRF24J40_INTCON    0x32
#define MRF24J40_GPIO      0x33
#define MRF24J40_TRISGPIO  0x34
#define MRF24J40_SLPACK    0x35
#define MRF24J40_RFCTL     0x36
#define MRF24J40_SECCR2    0x37
#define MRF24J40_BBREG0    0x38
#define MRF24J40_BBREG1    0x39
#define MRF24J40_BBREG2    0x3A
#define MRF24J40_BBREG3    0x3B
#define MRF24J40_BBREG4    0x3C
#define MRF24J40_BBREG6    0x3E
#define MRF24J40_CCAEDTH   0x3F

#define MRF24J40_FIFO_BASE     0x80000000
#define MRF24J40_LONGREG_BASE  0x80000200
#define MRF24J40_RXBUF_BASE    0x80000300

#define MRF24J40_TXNORM_FIFO   (MRF24J40_FIFO_BASE + 0x000)
#define MRF24J40_BEACON_FIFO   (MRF24J40_FIFO_BASE + 0x080)
#define MRF24J40_GTS1_FIFO     (MRF24J40_FIFO_BASE + 0x100)
#define MRF24J40_GTS2_FIFO     (MRF24J40_FIFO_BASE + 0x180)

#define MRF24J40_RFCON0    (MRF24J40_LONGREG_BASE + 0x00)
#define MRF24J40_RFCON1    (MRF24J40_LONGREG_BASE + 0x01)
#define MRF24J40_RFCON2    (MRF24J40_LONGREG_BASE + 0x02)
#define MRF24J40_RFCON3    (MRF24J40_LONGREG_BASE + 0x03)
#define MRF24J40_RFCON5    (MRF24J40_LONGREG_BASE + 0x05)
#define MRF24J40_RFCON6    (MRF24J40_LONGREG_BASE + 0x06)
#define MRF24J40_RFCON7    (MRF24J40_LONGREG_BASE + 0x07)
#define MRF24J40_RFCON8    (MRF24J40_LONGREG_BASE + 0x08)
#define MRF24J40_SLPCAL0   (MRF24J40_LONGREG_BASE + 0x09)
#define MRF24J40_SLPCAL1   (MRF24J40_LONGREG_BASE + 0x0A)
#define MRF24J40_SLPCAL2   (MRF24J40_LONGREG_BASE + 0x0B)
#define MRF24J40_RFSTATE   (MRF24J40_LONGREG_BASE + 0x0F)
#define MRF24J40_RSSI      (MRF24J40_LONGREG_BASE + 0x10)
#define MRF24J40_SLPCON0   (MRF24J40_LONGREG_BASE + 0x11)
#define MRF24J40_SLPCON1   (MRF24J40_LONGREG_BASE + 0x20)
#define MRF24J40_WAKETIMEL (MRF24J40_LONGREG_BASE + 0x22)
#define MRF24J40_WAKETIMEH (MRF24J40_LONGREG_BASE + 0x23)
#define MRF24J40_REMCNTL   (MRF24J40_LONGREG_BASE + 0x24)
#define MRF24J40_REMCNTH   (MRF24J40_LONGREG_BASE + 0x25)
#define MRF24J40_MAINCNT0  (MRF24J40_LONGREG_BASE + 0x26)
#define MRF24J40_MAINCNT1  (MRF24J40_LONGREG_BASE + 0x27)
#define MRF24J40_MAINCNT2  (MRF24J40_LONGREG_BASE + 0x28)
#define MRF24J40_MAINCNT3  (MRF24J40_LONGREG_BASE + 0x29)
#define MRF24J40_TESTMODE  (MRF24J40_LONGREG_BASE + 0x2F)
#define MRF24J40_ASSOEADR0 (MRF24J40_LONGREG_BASE + 0x30)
#define MRF24J40_ASSOEADR1 (MRF24J40_LONGREG_BASE + 0x31)
#define MRF24J40_ASSOEADR2 (MRF24J40_LONGREG_BASE + 0x32)
#define MRF24J40_ASSOEADR3 (MRF24J40_LONGREG_BASE + 0x33)
#define MRF24J40_ASSOEADR4 (MRF24J40_LONGREG_BASE + 0x34)
#define MRF24J40_ASSOEADR5 (MRF24J40_LONGREG_BASE + 0x35)
#define MRF24J40_ASSOEADR6 (MRF24J40_LONGREG_BASE + 0x36)
#define MRF24J40_ASSOEADR7 (MRF24J40_LONGREG_BASE + 0x37)
#define MRF24J40_ASSOSADR0 (MRF24J40_LONGREG_BASE + 0x38)
#define MRF24J40_ASSOSADR1 (MRF24J40_LONGREG_BASE + 0x39)
#define MRF24J40_UPNONCE0  (MRF24J40_LONGREG_BASE + 0x40)
#define MRF24J40_UPNONCE1  (MRF24J40_LONGREG_BASE + 0x41)
#define MRF24J40_UPNONCE2  (MRF24J40_LONGREG_BASE + 0x42)
#define MRF24J40_UPNONCE3  (MRF24J40_LONGREG_BASE + 0x43)
#define MRF24J40_UPNONCE4  (MRF24J40_LONGREG_BASE + 0x44)
#define MRF24J40_UPNONCE5  (MRF24J40_LONGREG_BASE + 0x45)
#define MRF24J40_UPNONCE6  (MRF24J40_LONGREG_BASE + 0x46)
#define MRF24J40_UPNONCE7  (MRF24J40_LONGREG_BASE + 0x47)
#define MRF24J40_UPNONCE8  (MRF24J40_LONGREG_BASE + 0x48)
#define MRF24J40_UPNONCE9  (MRF24J40_LONGREG_BASE + 0x49)
#define MRF24J40_UPNONCE10 (MRF24J40_LONGREG_BASE + 0x4A)
#define MRF24J40_UPNONCE11 (MRF24J40_LONGREG_BASE + 0x4B)
#define MRF24J40_UPNONCE12 (MRF24J40_LONGREG_BASE + 0x4C)

/* INTSTAT bits */

#define MRF24J40_INTSTAT_TXNIF     (1 << 0)
#define MRF24J40_INTSTAT_TXG1IF    (1 << 1)
#define MRF24J40_INTSTAT_TXG2IF    (1 << 2)
#define MRF24J40_INTSTAT_RXIF      (1 << 3)
#define MRF24J40_INTSTAT_SECIF     (1 << 4)
#define MRF24J40_INTSTAT_HSYMTMRIF (1 << 5)
#define MRF24J40_INTSTAT_WAKEIF    (1 << 6)
#define MRF24J40_INTSTAT_SLPIF     (1 << 7)

/* RXMCR bits */

#define MRF24J40_RXMCR_PROMI       (1 << 0) /* Enable promisc mode (rx all valid packets) */

#define MRF24J40_RXMCR_ERRPKT      0x02 /* Do not check CRC */
#define MRF24J40_RXMCR_COORD       0x04 /* Enable coordinator mode     ??? DIFFERENCE ??? - not used in datasheet! */
#define MRF24J40_RXMCR_PANCOORD    0x08 /* Enable PAN coordinator mode ??? DIFFERENCE ??? */
#define MRF24J40_RXMCR_NOACKRSP    0x20 /* Enable auto ACK when a packet is rxed */

/* TXMCR bits */

#define MRF24J40_TXMCR_CSMABF0     (1 << 0)
#define MRF24J40_TXMCR_CSMABF1     0x02
#define MRF24J40_TXMCR_CSMABF2     0x04
#define MRF24J40_TXMCR_MACMINBE0   0x08
#define MRF24J40_TXMCR_MACMINBE1   0x10
#define MRF24J40_TXMCR_SLOTTED     0x20
#define MRF24J40_TXMCR_BATLIFEXT   0x40
#define MRF24J40_TXMCR_NOCSMA      0x80

/* ACKTMOUT bits */

#define MRF24J40_ACKTMOUT_MAWD     0xEF
#define MRF24J40_ACKTMOUT_DRPACK   0x80

/* INTCON bits */

#define MRF24J40_INTCON_SLPIE      0x80
#define MRF24J40_INTCON_WAKEIE     0x40
#define MRF24J40_INTCON_HSYMTMRIE  0x20
#define MRF24J40_INTCON_SECIE      0x10
#define MRF24J40_INTCON_RXIE       0x08
#define MRF24J40_INTCON_TXG2IE     0x04
#define MRF24J40_INTCON_TXG1IE     0x02
#define MRF24J40_INTCON_TXNIE      (1 << 0)

/* BBREG1 bits */

#define MRF24J40_BBREG1_RXDECINV   0x04 /* Enable/Disable packet reception */

/* BBREG2 bits */

#define MRF24J40_BBREG2_CCAMODE_ED 0x80
#define MRF24J40_BBREG2_CCAMODE_CS 0x40

/* TXNCON bits */

#define MRF24J40_TXNCON_TXNTRIG    (1 << 0) /* Trigger packet tx, automatically cleared */

#define MRF24J40_TXNCON_TXNSECEN   0x02 /* Enable security */
#define MRF24J40_TXNCON_TXNACKREQ  0x04 /* An ACK is requested for this pkt */
#define MRF24J40_TXNCON_INDIRECT   0x08 /* Activate indirect tx bit (for coordinators) */
#define MRF24J40_TXNCON_FPSTAT     0x10 /* Status of the frame pending big in txed acks */

/* TXSTAT bits */

#define MRF24J40_TXSTAT_TXNSTAT    (1 << 0)
#define MRF24J40_TXSTAT_TXG1STAT   (1 << 1)
#define MRF24J40_TXSTAT_TXG2STAT   (1 << 2)
#define MRF24J40_TXSTAT_CCAFAIL    (1 << 5)
#define MRF24J40_TXSTAT_X_SHIFT    6
#define MRF24J40_TXSTAT_X_MASK     (3 << MRF24J40_TXSTAT_X_SHIFT)

/* TXBCON0 bits */

#define MRF24J40_TXBCON0_TXBTRIG   0x01
#define MRF24J40_TXBCON0_TXBSECEN  0x02

/* TXBCON1 bits */

#define MRF24J40_TXBCON1_RSSINUM   0x30
#define MRF24J40_TXBCON1_NWU_BCN   0x40
#define MRF24J40_TXBCON1_TXBMSK    0x80

/* WAKECON bits */

#define MRF24J40_WAKECON_INTL      0x3F
#define MRF24J40_WAKECON_REGWAKE   0x40
#define MRF24J40_WAKECON_IMMWAKE   0x80

/* WAKECON bits */

#define MRF24J40_WAKECON_INTL      0x3F
#define MRF24J40_WAKECON_REGWAKE   0x40
#define MRF24J40_WAKECON_IMMWAKE   0x80

/* ESLOTG1 bits */

#define MRF24J40_ESLOTG1_CAP       0x0F
#define MRF24J40_ESLOTG1_GTS1      0xF0

/* SLPCAL2 bits */

#define MRF24J40_SLPCAL2_SLPCAL    0x0F
#define MRF24J40_SLPCAL2_SLPCALEN  0x10
#define MRF24J40_SLPCAL2_SLPCALRDY 0x80

/* RFCON7 bits */

#define MRF24J40_RFCON7_SEL_32KHZ  0x40
#define MRF24J40_RFCON7_SEL_100KHZ 0x80

/* SLPACK bits */

#define MRF24J40_SLPACK_WAKECNT0_6 0x7F
#define MRF24J40_SLPACK_SLPACK     0x80

/* RFCTL bits */

#define MRF24J40_RFCTRL_RFRXMODE   0x01
#define MRF24J40_RFCTRL_RFTXMODE   0x02
#define MRF24J40_RFCTRL_RFRST      0x03
#define MRF24J40_RFCTRL_WAKECNT7_8 0x18

/* RXFLUSH bits */

#define MRF24J40_RXFLUSH_RXFLUSH   0x01
#define MRF24J40_RXFLUSH_BCNONLY   0x02
#define MRF24J40_RXFLUSH_DATAONLY  0x04
#define MRF24J40_RXFLUSH_CMDONLY   0x08
#define MRF24J40_RXFLUSH_WAKEPAD   0x20
#define MRF24J40_RXFLUSH_WAKEPOL   0x40

#define MRF24J40_RXFLUSH_SHIFT_RXFLUSH   0
#define MRF24J40_RXFLUSH_SHIFT_BCNONLY   1
#define MRF24J40_RXFLUSH_SHIFT_DATAONLY  2
#define MRF24J40_RXFLUSH_SHIFT_CMDONLY   3
#define MRF24J40_RXFLUSH_SHIFT_WAKEPAD   5
#define MRF24J40_RXFLUSH_SHIFT_WAKEPOL   6

/* SLPCON1 bits */

#define MRF24J40_SLPCON1_CLKOUT_DISABLED 0x20

#endif /* __DRIVERS_WIRELESS_IEEE802154_MRF24J40_MRF24J40_REG_H */
