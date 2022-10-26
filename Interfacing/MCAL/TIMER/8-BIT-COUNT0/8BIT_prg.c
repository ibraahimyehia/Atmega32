/*
 * 8BIT_prg.c
 *
 *  Created on: Sep 13, 2022
 *      Author: Ibrahim
 */

/*---------------------------------------------------*/
/*

 * BIT_MATH.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Ibrahim
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

/*
 * WRT_BIT is to assign 1 or 0 to  a specific bit in a register
 * while maintaining all the bits' value as it is.
 * Steps:
 * 		1- Clear the specific bit you want to write on
 * 		2- Insert the new value you want to write
 */
#define WRT_BIT(REG, BIT, VAL) ( (REG) = ( ( (REG) & (~(1<<(BIT))) ) | ( (VAL) << (BIT)  ) ) )

/*
 * SET_BIT is used to assign 1 to a specific bit in a register
 * while maintaining all other bits' value as it is.
 */
#define SET_BIT(REG, BIT)  ( (REG) |=  (1<<(BIT)) )

/*
 * CLR_BIT is used to assign 0 to a specific bit in a register
 * while maintaining all other bits' value as it is.
 */
#define CLR_BIT(REG, BIT)  ( (REG) &= (~(1<<(BIT))) )

/*
 * TOG_BIT is used to flip a specific bit in a register from 0 to 1 or from 1 to 0
 * while maintaining all other bits' value as it is.
 */
#define TOG_BIT(REG, BIT)  ( (REG) ^=  (1<<(BIT)) )

/*
 * GET_BIT is used to read the value of a specific bit in a register
 * while maintaining all the bits' value as it is.
 */
#define GET_BIT(REG, BIT)  ( ( (REG) >> (BIT) ) & 1 )



#endif /* LIB_BIT_MATH_H_ */


/* -------------------------------------------------------------------------------------------------*/

/*
 * STD_TYPES.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Ibrahim
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_


/*
 * Signed Data Types
 */
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;

/*
 * Unsigned Data Types
 */
typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;

/*
 * Floating point Types
 */
typedef float                   f32;
typedef double                  f64;

/*
 * Address NULL
 */
#define ADDRESS_NULL ( (void *) 0x00)




typedef void (*Ptr_func_IvOv_t)(void);



#endif /* LIB_STD_TYPES_H_ */
 /* ----------------------------------------------------------------------------------------*/














/* 1- Time defination
 *  Tic Time = 1 / Frequ(Timer)
 *  Frequ(Timer) = Freq(cpu) / Prescaler
 *  so Tic Time = Prescaler / Freq(cpu)
 *
 *  2- OverFlow Time = Tic Time * 2^Reseluotin
 *   Reseluotin = NO.Bits = 8
 *   so OverFlow Time = Tic Time * 256
 *
 *  3- No.Ticks Until OverFlow = 2^Reseluotin
 *
 * |--------------------------------------------------------------------------|
 * |----------------- REMEMBER THAT FRAQUENCY = 1 / TIME----------------------|
 * |--------------------------------------------------------------------------|
 *
 *
 * to make function like delay we need to detrmine the required time
 * three cases
 * 1-required time = Time Overflow (assume its equal 256)
 * no need for Preload
 *
 * 2-required time > Time Overflow
 *
 * if required time = 1280
 * and tic time = 1sec
 * so time overflow = 1sec * 256 = 256 sec
 * so CounterOverflow (Cov) =  required time /  time overflow = 1280 / 256 = 5
 * and start load from 0
 *|------------------------------------------------------------------------------------------------------|
 *|----------------------------ISR(ovf)------------------------------------------------------------------|
 *|----------------------------static count=0; ----------------------------------------------------------|
 *|----------------------------count++; -----------------------------------------------------------------|
 *|----------------------------if(count==5){ ------------------------------------------------------------|
 *|----------------------------Toggle_Led();-------------------------------------------------------------|
 *|----------------------------count=0; } ---------------------------------------------------------------|
 *|------------------------------------------------------------------------------------------------------|
 *
 *  * --- assume Required time = 614.4 sec so --> Cov = 2.4
 *   No.Ticks Until OverFlow = 2^Reseluotin = 256
 *   No.Overflow almost equal 3
 *   preload = (3-2.4) * 256 = 153.6 sec  so we will begin count time of over folw from 153.6
 *   ----------------OR---------------------
 *   preload = 2^resolution * (1 - fraction Number of Cov)
 *   preload = 256 *( 1 - 0.4 ) = 153.6
 *
 *
 *
 * 3-required time < Time Overflow
 *
 * same as before
 *
 *
 */



