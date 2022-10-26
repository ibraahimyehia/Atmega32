/*
 * SPI_int.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_


void SPI_vPortClear();

void SPI_vMaster();
void SPI_vSlave();



u8 SPI_vSend_Receive_Data(u8 A_u8Data);

void SPI_vSendChar(u8 A_u8Data);
u8 SPI_u8ReceiveChar();

void SPI_vSendString(u16 A_u16Data);
void SPI_vReceiveString();




//void SPI_vInit();
	/* mosi setup */
	/* miso setup */
	/* spi enable */
	/* set devider*/
	/*spi mode */
	/*handle ss pin*/








#endif /* MCAL_SPI_SPI_INT_H_ */
