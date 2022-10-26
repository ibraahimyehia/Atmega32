/*
 * 8BIT_cfg.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_TIMER_8_BIT_COUNT0_8BIT_CFG_H_
#define MCAL_TIMER_8_BIT_COUNT0_8BIT_CFG_H_


/* from PIN configuration from DATA sSHEET we can see that  OC0 - PB3*/



/* TIMER0 Prescaler Options :
 *
 *  ############## defined in private file ##############################################
 *
 * 1- TIMER0_STOP_TIMER
 * 2- TIMER0_NO_PRESCALER
 * 3- TIMER0_8_PRESCALER
 * 4- TIMER0_64_PRESCALER
 * 5- TIMER0_256_PRESCALER
 * 6- TIMER0_1024_PRESCALER  IMER0_1024_PRESCALER
 * 7- TIMER0_EXTERNAL_CLC_FALLING_EDGE
 * 8- TIMER0_EXTERNAL_CLC_RAISING_EDGE
 * #######################################################################################
 */

#define TIMER0_SET_PRESCALER   TIMER0_8_PRESCALER


/*
 * TIMER0 mode Options:
 * #####################  WAVE GENRATION MODE ################################################
 * ##################### defined in private file #############################################
 * 1- OVF_MODE
 * 2-CTC_MODE
 * 3-FAST_PWM
 * 4-PHASE_CORRECT_PWM
 */

#define TIMER0_MODE  FAST_PWM




/*
 * TIMER0 Pin Options:
 * #####################  WAVE GENRATION MODE ################################################
 * ##################### defined in private file #############################################
 * 1-OC0_DISCONECTED
 * 2-OC0_TOGGLE
 * 3-OC0_CLEAR
 * 4-OC0_SET
 */

#define TIMER0_PIN_MODE   OC0_DISCONECTED




/* TIME0 PWM MODE OPTIONS:
 * 1- PWM_NON_INVERTING      -->   Duty Cycle (Normal To) OCR
 * 2- PWM_INVERTING 		 -->   Duty Cycle (Opposite To) OCR
 */

#define TIMER0_PMW_MODE   PWM_NON_INVERTING





#endif /* MCAL_TIMER_8_BIT_COUNT0_8BIT_CFG_H_ */
