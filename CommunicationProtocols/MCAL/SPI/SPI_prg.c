/*
 * SPI_prg.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Ibrahim
 */


/* The SPI Master initiates the communication cycle when pulling low(configure as input and high) the Slave Select SS pin of the
desired Slave. Master and Slave prepare the data to be sent in their respective Shift Registers, and the Master generates the required clock pulses on the SCK line to interchange data. Data is always shifted from Master to Slave on the Master Out – Slave In,
MOSI, line, and from Slave to Master on the Master In – Slave Out, MISO, line. After
each data packet, the Master will synchronize the Slave by pulling high(configure as output and high) the Slave Select,SS, line.*/


/*------------------SPI Slave mode --------------------------------
 *  1- (SS) pin is always input
	2- SPI is activated when SS is held low
	3- MISO becomes an output
	####### IF SS is driven high means that it will not receive incoming data. Note that the SPI##############
	####### logic will be reset once the SS pin is driven high.###############################################
	*/

/*------------------SPI Master mode --------------------------------
 	 1- (MSTR in SPCR is set)
 	 2- SS is configured as an output
	############### If SS is configured as an input, it must be held high to ensure Master SPI operation #####
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"


#include"SPI_reg.h"
#include"SPI_cfg.h"
#include"SPI_int.h"
#include"SPI_pri.h"

#include"../DIO/DIO_int.h"
#include"../DIO/DIO_reg.h"


//void SPI_vPortClear(){
//	/* make DDRB all pins input =0b0000000 */
//	DIO_vSetPortDir(SPI_PORT , DIR_INPUT);
//
//	/* Clear PORTB */
//	DIO_vSetPortVal(SPI_PORT , VAL_LOW);
//
//	/* Clear SPCR Register */
//	SPCR = 0x00;
//}


void SPI_vMaster(){

		/* make DDRB all pins input =0b0000000 */
		DIO_vSetPortDir(SPI_PORT , DIR_INPUT);


	/* enable MOSI PIN , SCK pin to be output in the same cycle*/
	DDRB =SET_BIT(DDRB , MOSI_PIN) | SET_BIT(DDRB , SCK_PIN);

	/*------------- --> SPCR <-- --------------------
	 * Bit 6 – SPE: SPI Enable   (SET)
	 * Bit 4 – MSTR: Master/Slave Select   (SET)
	 * Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select Fosc/8
	 *
	 * • Bit 5 – DORD: Data Order written to zero, the MSB of the data word is transmitted first and this the deafult value
	 */
	SPCR = SET_BIT(SPCR,6) | SET_BIT(SPCR,4) | SET_BIT(SPCR,0);




	/* Choose Clock Polarity to init with thero and Phase of Setup mode (rising edge is the leading)
	 * And it Set by deafult to zeros CPOL=0  CPHA=0  */
}


void SPI_vSlave(){

	/* make DDRB all pins input */
	DIO_vSetPortDir(SPI_PORT , DIR_INPUT);

	/* enable MISO Pin to be output */
	SET_BIT(DDRB , MISO_PIN);

	/*------------- --> SPCR <-- --------------------
	 * Bit 6 – SPE: SPI Enable   (SET)
	 * Bit 4 – MSTR: Master/Slave Select   (CLEAR) */
	SPCR = CLR_BIT(SPCR , 4);
	SPCR = SET_BIT(SPCR , 6);

}

u8 SPI_vSend_Receive_Data(u8 A_u8Data){

	SPDR = A_u8Data;
	/* Busy Wait*/

	u8 FLAG = GET_BIT(SPSR , 7 ); /* SPIF BIT 7 */
	/*  serial transfer is complete, the SPIF Flag is set */
	while(FLAG==0); /* DAta Sent Completely */
	/*now Receive Data ftom Slave */
	return SPDR;
}






void SPI_vMasterSend(u8 A_u8Data){
	 /* SPDR DATA Register  */
	SPDR = A_u8Data;

	/* Busy Wait*/
	u8 Flag = GET_BIT(SPSR , 7);
	while(Flag == 0);
	/* Wait until Flag is Set To ONE */

}


u8 SPI_u8SlaveReceive(){
	
	u8 Flag = GET_BIT(SPSR , 7);
	while(Flag == 0);
	return SPDR;
	
}


















