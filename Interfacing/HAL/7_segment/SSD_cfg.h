/*
 * SSD_cfg.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Ibrahim
 */

#ifndef HAL_7_SEGMENT_SSD_CFG_H_
#define HAL_7_SEGMENT_SSD_CFG_H_

/*modes*/
/* COM_CATHODE - COM_ANODE */

#define SSD_COM  COM_CATHODE


/* connections */

#define SSD0_DATA_PORT PORTD_ID  // data for first led segment come from POrt D
#define SSD0_EN_PORT   PORTA_ID
#define SSD0_EN_PIN    PIN0_ID    // define pin A0 as control pin for COM

#define SSD1_DATA_PORT PORTB_ID   // data for second led segment come from POrt B
#define SSD1_EN_PORT   PORTA_ID
#define SSD1_EN_PIN    PIN1_ID     // define pin A1 as control pin for COM






#endif /* HAL_7_SEGMENT_SSD_CFG_H_ */
