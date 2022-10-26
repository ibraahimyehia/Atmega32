/*
 * ADC_int.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_


enum ADC_ID{
	ADC_ID0,
	ADC_ID1,
	ADC_ID2,
	ADC_ID3,
	ADC_ID4,
	ADC_ID5,
	ADC_ID6,
	ADC_ID7
};



void ADC_vInit(void);
/* no  need for ser direction as output for each register as its not Port or Pins or DDR */

/* -----------------------------------------------------------
 * ADMUX Register     page212
 -----------------------------------------------------------*/

/*Reference Selection Bits 7,6*/





/* ---------------------------------------------------------
 * ADCSRA Register
 * --------------------------------------------------------- */
/*ADC Enable*/
/*ADC  Start Conversion*/
/*ADC Auto Trigger Enable */
/*ADC Prescaler Select Bits*/





u16 ADC_u16GetDigValSync(u8 A_u8ChannelId);

/* typedef void (*Ptr_func_IvOv_t)(void); // should be in STD_TYPES.h */


void ADC_u16GetDigValAsync(Ptr_func_IvOv_t  ptr_func , u8 A_u8ChannelId);












#endif /* MCAL_ADC_ADC_INT_H_ */
