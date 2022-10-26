/*
 * UART_int.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_UART_UART_INT_H_
#define HAL_UART_UART_INT_H_

/* you can define UCSRC bits by enum and set each one mode in prog.c
 * examble
 * enum {
 * 		UCPOL,
 * 		UCSZ0,
 * 		UCSZ1,
 * 		USBS,
 * 		UPM0,
 * 		UPM1,
 * 		UMSEL,
 * 		URSEL,
 * 		} UCSRC_BITS;
 *
 * 		void UART_vRegisterSelecrt{
 * 		SET_BIT(UCSRC , URSEL) --> go and set bit 7 in register to be 1
 * 		}
 *
 * 		##and so on##
 */

/*
 * 		#####################################################################################################################################
 * 		######################################## START OF INITALIZATION #####################################################################
 * 		#####################################################################################################################################
*/





void UART_vInit();

void UART_vSendChar(u8 A_u8Sdata);

u8 UART_u8ReceiveChar();

void UART_vSendString(u8* A_u8SrtingSend);

void UART_vReceiveString(u8* A_u8SrtingReceived);


#define LOW  0
#define HIGH 1



#endif /* HAL_UART_UART_INT_H_ */
