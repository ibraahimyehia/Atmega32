/*
 * UART_reg.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_UART_UART_REG_H_
#define HAL_UART_UART_REG_H_

#define UDR *((volatile u8*)   0x2C )

#define UCSRA *((volatile u8*) 0x2B )

#define UCSRB *((volatile u8*) 0x2A )

#define UBRRL *((volatile u8*) 0x29 )


#define UCSRC *((volatile u8*) 0x40 )
#define UBRRH *((volatile u8*) 0x40 )

/*The UCSRC Register shares the same I/O location as the UBRRH Register
 * When doing a write access of this I/O location, the high bit of the value written, the
USART Register Select (URSEL) bit, controls which one of the two registers that will be
written. If URSEL is zero during a write operation, the UBRRH value will be updated. If
URSEL is one, the UCSRC setting will be updated.

########################################################################################################################
//Set UBRRH to 2
//UBRRH = 0x02;
//...
//// Set the USBS and the UCSZ1 bit to one, and
//// the remaining bits to zero.
//UCSRC = (1<<URSEL)|(1<<USBS)|(1<<UCSZ1);
*/





#endif /* HAL_UART_UART_REG_H_ */
