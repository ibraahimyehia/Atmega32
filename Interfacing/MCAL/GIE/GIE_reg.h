/*
 * GIE_reg.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_GIE_GIE_REG_H_
#define MCAL_GIE_GIE_REG_H_

/* statues register defination */

#define SREG *((volatile u8*) 0x5f)
#define I 7  //Glopal Interrupt Enable
#define T 6  // Bit copy Storage
#define H 5  // HALF carry Flag
#define S 4
#define V 3
#define N 2
#define Z 1
#define C 0




#endif /* MCAL_GIE_GIE_REG_H_ */
