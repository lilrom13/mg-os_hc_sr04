/*
 * Copyright 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __HC_SR04__
#define __HC_SR04__

#include "mgos.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hc_sr04_t
{
  int trig_pin;
  int echo_pin;
} hc_sr04;

bool     mgos_hc_sr04_init(void);

hc_sr04 *hc_sr04_init(int _trig_pin, int _echo_pin);
bool     hc_sr04_read(hc_sr04 *h);


#ifdef __cplusplus
}
#endif

#endif // __HC_SR04__
