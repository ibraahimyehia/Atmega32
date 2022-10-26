/*
 * PAD_prg.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Ibrahim
 */

#include<avr/delay.h>

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include"../../MCAL/DIO/DIO_int.h"

#include"PAD_int.h"
#include"PAD_cfg.h"
#include"PAD_pri.h"

#include"../LCD/LCD_int.h"


void KPD_vInit(){
	/* set pull up for rows */

	for(u8 Iterator1 = ROW_START; Iterator1<=ROW_END ; Iterator1++){
		DIO_vSetPinDir(KPD_PORT , Iterator1 , DIR_INPUT);
		DIO_vSetPinVal(KPD_PORT , Iterator1 , VAL_HIGH);
	}

	for(u8 Iterator2 = COL_START; Iterator2<=COL_END ; Iterator2++){
		DIO_vSetPinDir(KPD_PORT , Iterator2 , DIR_OUTPUT);
		DIO_vSetPinVal(KPD_PORT , Iterator2 , VAL_HIGH);
	}

}




u8 KPD_vGetPressedKey(){

	u32 L_u32SwitchArr[4][4] = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,00}
								};


	u8 L_u8Col , L_u8Row , 	L_u8PinVal ;
	/* intaalize switch to be not prssed */
 	u8 L_u8PressedKey = NO_PRESSED_KEY;
 	/* looping to activate COLs by seeting each col as low */
 	for(L_u8Col = COL_START ; L_u8Col<=COL_END ; L_u8Col++){
 		DIO_vSetPinVal(KPD_PORT , L_u8Col , VAL_LOW);
 		/* Loop for the Rows to check for low value row */
 		for(L_u8Row = ROW_START; L_u8Row<=ROW_END ; L_u8Row++){
 			L_u8PinVal = DIO_u8GetPinVal(KPD_PORT , L_u8Row);
 			 if(L_u8PinVal == 0){   //mean that button pressed
 				L_u8PressedKey = L_u32SwitchArr[L_u8Row - ROW_START][L_u8Col - COL_START];  // -_start to avoid that rows is bigger than array size
 				 while(L_u8PinVal == 0){
 					L_u8PinVal = DIO_u8GetPinVal(KPD_PORT , L_u8Row);
 				 }
 				 _delay_ms(20); // to avoid bouncing
 			 }

 		}



 		DIO_vSetPinVal(KPD_PORT , L_u8Col , VAL_HIGH);



 	}

//
// 	switch(L_u8PinVal){
// 	case 11:
// 		u8 FirstNum =
// 		LCD_vDispChar('+')
//
//
//
// 	}
//





	return L_u8PressedKey;
}

















