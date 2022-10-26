/*
 * LCD_pri.h
 *
 *  Created on: Aug 22, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_LCD_LCD_PRI_H_
#define HAL_LCD_LCD_PRI_H_

					//32 16 8 4 2 1

#define CLEAR_COM    0b00000001

#define RETURN_HOME  0b00000010

#define ENTRY_MODE   0b00000110     /* shift from left to right //from data sheet// ID=1  and SH=0 */

#define DISP_OFF     0b00001000

#define DISP_ON      0b00001100    /* make cursor on and un display it and make it not blank */

#define BIT_MODE_8   0b00111000  /* 6.6 function set */

//#define CG_RAM       //0b01------;
//
//#define DD_RAM       //0b1------;



#endif /* HAL_LCD_LCD_PRI_H_ */
