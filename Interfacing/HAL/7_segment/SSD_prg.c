/*
 * SSD_prg.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Ibrahim
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include "../../MCAL/DIO/DIO_int.h"

#include "SSD_pri.h"
#include "SSD_cfg.h"
#include "SSD_int.h"


/* SSD0_DATA_PORT PORTD_ID //  SSD1_DATA_PORT PORTB_ID */
/*first function to intalize ssd to be off */
void SSD_vInit(u8 A_u8SsdId){
	switch(A_u8SsdId){
	case SSD0_ID: {
		DIO_vSetPortDir(SSD0_DATA_PORT , DIR_OUTPUT);
		DIO_vSetPinDir(SSD0_EN_PORT , SSD0_EN_PIN ,DIR_OUTPUT);  // set direction for enable pins
#if (SSD_COM == COM_CATHODE)
		DIO_vSetPinVal(SSD0_EN_PORT , SSD0_EN_PIN ,VAL_HIGH); // start with off mode
#else
		DIO_vSetPinVal(SSD0_EN_PORT , SSD0_EN_PIN ,VAL_LOW);
#endif

		break;
	}


	case SSD1_ID: {
		DIO_vSetPortDir(SSD1_DATA_PORT , DIR_OUTPUT);
		DIO_vSetPinDir(SSD1_EN_PORT , SSD1_EN_PIN ,DIR_OUTPUT);
#if (SSD_COM == COM_CATHODE)
		DIO_vSetPinVal(SSD1_EN_PORT , SSD1_EN_PIN ,VAL_HIGH);
#else
		DIO_vSetPinVal(SSD1_EN_PORT , SSD1_EN_PIN ,VAL_LOW);

#endif

		break;
	}

	}
}




void SSD_vTurnOn(u8 A_u8SsdId){
	switch(A_u8SsdId){
	case SSD0_ID: {
#if (SSD_COM == COM_CATHODE)
		DIO_vSetPinVal(SSD0_EN_PORT , SSD0_EN_PIN ,VAL_LOW);
#else
		DIO_vSetPinVal(SSD0_EN_PORT , SSD0_EN_PIN ,VAL_HIGH);
#endif
		break;
	}


	case SSD1_ID: {
#if (SSD_COM == COM_CATHODE)
		DIO_vSetPinVal(SSD1_EN_PORT , SSD1_EN_PIN ,VAL_LOW);
#else
		DIO_vSetPinVal(SSD1_EN_PORT , SSD1_EN_PIN ,VAL_HIGH);
#endif

		break;
	}

	}}



void SSD_vTurnOff(u8 A_u8SsdId){

	switch(A_u8SsdId){
	case SSD0_ID: {
#if (SSD_COM == COM_CATHODE)
		DIO_vSetPinVal(SSD0_EN_PORT , SSD0_EN_PIN ,VAL_HIGH); // high for off mode
#else
		DIO_vSetPinVal(SSD0_EN_PORT , SSD0_EN_PIN ,VAL_LOW);
#endif

		break;
	}

	case SSD1_ID: {
#if (SSD_COM == COM_CATHODE)
		DIO_vSetPinVal(SSD1_EN_PORT , SSD1_EN_PIN ,VAL_HIGH);
#else
		DIO_vSetPinVal(SSD1_EN_PORT , SSD1_EN_PIN ,VAL_LOW);

#endif

		break;
	}

	}}



void SSD_vDispNum(u8 A_u8SsdId, u8 A_u8Val){

	const u8 L_u8SsdDecToSegArr[10] = {
			0b00111111,
			0b00000110,
			0b01011011,
			0b01001111,
			0b01100110,
			0b01101101,
			0b01111101,
			0b00000111,
			0b01111111,
			0b01101111
	};

	switch(A_u8SsdId){
	case SSD0_ID:
	{
#if (SSD_COM == COM_CATHODE)
		DIO_vSetPortVal(SSD0_DATA_PORT , L_u8SsdDecToSegArr[A_u8Val]);
#else
		DIO_vSetPortVal(SSD0_DATA_PORT , ~L_u8SsdDecToSegArr[A_u8Val]);
#endif
		break;

	}

	case SSD1_ID:
		{
	#if (SSD_COM == COM_CATHODE)
			DIO_vSetPortVal(SSD1_DATA_PORT , L_u8SsdDecToSegArr[A_u8Val]);
	#else
			DIO_vSetPortVal(SSD1_DATA_PORT , ~L_u8SsdDecToSegArr[A_u8Val]);
	#endif
			break;



	}
}
}

