
#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

#define LED_State_ON  1
#define LED_State_OFF 0

#define LED0_ID  0
#define LED1_ID  1
#define LED2_ID  2
#define LED3_ID  3
#define LED4_ID  4
#define LED5_ID  5
#define LED6_ID  6
#define LED7_ID  7

void LED_vInit(u8 A_u8LedId);

void LED_vTurnOn(u8 A_u8LedId);
void LED_vTurnOff(u8 A_u8LedId);





#endif /* HAL_LED_LED_INT_H_ */
