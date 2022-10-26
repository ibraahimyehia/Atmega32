/*
 * UART_cfg.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_UART_UART_CFG_H_
#define HAL_UART_UART_CFG_H_

/* ---------------------REGISTER SELECT ----------------------------
 * URSEL is bit7 in both Register UCSRC - UBRRH
 * 1- URSEL is zero during a write operation,the UBRRH value will be updated.
 * 2- URSEL is one, the UCSRC setting will be updated.
 */
#define SELECT_UBRRH  0b00000000
#define SELECT_UCSRC  0b10000000


/* -----------------------USART MODE SELECT ---------------------------
 *  Bit 6 – UMSEL --> UCSRC
 * 1- 0 Asynchronous Operation
 * 2- 1 synchronous Operation
 */

#define Asynchronous 0b00000000
#define synchronous  0b01000000

#define MODE  Asynchronous

/* --------------------- PARITY MODE -------------------------------------
 * • Bit 5:4 – UPM1:0: Parity Mode  --> UCSRC
 *  1- DISABLED 	00
 *  2- RESERVED 	01
 *  3- ENABLED,EVEN 10
 *  4- ENABLED,odd  11
 */

#define DISABLED_MODE  		0b00000000
#define RESERVED_MODE     	0b00010000
#define ENABLED_EVEN_MODE   0b00100000
#define ENABLED_odd_MODE    0b00110000

#define PARITY_MODE  DISABLED_MODE



/* --------------- STOP BIT SELECT -------------------------------------
 * • Bit 3 – USBS: Stop Bit Select  --> UCSRC
 * 1- 1-BIT  0
 * 2- 2-BIT  1
 */
#define ONE_STOP_BIT  0b00000000
#define TWO_STOP_BIT  0b00001000

#define STOP_BITS_SIZE  ONE_STOP_BIT

/* -------------- DATA SIZE ---------------------------------------
 * • Bit 2:1 – UCSZ1:0:  --> UCSRC
 *  with Bit 2 -  UCSZ2 bit --> UCSRB
 *
 *     UCSZ2  UCSZ1  UCSZ0
*  1-  0      0      0      5-bit
*  2-  0      0      1      6-bit
*  3-  0      1      0      7-bit
*  4-  0      1      1      8-bit
*  5-  1      0      0      Reserved
*  6-  1      0      1      Reserved
*  7-  1      1      0      Reserved
*  8-  1      1      1      9-bit
 */

/* ######## DATA SIZE CONTROLED BY TWO REGISTER SO IT DONE BY BIT MASKING#
 * ######## IN PROGRAM.C #################################################
 */












#endif /* HAL_UART_UART_CFG_H_ */
