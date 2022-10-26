/*
 * 8BIT_pri.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_TIMER_8_BIT_COUNT0_8BIT_PRI_H_
#define MCAL_TIMER_8_BIT_COUNT0_8BIT_PRI_H_


#define  TIMER0_STOP_TIMER						0
#define  TIMER0_NO_PRESCALER					1
#define  TIMER0_8_PRESCALER  					2
#define  TIMER0_64_PRESCALER 					3
#define  TIMER0_256_PRESCALER 					4
#define  TIMER0_1024_PRESCALER					5
#define  TIMER0_EXTERNAL_CLC_FALLING_EDGE		6
#define  TIMER0_EXTERNAL_CLC_RAISING_EDGE		7


#define  OVF_MODE					0
#define  CTC_MODE 					1
#define  FAST_PWM					2
#define  PHASE_CORRECT_PWM			3

#define OC0_DISCONECTED		0
#define OC0_TOGGLE			1
#define OC0_CLEAR			2
#define OC0_SET				3


#define PWM_NON_INVERTING 		0
#define PWM_INVERTING 			1



#endif /* MCAL_TIMER_8_BIT_COUNT0_8BIT_PRI_H_ */