//
//#include"../../LIB/STD_TYPES.h"
//#include"../../LIB/BIT_MATH.h"

#include"8BIT_reg.h"
#include"8BIT_pri.h"
#include"8BIT_int.h"
#include"8BIT_cfg.h"
#include"../../../HAL/LED/LED_int.h"


static void (*GLB_PTRF_TIMER0)(void) = ADDRESS_NULL ;



/* timer initialization:
 * 1-Enable Timer
 * 2-Prescaler and this must be the lsat function to make system start count at the end of INITIALLIzaTION
 * 3-Timer Mode
 * 4-Set OC0 Pin State    disconected - set - clear - toggle
 */


/* #######################################################################################################################################
 * #################Init could be sample than that using single option sbut we supported it with all options ############################
 * ################3##################################################################################################################*/
void TIMER0_vInit(){
	/* ----------------------------------------------Set Timer Mode ---BIT 3,6 ------------------------------------------------------- */

#if TIMER0_MODE ==   OVF_MODE
		WRT_BIT(TCCR0 , 3 , VAL_LOW);
		WRT_BIT(TCCR0 , 6 , VAL_LOW);

	/*-----------------------------------------------------------*/
#elif TIMER0_MODE == CTC_MODE
		/* Set Pin Mode*/
		WRT_BIT(TCCR0 , 3 , VAL_HIGH);
		WRT_BIT(TCCR0 , 6 , VAL_LOW);


		#if TIMER0_PIN_MODE  == OC0_DISCONECTED
	/* TODO */
		WRT_BIT(TCCR0 , 4 , VAL_LOW);
		WRT_BIT(TCCR0 , 5 , VAL_LOW);



		#elif TIMER0_PIN_MODE ==  OC0_TOGGLE
	/* TODO */
		WRT_BIT(TCCR0 , 4 , VAL_HIGH);
		WRT_BIT(TCCR0 , 5 , VAL_LOW);



		#elif TIMER0_PIN_MODE ==  OC0_CLEAR
	/* TODO */
		WRT_BIT(TCCR0 , 4 , VAL_LOW);
		WRT_BIT(TCCR0 , 5 , VAL_HIGH);


		#elif TIMER0_PIN_MODE  == OC0_SET
	/* TODO */
		WRT_BIT(TCCR0 , 4 , VAL_HIGH);
		WRT_BIT(TCCR0 , 5 , VAL_HIGH);

		#endif
/*-------------------------#########################################################################----------------------------------*/


#elif TIMER0_MODE == FAST_PWM
		WRT_BIT(TCCR0 , 3 , VAL_HIGH);
		WRT_BIT(TCCR0 , 6 , VAL_HIGH);

		#if TIMER0_PMW_MODE  ==   PWM_NON_INVERTING
	/* TODO 1 0 CLEAR OC0 on compare match, set OC0 at TOP */
//		OCR0 = 0x00;
		WRT_BIT(TCCR0 , 4 , VAL_LOW);
		WRT_BIT(TCCR0 , 5 , VAL_HIGH);

		#elif TIMER0_PMW_MODE  == PWM_INVERTING
	/* TODO 1 1 SET OC0 on compare match, clear OC0 at TOP*/
//		OCR0 = 0xFF;
		WRT_BIT(TCCR0 , 4 , VAL_HIGH);
		WRT_BIT(TCCR0 , 5 , VAL_HIGH);


		#endif
/*----------------------------------------------*/



#elif TIMER0_MODE == PHASE_CORRECT_PWM

		WRT_BIT(TCCR0 , 3 , VAL_LOW);
		WRT_BIT(TCCR0 , 6 , VAL_HIGH);
		/* in non-inverting Compare Output mode, the Output Compare (OC0)
		is cleared on the compare match between TCNT0 and OCR0 while upcounting, and set
		on the compare match while downcounting. */

	#if TIMER0_PMW_MODE ==  PWM_NON_INVERTING
		/* 1 0 Clear OC0 on compare match when up-counting. Set OC0 on compare
		match when downcounting.*/
	/* TODO */
		WRT_BIT(TCCR0 , 4 , VAL_LOW);
		WRT_BIT(TCCR0 , 5 , VAL_HIGH);

	#elif TIMER0_PMW_MODE  == PWM_INVERTING
		/* Inverting of the operation */
	/* TODO */
		WRT_BIT(TCCR0 , 4 , VAL_HIGH);
		WRT_BIT(TCCR0 , 5 , VAL_HIGH);
	#endif
/*----------------------------------------------*/


#else
#warning "Invalid Time Mode Option ..."
#endif


	/* ----------------------------------------------Enable Interrupt------------------------------------------------------- */




//WRT_BIT(TIMSK , 0 , VAL_HIGH); /* ENABLE Overflow Interrupt (OVF)--> Normal Mode */
//
//WRT_BIT(TIMSK , 1 , VAL_HIGH); /* ENABLE Output Compare Match Interrupt  (CTC) */






	/* ----------------------------------------------set prescaler ------------------------------------------------------- */




#if TIMER0_SET_PRESCALER  ==   TIMER0_NO_PRESCALER
		WRT_BIT(TCCR0 , 0 , VAL_HIGH);
		WRT_BIT(TCCR0 , 1 , VAL_LOW);
		WRT_BIT(TCCR0 , 2 , VAL_LOW);

		/* BIT MAsking More ACCurate  TCCR0 = 0b11111000; --> 0xF8   to clear the 3 bits
		 * TCCR0 |= TIMER0_SET_PRESCALER
		 * and thats it :)
		 */




#elif TIMER0_SET_PRESCALER  == TIMER0_8_PRESCALER
		WRT_BIT(TCCR0 , 0 , VAL_LOW);
		WRT_BIT(TCCR0 , 1 , VAL_HIGH);
		WRT_BIT(TCCR0 , 2 , VAL_LOW);


#elif TIMER0_SET_PRESCALER ==  TIMER0_64_PRESCALER
		WRT_BIT(TCCR0 , 0 , VAL_HIGH);
		WRT_BIT(TCCR0 , 1 , VAL_HIGH);
		WRT_BIT(TCCR0 , 2 , VAL_LOW);


#elif TIMER0_SET_PRESCALER ==  TIMER0_256_PRESCALER
		WRT_BIT(TCCR0 , 0 , VAL_LOW);
		WRT_BIT(TCCR0 , 1 , VAL_LOW);
		WRT_BIT(TCCR0 , 2 , VAL_HIGH);


#elif TIMER0_SET_PRESCALER  == TIMER0_1024_PRESCALER
		WRT_BIT(TCCR0 , 0 , VAL_HIGH);
		WRT_BIT(TCCR0 , 1 , VAL_LOW);
		WRT_BIT(TCCR0 , 2 , VAL_HIGH);


#elif TIMER0_SET_PRESCALER ==  TIMER0_EXTERNAL_CLC_FALLING_EDGE
		WRT_BIT(TCCR0 , 0 , VAL_LOW);
		WRT_BIT(TCCR0 , 1 , VAL_HIGH);
		WRT_BIT(TCCR0 , 2 , VAL_HIGH);


#elif TIMER0_SET_PRESCALER ==  TIMER0_EXTERNAL_CLC_RAISING_EDGE
		WRT_BIT(TCCR0 , 0 , VAL_HIGH);
		WRT_BIT(TCCR0 , 1 , VAL_HIGH);
		WRT_BIT(TCCR0 , 2 , VAL_HIGH);


		#endif



}




