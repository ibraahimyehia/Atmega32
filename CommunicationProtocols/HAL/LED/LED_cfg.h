/*
 * LED_cfg.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_LED_LED_CFG_H_
#define HAL_LED_LED_CFG_H_
/*   "method 1"
#define LED_PORT PORTD_ID

#define LED0_PIN PIN0_ID
#define LED1_PIN PIN1_ID
#define LED2_PIN PIN2_ID
#define LED3_PIN PIN3_ID
#define LED4_PIN PIN4_ID
#define LED5_PIN PIN5_ID
#define LED6_PIN PIN6_ID
#define LED7_PIN PIN7_ID

/* this led_port is defined to port ID wich defined previous in DIO int and was equal 0 when we need to change port to another (B ,C ,D)
 * and this methode dosent let you connect leds with any port it let u connect it with one port u defined and can be changeable*/

/* "method 2" */

#define LED0_PORT PORTA_ID
#define LED0_PIN PIN0_ID

#define LED1_PORT PORTA_ID
#define LED1_PIN PIN1_ID

#define LED2_PORT PORTA_ID
#define LED2_PIN PIN2_ID

#define LED3_PORT PORTA_ID
#define LED3_PIN PIN3_ID

#define LED4_PORT PORTA_ID
#define LED4_PIN PIN4_ID

#define LED5_PORT PORTA_ID
#define LED5_PIN PIN5_ID

#define LED6_PORT PORTA_ID
#define LED6_PIN PIN6_ID

#define LED7_PORT PORTA_ID
#define LED7_PIN PIN7_ID


#endif /* HAL_LED_LED_CFG_H_ */
