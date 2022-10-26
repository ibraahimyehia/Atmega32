/*
 * main.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Ibrahim
 */
#include <avr/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"


#include "MCAL/UART/UART_int.h"
#include "HAL/LED/LED_int.h"

#include "MCAL/DIO/DIO_int.h"




 int main(void){

	 /* PD0 --> Input RX*/
	 DIO_vSetPinDir(PORTD_ID , PIN0_ID , DIR_INPUT);
	 /* PD1 --> Output TX*/
	 DIO_vSetPinDir(PORTD_ID , PIN1_ID , DIR_OUTPUT);
	 /* PA0 --> Output LED0 */
	// LED_vInit(LED0_ID);
	 /* PD7 --> Output for LED */
	 DIO_vSetPinDir(PORTD_ID , PIN7_ID , DIR_OUTPUT);

	 /* ENABLE UART */
	 UART_vInit();
	 /* Send Hello World! */
	 	 	 	 /* Highly Recommended to store String at Arr Then send the Arr in function(Arr) as function(Hello) will store data in FLASH!!!!! */
	 	 u8* Arr;
	 	 Arr = "Hello Word!";
	 	 UART_vSendString(Arr);




	 	 u8 statu ;
	 while(1){

		 /* if send HIGH LED Turn On */
		 statu = UART_u8ReceiveChar();
		 switch(statu){
		 case '1': DIO_vSetPinVal(PORTD_ID , PIN7_ID , VAL_HIGH); break;
		 case '0': DIO_vSetPinVal(PORTD_ID , PIN7_ID , VAL_LOW); break;
		 }
	 }
 }
