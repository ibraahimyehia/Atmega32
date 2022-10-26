/*
 * ADC_pri.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_ADC_ADC_PRI_H_
#define MCAL_ADC_ADC_PRI_H_


#define ADC_PRESCALLER_2	1
#define ADC_PRESCALLER_4	2
#define ADC_PRESCALLER_8	3
#define ADC_PRESCALLER_16	4
#define ADC_PRESCALLER_32 	5
#define ADC_PRESCALLER_64   6
#define ADC_PRESCALLER_128  7


Ptr_func_IvOv_t  G_ptr_func;


void __vector_16 (void) __attribute__((signal));




#endif /* MCAL_ADC_ADC_PRI_H_ */
