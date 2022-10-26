/*
 * ADC_reg.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_

#define SFIOR *( (volatile  u8*) 0x50)



#define ADMUX *( (volatile  u8*) 0x27)
#define ADCSRA *( (volatile  u8*) 0x26)


#define ADCH *( (volatile  u8*) 0x25)
#define ADCL *( (volatile  u8*) 0x24)
#define ADC_DATA *( (volatile u16*) 0x24)  /* as the two registers follow each other we can read and write data from them at once by
   	   	   	   	   	   	   	   	   	   	   	   	   u16 pointer -- u16 = 8bit + 8bit aka two registers accssising     */




#endif /* MCAL_ADC_ADC_REG_H_ */
