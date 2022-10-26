/*
0
 * PAD_int.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_KEY_PAD_PAD_INT_H_
#define HAL_KEY_PAD_PAD_INT_H_


#define KPD_PORT PORTD_ID

#define NO_PRESSED_KEY  20



void KPD_vInit();

u8 KPD_vGetPressedKey();

u8 sum();









#endif /* HAL_KEY_PAD_PAD_INT_H_ */
