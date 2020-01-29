/* Copyright (c) 2018 Arm Limited
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "mbed.h"
 
#if !defined(MBED_THREAD_STATS_ENABLED)
#error "Stats not enabled"
#endif
 
#define MAX_THREAD_STATS    0x8

// Initialise the digital pin LED1 as an output
DigitalOut led1(LED1);

#define MAX_THREAD_STACK 224

int32_t wait_time_ms = 5000;

void blinky()
{
    volatile uint64_t i = ~0;
    while(i--) {
        led1 = !led1;
        thread_sleep_for(wait_time_ms);
    }
}

void idle()
{
    volatile uint64_t i = ~0;    
    while(i--) { 
        thread_sleep_for(wait_time_ms);
    }
}

int main()
{
    Thread *blinky_thread,
           *idle_thread;    
    mbed_stats_thread_t *stats = new mbed_stats_thread_t[MAX_THREAD_STATS];
    
    blinky_thread = new Thread(osPriorityNormal, MAX_THREAD_STACK, nullptr, "blinky_thread");
    blinky_thread->start(blinky);

    idle_thread = new Thread(osPriorityNormal, MAX_THREAD_STACK, nullptr, "idle_thread");
    idle_thread->start(idle);

    int count = mbed_stats_thread_get_each(stats, MAX_THREAD_STATS);
    for(int i = 0; i < count; i++) {
        printf("ID: 0x%x \n", stats[i].id);
        printf("Name: %s \n", stats[i].name);
        printf("State: %d \n", stats[i].state);
        printf("Priority: %d \n", stats[i].priority);
        printf("Stack Size: %d \n", stats[i].stack_size);
        printf("Stack Space: %d \n", stats[i].stack_space);
        printf("\n");
    }
   
    blinky_thread->terminate();
    idle_thread->terminate();    
    return 0;
}
