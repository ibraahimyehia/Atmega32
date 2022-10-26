/*
 * ADC_prg.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Ibrahim
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include"ADC_int.h"
#include"ADC_reg.h"
#include"ADC_pri.h"
#include"ADC_cfg.h"







void ADC_vInit(void){

/* -----------------------------------------------------------
 * ADMUX Register     page212
 -----------------------------------------------------------*/

/*Reference Selection Bits 7,6*/
	SET_BIT(ADMUX , 7);
	CLR_BIT(ADMUX , 6);


/* Adjustment set to be right Adjust Bit 5 */
	CLR_BIT(ADMUX , 5);


/* ---------------------------------------------------------
 * ADCSRA Register
 * --------------------------------------------------------- */
/*ADC Enable*/
	SET_BIT(ADCSRA , 7);



/*ADC Auto Trigger Enable we will not use it */

	/*ADC Prescaler Select Bits*/

	ADCSRA = ( (ADCSRA & 0b11111000) | ADC_PRESCALLER ); /* last three bits is the prescaler bits so by anded it by
	 zeros by register to clear it and or with the priscaler number */


}


u16 ADC_u16GetDigValSync(u8 A_u8ChannelId){

	/* -----------------------------------------------------------
	 * ADMUX Register     page212
	 -----------------------------------------------------------*/

	/* 1- Channel Selection Bits 0:4 */
	ADMUX = ( (ADMUX & 0b11100000) | A_u8ChannelId ); // last 5 bits set as user entered ADC_ID0  or ADC_ID1 etc



	/* ---------------------------------------------------------
	 * ADCSRA Register
	 * --------------------------------------------------------- */

	/* 2- ADC Start Conversion
	 * ADSC BIT 6
    */
		SET_BIT(ADCSRA , 6);


	/* 3- Busy Wait ADC Flag to show that Conversion complete
	 * • Bit 4 – ADIF: ADC Interrupt Flag
	 *  see page 214
	 */
		while(GET_BIT(ADCSRA , 4) != 1);   /* while 0 conversion still going while 1 conversion complete */

		/* but what if the ADIF flag is a bad sector and damaged the system will stop forever so we need a timeout to declare
		 * there is an error at the flag or it will go right and return data
		 */


		/* 4- Clear ADC Complete Conversion Flag by seeting 1 on the Flag bit
		 * • Bit 4 – ADIF: ADC Interrupt Flag
		 */

		    SET_BIT(ADCSRA , 4);

		/* 5- Update ADC return Variable */
		    return ADC_DATA;
}




void ADC_u16GetDigValAsync(Ptr_func_IvOv_t  ptr_func , u8 A_u8ChannelId){

	/* -----------------------------------------------------------
	 * ADMUX Register     page212
	 -----------------------------------------------------------*/

	/* 1- Channel Selection Bits 0:4 */
	ADMUX = ( (ADMUX & 0b11100000) | A_u8ChannelId ); // last 5 bits set as user enterd ADC_ID0  or ADC_ID1 etc



	/* ---------------------------------------------------------
	 * ADCSRA Register
	 * --------------------------------------------------------- */

	/* 2- enable ADC Interrupt
	 * • Bit 3 – ADIE: ADC Interrupt Enable
	 */
	SET_BIT(ADCSRA , 3);


	/* 3- ISR CALL */
	  G_ptr_func = ptr_func;


	/* 4- STaert Conversion */
	SET_BIT(ADCSRA , 6);
}



/* ISR Defination */
void __Vector_16 (void){
	/*call for gobals interrupt function */
	G_ptr_func;

	/* DIsable ADC INterrupt*/
	SET_BIT(ADCSRA , 3);


}











