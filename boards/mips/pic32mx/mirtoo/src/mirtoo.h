/****************************************************************************
 * boards/mips/pic32mx/mirtoo/src/mirtoo.h
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

#ifndef __BOARDS_MIPS_PIC32MX_MIRTOO_SRC_MIRTOO_H
#define __BOARDS_MIPS_PIC32MX_MIRTOO_SRC_MIRTOO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

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

/****************************************************************************
 * Name: pic32mx_spi2initialize
 *
 * Description:
 *   Called to configure SPI2 chip select GPIO pins for the Mirtoo module.
 *
 ****************************************************************************/

#ifdef CONFIG_PIC32MX_SPI2
void weak_function pic32mx_spi2initialize(void);
#endif

/****************************************************************************
 * Name: pic32mx_led_initialize
 *
 * Description:
 *   Configure on-board LEDs if LED support has been selected.
 *
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void pic32mx_led_initialize(void);
#endif

/****************************************************************************
 * Name: pic32mx_adcinitialize
 *
 * Description:
 *   Perform architecture specific ADC initialization
 *
 ****************************************************************************/

#ifdef CONFIG_PIC32MX_ADC

/* int pic32mx_adcinitialize(void); not used */

#endif

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_MIPS_PIC32MX_MIRTOO_SRC_MIRTOO_H */
