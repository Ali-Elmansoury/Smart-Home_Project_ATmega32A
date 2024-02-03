/*
 * dio.h
 *
 * Created: 27-Sep-23 7:15:54 PM
 *  Author: pc
 */ 
#include "std_types.h"

#ifndef DIO_H_
#define DIO_H_
#include "dio_reg.h"

#define OUTPUT (1)
#define INPUT (0)

#define PORTA_ID (0)
#define PORTB_ID (1)
#define PORTC_ID (2)
#define PORTD_ID (3)

#define PIN0_ID (0)
#define PIN1_ID (1)
#define PIN2_ID (2)
#define PIN3_ID (3)
#define PIN4_ID (4)
#define PIN5_ID (5)
#define PIN6_ID (6)
#define PIN7_ID (7)

#define HIGH (1)
#define LOW (0)

//pin direction
void dio_setPinDirection(u8 portId, u8 pinId, u8 direction);
void dio_writeChannel(u8 portId, u8 pinId, u8 level);
u8 dio_readChannel(u8 portId, u8 pinId);
void dio_flipChannel(u8 portId, u8 pinId);
void dio_enablePullUp(u8 portId, u8 pinId);



#endif /* DIO_H_ */