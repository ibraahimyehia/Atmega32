/*
 * GIE_prg.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Ibrahim
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include"GIE_int.h"
#include"GIE_reg.h"



void GIE_vEnable(void){
	SET_BIT(SREG , I);


}

void GIE_vDisaple(void){

	CLR_BIT(SREG , I);


}