void TIMER0_vStop(){

	/*  BIT 0,1,2 -->  0 0 0 No clock source (Timer/Counter stopped)*/
	WRT_BIT(TCCR0 , 0 , VAL_LOW);
	WRT_BIT(TCCR0 , 1 , VAL_LOW);
	WRT_BIT(TCCR0 , 2 , VAL_LOW);
}





/* Set Preload to Satart Count From The Preload Value */
void TIME0_vSetPreload(u8 A_u8PreloadVal){

	TCNT0 = A_u8PreloadVal;

}


/* Set OCR Value to be the TOP counts to generate CTC Flag */
void TIME0_vSetOcrVal(u8 A_u8OcrVal){

	OCR0 = A_u8OcrVal;

}


/* Set Call back to Execute The ISR(interrupt service Routine) related with OVF Event */
void TIMER0_vCallBackOvf(void(*Fptr)(void)){

	GLB_PTRF_TIMER0 = Fptr;


}


/* Set Call back to Execute The ISR(interrupt service Routine) related with CTC Event */
void TIMER0_vCallBackCtc(void(*Fptr)(void)){

	GLB_PTRF_TIMER0 = Fptr;

}



/* ISR FOr CTC Event */
void __vector_10(void)   __attribute__((signal));
void __vector_10(void){

	/* Execute the ISR [User Routine] */
	GLB_PTRF_TIMER0();

}


/* ISR FOr OVF Event */
void __vector_11(void)   __attribute__((signal));
void __vector_11(void){

	/* Execute the ISR [User Routine] */
//	LED_vInit(LED0_ID);
//		LED_vTurnOn(LED0_ID);

	GLB_PTRF_TIMER0();


}









