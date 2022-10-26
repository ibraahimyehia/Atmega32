/*
 * 8BIT_reg.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_TIMER_8_BIT_COUNT0_8BIT_REG_H_
#define MCAL_TIMER_8_BIT_COUNT0_8BIT_REG_H_





#define TCCR0  *( (volatile u8* ) (0x53))
#define TCNT0  *( (volatile u8* ) (0x52))
#define OCR0   *( (volatile u8* ) (0x5C))
#define TIMSK  *( (volatile u8* ) (0x59))
#define TIFR   *( (volatile u8* ) (0x58))






#endif /* MCAL_TIMER_8_BIT_COUNT0_8BIT_REG_H_ */
