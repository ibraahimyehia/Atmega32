s/*
 * WTD_int.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_TIMER_WTD_TIMER_WTD_INT_H_
#define MCAL_TIMER_WTD_TIMER_WTD_INT_H_


void WTD_vDisabl();

void WTD_vEnable();




/* sleep options
 * 0 --> 16.3 ms
 * 1 --> 32.5 ms
 * 2 --> 65 ms
 * 3 --> 0.13 sec
 * 4 --> 0.26 sec
 * 5 --> 0.52 sec
 * 6 --> 1.0 sec
 * 7 --> 2.1 sec
 */

#define WTD_SLEEP_16_3_ms       0
#define WTD_SLEEP_32_5_ms       1
#define WTD_SLEEP_65_ms         2
#define WTD_SLEEP_0_13_sec      3
#define WTD_SLEEP_0_26_sec      4
#define WTD_SLEEP_0_52_sec      5
#define WTD_SLEEP_1_sec       6
#define WTD_SLEEP_2_1_sec       7



void WTD_vSetSleep(u8 A_u8SleepTime);





#endif /* MCAL_TIMER_WTD_TIMER_WTD_INT_H_ */
