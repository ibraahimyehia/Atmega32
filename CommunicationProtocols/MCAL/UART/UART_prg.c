/*
 * UART_prg.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Ibrahim
 */
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"

#include"UART_reg.h"
#include"UART_cfg.h"
#include"UART_int.h"


/*
 * BAUD Baud rate (in bits per second, bps) --> we will work on baud rate of 9600
 * fOSC System Oscillator clock frequency = 8000000 HZ
 * UBRR Contents of the UBRRH and UBRRL Registers, (0 - 4095)
 *
 *        EQuation BAUD = fOSC/ 16(UBRR+1)
 *        so we set the BAUD rate by settin value of UBRR
 *        UBRR =  ( fOSC / 16*BAUD ) -1  -->  UBRR alomst = 51
 *        ---------------------------------------------------------------------------------------
 *        UBRR[11:8] in REGISTER UBRRH  +  UBRR[7:0] in REGISTER UBRRL  = 12 Bit  0b0000 00000000
 *        UBBR = 51 ----->  0b0000 00110100
 *
 *#######REGISTER UBRRH = 0  the rest of the rgister is not importent and normal to be 0                                                   #########################
 *#######REGISTER UBRRL = 0b00110100  as known as  52 decimal u can write it at once as the we own the whole register for this operation   #########################
 *#######                                                                                                                                  #########################
 *#######Asynchronous Normal Mode (U2X = 0)  U2X Bit 1 -->  UCSRA                                                                          #########################
 *
 */


void UART_vInit(){


			/* SET Baud Rate to 9600 */
			UBRRL = 51 ;
			CLR_BIT(UCSRA , 1);

//
//			/* SELECT UART MODE */
//			UCSRC |= MODE;
//


			/* ENABLE RX , TX */         /*  -- UCSRB --  */
				/* • Bit 4 – RXEN: Receiver Enable*/
			WRT_BIT(UCSRB , 4 , HIGH);

				/* • Bit 3 – TXEN: Transmitter Enable*/
			WRT_BIT(UCSRB , 3 , HIGH);



//			/* PARITY MODE */
//			UCSRC &= 0b11001111; /* Bit Masking*/
//			UCSRC |= PARITY_MODE;
//
//			/* STOP BIT SELECT */
//			UCSRC &= 0b11110111; /* Bit Masking*/
//			UCSRC |= STOP_BITS_SIZE;
//

			/* DATA SIZE SELECT */  /* -- 8 BIT -- */
					/* 0   1   1 */
		//	UCSRB &= 0b11111011; UCSRB |= 0b00000000;
//			UCSRC &= 0b11111001; UCSRC |= 0b00000110;
//
//
//			/* SELECT REGISTER UCSRC OVER UBRRH */
//			UCSRC &= 0b01111111; UCSRC |= 0b10000000;
//



	/* ##############################################################################################################################################
	 * ############################### reading the register in the current clock cycle will return the UCSRC contents   #############################
	 * ############################### SO WE HAVE TO RIGHT EVERY BITS ON UCSRC REGISTER AT ONCE (AT THE SAME CLK CYCLE) #############################
	 * ##############################################################################################################################################
	 * */
					//UCSRC = MODE | PARITY_MODE | STOP_BITS_SIZE | (0b00000110 /*DATA SIZE SELECT*/) | (0b10000000 /*SELECT REGISTER UCSRC*/ ) ;
					UCSRC = 0b10000110 ;



}





void UART_vSendChar(u8 A_u8Data){

	/* • Bit 5 – UDRE: USART Data Register Empty --> UCSRA
	 *   If UDRE is one, the buffer is empty */
	u8 FLAG;
	FLAG = GET_BIT(UCSRA , 5);  /* FLAG = 0 there is data */

	/* busy wait until UART is Empty */
	while(FLAG == 0);
	 /* once flag=1 it will stop as there is no more Data */
		UDR = A_u8Data;


}




u8 UART_u8ReceiveChar(){

	/*  Bit 7 – RXC: USART Receive Complete --> UCSRA
	 * RXC - cleared when the receive buffer is empty (no data in current buffer)
	 * 	   - set when there are unread data in the receive buffer (finished receiving)
	 */

	u8 FLAG;
	u8 DATA;
	FLAG = GET_BIT(UCSRA , 7);
	/* busy wait until UART complete Receiving data */
	while(FLAG == 0);
	  /* FLAG = 0  means there is no data received yet (buffer is empty) */
		DATA = UDR;


	return DATA;



	/* ---------------------------------------------------------------------------------------------------------------------------
	 * ||||||||||||||||||||||||||||||||||||||||||||||we can use UDRE instead of RXC ||||||||||||||||||||||||||||||||||||||||||||||
	 * ||||||||||||||||||||||||||||||||||||||||||||||while(UDRE == 1);              ||||||||||||||||||||||||||||||||||||||||||||||
	 * ||||||||||||||||||||||||||||||||||||||||||||||return UDE;                    ||||||||||||||||||||||||||||||||||||||||||||||
	 * ---------------------------------------------------------------------------------------------------------------------------
	 */


}


void UART_vSendString(u8* A_u8SrtingSend){
	u8 ITERATOR=0;
	while(A_u8SrtingSend[ITERATOR] != '\0'){

		UART_vSendChar(A_u8SrtingSend[ITERATOR]);
		ITERATOR++ ;
	}
	UART_vSendChar('\0'); /* STring Function Will stop once the '\0' reached from pointer and wont send it so we send it in this line */

}

void UART_vReceiveString(u8* A_u8SrtingReceived){
	u8 ITERATOR=0;

	A_u8SrtingReceived[ITERATOR] = UART_u8ReceiveChar();  /* first one to check that we recieve real data not empty or dummy data */

	while(A_u8SrtingReceived[ITERATOR] != '\0'){

		A_u8SrtingReceived[ITERATOR] = UART_u8ReceiveChar();
		ITERATOR++ ;

	}
	A_u8SrtingReceived[ITERATOR] = '\0' ;  /* STring Function Will stop once the '\0' reached from pointer and wont send it so we send it in this line */
}






