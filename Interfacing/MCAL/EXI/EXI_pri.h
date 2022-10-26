/*
 * EXI_pri.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_EXI_EXI_PRI_H_
#define MCAL_EXI_EXI_PRI_H_

#define FALLING_EDGE   2   10
#define RISING_EDGE    3   11

/* number 1 for external interrupt 0 in vector table */
void __vector_1 (void) __attribute__((signal));

/* number 2 for external interrupt 0 in vector table */
void __vector_2 (void) __attribute__((signal));

/* number 1 for external interrupt 0 in vector table */
void __vector_3 (void) __attribute__((signal));








#endif /* MCAL_EXI_EXI_PRI_H_ */
