/*
 * TRAN_Init.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Ibrahim
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "TRAN_Init.h"



void Stepper_RotateCW(void)
{
	SET_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	SET_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	SET_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	SET_BIT(PORTD,Coil_Orange);
	_delay_ms(5);
}

void Stepper_RotateACW(void)
{

	CLR_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	SET_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	SET_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	SET_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	SET_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);
}