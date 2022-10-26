/*
 * WTD_prg.c

 *
 *  Created on: Sep 20, 2022
 *      Author: Ibrahim
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include"WTD_cfg.h"
#include"WTD_int.h"
#include"WTD_pri.h"
#include"WTD_reg.h"


void WTD_vEnable(){
	SET_BIT(WDTCR , 3);


}


void WTD_vDisabl(){

	/* in the same cycle WDE = 1 , WDTOFE =1 */
	WDTCR = 0b00011000;

	/* Within the next four cycle */
	WDTCR = 0b00000000;
}


void WTD_vSetSleep(u8 A_u8SleepTime){

	WDTCR &= 0b11111000;
	WDTCR |= A_u8SleepTime;
}
