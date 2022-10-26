/*
 * LCD_int.h
 *
 *  Created on: Aug 22, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define ROW0_ID   0
#define ROW1_ID   1


#define COL0_ID  0
#define COL1_ID  1
#define COL2_ID  2
#define COL3_ID  3
#define COL4_ID  4
#define COL5_ID  5
#define COL6_ID  6
#define COL7_ID  7
#define COL8_ID  8
#define COL9_ID  9
#define COL10_ID  10
#define COL11_ID  11
#define COL12_ID  12
#define COL13_ID  13
#define COL14_ID  14
#define COL15_ID  15



/*  void LCD_vInit(LCD_ID); its a genral func in case there is many LCD on board in our
* case we have only one LCD /*no need for void LCD_vInit();
*/

void LCD_vInit();

void LCD_vCmd(u8 A_u8CmdId);

void LCD_Seq8Bit();

void LCD_vDispChar(u8 A_u8Ch);
void LCD_vDispStr(u8* A_u8Str);  /* array of character inrtodiced as Ptr as it on function*/
void LCD_vDispNum(u32 A_u32Num);
void LCD_vClrScreen();
void LCD_vGoToRowCol(u8 A_u8RowId , u8 A_u8ColId);


 void LCD_vSendData(u8 A_u8Data);



#endif /* HAL_LCD_LCD_INT_H_ */
