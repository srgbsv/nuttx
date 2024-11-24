/****************************************************************************
 * boards/arm/stm32/stm32f4discovery/src/stm32_pwm_output.c
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
#include <syslog.h>

#include "nucleo-h743zi.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* PWM Input
 *
 */

#define HAVE_PWM_OUTPUT 1

#if !defined(CONFIG_PWM)
#  undef HAVE_PWM_OUTPUT
#endif

#if !defined(CONFIG_PWM_OUTPUT)
#  undef HAVE_PWM_OUTPUT
#endif

#if ! defined(CONFIG_STM32_TIM1) \
    && ! defined(CONFIG_STM32_TIM2) \
    && ! defined(CONFIG_STM32_TIM3) \
    && ! defined(CONFIG_STM32_TIM4)\
    && ! defined(CONFIG_STM32_TIM5) \
    && ! defined(CONFIG_STM32_TIM6) \
    && ! defined(CONFIG_STM32_TIM7) \
    && ! defined(CONFIG_STM32_TIM8)
#  undef HAVE_PWM_OUTPUT
#endif

#if ! defined(CONFIG_STM32_TIM1_PWM) \
    && ! defined(CONFIG_STM32_TIM2_PWM) \
    && ! defined(CONFIG_STM32_TIM3_PWM) \
    && ! defined(CONFIG_STM32_TIM4_PWM)\
    && ! defined(CONFIG_STM32_TIM5_PWM) \
    && ! defined(CONFIG_STM32_TIM6_PWM) \
    && ! defined(CONFIG_STM32_TIM7_PWM) \
    && ! defined(CONFIG_STM32_TIM8_PWM)
#  undef HAVE_PWM_OUTPUT
#endif

#ifdef HAVE_PWM_OUTPUT
/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_pwm_out_setup
 *
 * Description:
 *   Initialize and register the pwm_output driver.
 *
 * Input parameters:
 *   timer num - Output timer num (1-8)
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/
int stm32_pwm_out_setup(int tnum)
{
#ifdef HAVE_PWM_OUTPUT
  static bool initialized[12];
  struct pwm_lowerhalf_s *pwm;
  int ret;

  /* Have we already initialized? */

  if (!initialized[tnum])
  {
    /* Get an instance of the PWM interface */

    pwm = stm32_pwminitialize(tnum);
    if (!pwm)
    {
      syslog(LOG_ERR, "Failed to initialize pwm");
      tmrerr("ERROR: Failed to get the STM32 PWM lower half\n");
      return -ENODEV;
    }

    char devpath[13];
    sprintf(devpath, "/dev/pwmout%d", tnum);

    ret = pwm_register(devpath, pwm);
    if (ret < 0)
    {
      syslog(LOG_ERR, "Failed to register pwm");
      tmrerr("ERROR: pwm_register failed: %d\n", ret);
      return ret;
    }

    /* Now we are initialized */

    initialized[tnum] = true;
  }

  return OK;
#else
  return -ENODEV;
#endif
}

#endif /* HAVE_PWM_OUTPUT */
