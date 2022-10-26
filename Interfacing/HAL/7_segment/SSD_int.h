/*
 * SSD_int.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_7_SEGMENT_SSD_INT_H_
#define HAL_7_SEGMENT_SSD_INT_H_

#define SSD0_ID  0
#define SSD1_ID  1




void SSD_vInit(u8 A_u8SsdId);

void SSD_vTurnOn(u8 A_u8SsdId);

void SSD_vTurnOff(u8 A_u8SsdId);

void SSD_vDispNum(u8 A_u8SsdId, u8 A_u8Val);









#endif /* HAL_7_SEGMENT_SSD_INT_H_ */
