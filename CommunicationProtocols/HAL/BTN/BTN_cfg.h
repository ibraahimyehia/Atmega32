/*
 * BTN_cfg.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_BTN_BTN_CFG_H_
#define HAL_BTN_BTN_CFG_H_
// Abstract about connection
// same as LEDs

#define BTN0_PORT PORTD_ID  // different port*/
#define BTN0_PIN  PIN0_ID

#define BTN1_PORT PORTD_ID  /*different port*/
#define BTN1_PIN  PIN1_ID

#define BTN2_PORT PORTA_ID
#define BTN2_PIN  PIN2_ID

#define BTN3_PORT PORTA_ID
#define BTN3_PIN  PIN3_ID

#define BTN4_PORT PORTA_ID
#define BTN4_PIN  PIN4_ID

#define BTN5_PORT PORTA_ID
#define BTN5_PIN  PIN5_ID

#define BTN6_PORT PORTA_ID
#define BTN6_PIN  PIN6_ID

#define BTN7_PORT PORTA_ID
#define BTN7_PIN  PIN7_ID


// this options for BTN_PULLING configurayion parameter is // INTERNAL_PULLUP - EXTERNAL_PULLUP //
#define BTN_PUllING  INTERNAL_PULLUP  // pull up or pull down its spacific for button so it will be private




#endif /* HAL_BTN_BTN_CFG_H_ */
