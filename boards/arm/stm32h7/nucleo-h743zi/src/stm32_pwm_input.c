/****************************************************************************
 * boards/arm/stm32/stm32f4discovery/src/stm32_capture.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <errno.h>
#include <debug.h>
#include <nuttx/timers/capture.h>
#include <arch/board/board.h>

#include "chip.h"
#include <stdio.h>

#include "stm32.h"
#include "stm32_capture.h"
#include "arm_internal.h"

#include "nucleo-h743zi.h"

#if defined(CONFIG_CAPTURE)
/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* PWM Input
 *
 */

#define HAVE_PWM_INPUT 1

#if defined(CONFIG_PWM_INPUT)
#  undef HAVE_PWM_INPUT
#endif

#if ! defined(CONFIG_STM32_TIM1) \
    && ! defined(CONFIG_STM32_TIM2) \
    && ! defined(CONFIG_STM32_TIM3) \
    && ! defined(CONFIG_STM32_TIM4)\
    && ! defined(CONFIG_STM32_TIM5) \
    && ! defined(CONFIG_STM32_TIM6) \
    && ! defined(CONFIG_STM32_TIM7) \
    && ! defined(CONFIG_STM32_TIM8)
#  undef HAVE_PWM_INPUT
#endif

#if ! defined(CONFIG_STM32_TIM1) \
    && ! defined(CONFIG_STM32_TIM2) \
    && ! defined(CONFIG_STM32_TIM3) \
    && ! defined(CONFIG_STM32_TIM4)\
    && ! defined(CONFIG_STM32_TIM5) \
    && ! defined(CONFIG_STM32_TIM6) \
    && ! defined(CONFIG_STM32_TIM7) \
    && ! defined(CONFIG_STM32_TIM8)
#  undef HAVE_PWM_INPUT
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_pwm_input_setup
 *
 * Description:
 *   Initialize and register the pwm_input driver.
 *
 * Input parameters:
 *   timer num - Capture timer num (1-8)
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int stm32_pwm_input_setup(int tnum)
{
#ifdef HAVE_PWM_INPUT
  syslog(LOG_ERR, "HAVE_PWM_INPUT defined\n");
  struct cap_lowerhalf_s *capture;
  int ret;

  capture = stm32_cap_initialize(tnum);

  char devpath[12];
  sprintf(devpath, "/dev/pwmin%d", tnum);

  /* Then register the pwm capture sensor */

  ret = cap_register(devpath, capture);
  if (ret < 0)
    {
      syslog(LOG_ERR, "Error registering capture\n");
      mtrerr("ERROR: Error registering capture\n");
    }

  return ret;
#else
  syslog(LOG_ERR, "HAVE_PWM_INPUT not defined\n");
  return -ENODEV;
#endif
}

#endif /* CONFIG_CAPTURE */
