/*
 * EXI_rreg.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Ibrahim
 */

#ifndef MCAL_EXI_EXI_RREG_H_
#define MCAL_EXI_EXI_RREG_H_



#define MCUCR *(( u8*) 0x55)
#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3
/*
 * from pin 4 to 7 is unused pins
 */


#define MCUCSR *(( u8*) 0x54)
#define ISC2  6 //BIT 6
 /*
  * rest of Bits unused and Bit 5 is reserved
  */


#define GICR *(( u8*) 0x5B)
#define INT2  5
#define INT0  6
#define INT1  7

/*
 * r3est of pins unused
 */



#define GIFR *(( u8*) 0x5A)
#define INTF2  5
#define INTF0  6
#define INTF1  7

/*
 * r3est of pins unused
 */










#endif /* MCAL_EXI_EXI_RREG_H_ */
