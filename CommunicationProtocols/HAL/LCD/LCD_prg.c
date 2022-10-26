#include<avr/delay.h>

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include"../../MCAL/DIO/DIO_int.h"


#include"LCD_int.h"

#include"LCD_cfg.h"

#include"LCD_pri.h"



void LCD_vInit(){
	DIO_vSetPortDir(LCD_DATA_PORT , DIR_OUTPUT);
	DIO_vSetPinDir(RW_ID_PORT , RW_ID_PIN , DIR_OUTPUT);
	DIO_vSetPinDir(RS_ID_PORT , RS_ID_PIN , DIR_OUTPUT);
	DIO_vSetPinDir(EN_ID_PORT , EN_ID_PIN , DIR_OUTPUT);

	LCD_Seq8Bit();

}


void LCD_vCmd(u8 A_u8CmdId){

	DIO_vSetPinVal(EN_ID_PORT , EN_ID_PIN , VAL_HIGH);
	DIO_vSetPinVal(RW_ID_PORT , RW_ID_PIN , VAL_LOW);
	DIO_vSetPinVal(RS_ID_PORT , RS_ID_PIN , VAL_LOW);


	DIO_vSetPortVal(LCD_DATA_PORT , A_u8CmdId);

	DIO_vSetPinVal(EN_ID_PORT , EN_ID_PIN , VAL_LOW);

	_delay_ms(2);
	/*
	 * by the way there is no need to switch case
	 * switch(A_u8CmdId){
	case CLEAR_COM: DIO_vSetPortVal(LCD_DATA_PORT , CLEAR_COM); break;
	case RETURN_HOME: DIO_vSetPortVal(LCD_DATA_PORT , RETURN_HOME); break;
	case ENTRY_MODE: DIO_vSetPortVal(LCD_DATA_PORT , ENTRY_MODE); break;
	case DISP_OFF: DIO_vSetPortVal(LCD_DATA_PORT , DISP_OFF); break;
	case DISP_ON: DIO_vSetPortVal(LCD_DATA_PORT , DISP_ON); break;
	case BIT_MODE_8: DIO_vSetPortVal(LCD_DATA_PORT , BIT_MODE_8); break;
	case CG_RAM: DIO_vSetPortVal(LCD_DATA_PORT , CG_RAM); break;
	case DD_RAM: DIO_vSetPortVal(LCD_DATA_PORT , DD_RAM); break;
	 */


}




void LCD_Seq8Bit(){  /* sequence on page 13 data sheet */
	//_delay_ms(30);
	LCD_vCmd(BIT_MODE_8);
	_delay_ms(1);
	LCD_vCmd(DISP_ON); //disp on
	_delay_ms(1);
	LCD_vCmd(CLEAR_COM);
	_delay_ms(2);
	LCD_vCmd(ENTRY_MODE);
	/* END OF Initialization */


}



void LCD_vDispChar(u8 A_u8Ch){   /* 6.10 WRITE DATA*/
	DIO_vSetPinVal(EN_ID_PORT , EN_ID_PIN , VAL_HIGH);

	DIO_vSetPinVal(RS_ID_PORT , RS_ID_PIN , VAL_HIGH);
	DIO_vSetPinVal(RW_ID_PORT , RW_ID_PIN , VAL_LOW);

	DIO_vSetPortVal(LCD_DATA_PORT , A_u8Ch );

	DIO_vSetPinVal(EN_ID_PORT , EN_ID_PIN , VAL_LOW);

	/* for display string by swaping effect */
	_delay_ms(6);
	DIO_vSetPinVal(EN_ID_PORT , EN_ID_PIN , VAL_HIGH);
	_delay_ms(11);
	/* ------------------------- */

}




void LCD_vDispStr(u8* A_u8Str){  /* Numay of character inrtodiced as Ptr as it on function*/
	u8 L_u8Iterator=0;
	while(A_u8Str[L_u8Iterator] != '\0'){ // not NELL so its a character
		LCD_vDispChar(A_u8Str[L_u8Iterator]);

		L_u8Iterator++;
		_delay_ms(6);

	}



}



void LCD_vClrScreen(){
	DIO_vSetPinVal(EN_ID_PORT , EN_ID_PIN , VAL_HIGH);
	DIO_vSetPinVal(RW_ID_PORT , RW_ID_PIN , VAL_LOW);
	DIO_vSetPinVal(RS_ID_PORT , RS_ID_PIN , VAL_LOW);


	DIO_vSetPortVal(LCD_DATA_PORT , CLEAR_COM);

	DIO_vSetPinVal(EN_ID_PORT , EN_ID_PIN , VAL_LOW);
	_delay_ms(2);
}


void LCD_vGoToRowCol(u8 A_u8RowId , u8 A_u8ColId){
	u8 L_Address;
	switch(A_u8RowId){
	case ROW0_ID: L_Address = 0x00 + A_u8ColId; break;
	case ROW1_ID: L_Address = 0x40 + A_u8ColId; break;
	}
	LCD_vCmd(L_Address + 128);



}



//void LCD_vDispNum(u32 A_u32Num){
//
//	u8 Num[1] , L_u32SingleNum ;
//	u8 Iterator1=0;
//	while(A_u32Num !=0){
//	L_u32SingleNum = A_u32Num % 10 ;
//
//	Num[Iterator1] =  L_u32SingleNum + 0x30;  //or 48 decimal calc from ASCII TABLE
//
//	A_u32Num = A_u32Num/10 ;
//
//	Iterator1++;
//	}
//
////     u8 temp;
////    for(u8 i = 0; i<1; i++){
////        temp = Num[i];
////        Num[i] = Num[2-i-1];
////        Num[2-i-1] = temp;
////
////}
//	LCD_vDispStr(Num);
//
//}




void LCD_vDispNum(u32 A_u32Num){
if (A_u32Num == 0){
			LCD_vDispChar('0');
}

else{
		u8 arr[10], i=0;
		for(;A_u32Num>0;i++){
			arr[i]=0x30+(A_u32Num%10);
			A_u32Num/=10;
		}
		for(;i>0;i--)
		LCD_vDispChar(arr[i-1]);

		}

	}














//void LCD_vDispNum(u32 A_u32Num){
//
//	u8 x=sizeof(A_u32Num) + 1;
//	u8 Num[x] , L_u32SingleNum ;
//	u8 Iterator1=0;
//	while(A_u32Num !=0 && x!=0){
//	L_u32SingleNum = A_u32Num % 10 ;
//
//	Num[x] =  L_u32SingleNum + 0x30;  //or 48 decimal calc from ASCII TABLE
//
//	A_u32Num = A_u32Num/10 ;
//
//	x--;
//	}


//	u32 Temp[10];
//	for(u8 Iterator2 = 10 ; Iterator2<=0; Iterator2-- ){
//		Temp[10-Iterator2] = Num[Iterator2];
//	LCD_vDispChar(Temp[x)
//
//	}
//
//
//
//}
//








