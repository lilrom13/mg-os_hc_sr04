/*
* Copyright (c) 2014-2018 Cesanta Software Limited
* All rights reserved
*
* Licensed under the Apache License, Version 2.0 (the ""License"");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an ""AS IS"" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "mgos.h"
#include "mgos_hc_sr04.h"

bool mgos_hc_sr04_init()
{
  return true;
}

hc_sr04 *hc_sr04_init(int _trig_pin, int _echo_pin)
{
  hc_sr04 *h = (hc_sr04 *) malloc(sizeof(hc_sr04));

  if (h)
  {
    h->trig_pin = _trig_pin;
    h->echo_pin = _echo_pin;

    if (!mgos_gpio_set_mode(h->trig_pin, MGOS_GPIO_MODE_OUTPUT) ||
          !mgos_gpio_set_mode(h->echo_pin, MGOS_GPIO_MODE_INPUT))
    {
      // error during mode setting. Add log here
      return NULL;
    }
  }

  return h;
}

bool hc_sr04_read(hc_sr04 *h)
{
  // set high to trigger ping during 10u
  mgos_gpio_write(h->trig_pin, true);
  mgos_usleep(10);
  mgos_gpio_write(h->trig_pin, false);

  LOG(LL_INFO, ("hello from read"));

  return true;
}
