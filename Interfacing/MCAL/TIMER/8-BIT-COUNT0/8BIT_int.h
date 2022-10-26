/*
 * 8BIT_int.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_TIMER_8_BIT_COUNT0_8BIT_INT_H_
#define MCAL_TIMER_8_BIT_COUNT0_8BIT_INT_H_

/* timer initialization:
 * 1-Enable Timer
 * 2-Prescaler
 * 3-Timer Mode
 * 4-Set OC0 Pin State    disconected - set - clear - toggle
 */
void TIMER0_vInit();

void TIMER0_vStop();


/* Set Preload to Satart Count From The Preload Value*/
void TIME0_vSetPreload(u8 A_u8PreloadVal);


/* Set OCR Value to be the TOP counts to generate CTC Flag */
void TIME0_vSetOcrVal(u8 A_u8OcrVal);


/* Set Call back to Execute The ISR(interrupt service Routine) related with OVF Event */
void TIMER0_vCallBackOvf(void(*Fptr)(void));

/* Set Call back to Execute The ISR(interrupt service Routine) related with CTC Event */
void TIMER0_vCallBackCtc(void(*Fptr)(void));


#define VAL_LOW  0
#define VAL_HIGH 1



#endif /* MCAL_TIMER_8_BIT_COUNT0_8BIT_INT_H_ */
