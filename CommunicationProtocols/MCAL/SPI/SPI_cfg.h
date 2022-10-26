/*
 * SPI_cfg.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Ibrahim
 */





#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

/* -----------------------------------------------------------------------------------------------------
• Full-duplex, Three-wire Synchronous Data Transfer
• Master or Slave Operation
• LSB First or MSB First Data Transfer
• Seven Programmable Bit Rates
• End of Transmission Interrupt Flag
• Write Collision Flag Protection
• Wake-up from Idle Mode
• Double Speed (CK/2) Master SPI Mode
*---------------------------------------------------------------------------------------------------------
 */

   /* Port B */

// #define SPI_DATA_DIE_REG   DDRB



#define SPI_PORT  1		   /*PORTB*/



#define SS_PIN	  4 /*PIN 4 */

#define MOSI_PIN  5  /* PIN 5 */
#define MISO_PIN  6  /* PIN 6 */

#define SCK_PIN   7









#endif /* MCAL_SPI_SPI_CFG_H_ */
