#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"
#include "dio_reg.h"

/*PORT ID*/
#define PORTA_ID	(0)
#define PORTB_ID	(1)
#define PORTC_ID	(2)
#define PORTD_ID	(3)

/*PINs ID*/
#define PIN0_ID		(0)
#define PIN1_ID		(1)
#define PIN2_ID		(2)
#define PIN3_ID		(3)
#define PIN4_ID		(4)
#define PIN5_ID		(5)
#define PIN6_ID		(6)
#define PIN7_ID		(7)

/*Data Direction*/
#define OUTPUT	(1)
#define INPUT	(0)

/*Level*/
#define HIGH	(1)
#define LOW		(0)

/*Functions Prototype*/

/*Pin direction*/
void dio_setPinDirection(u8 portId, u8 pinId, u8 direction);
/*Write logic to pin*/
void dio_writeChannel(u8 portId, u8 pinId, u8 level);
/*Toggle pin logic*/
void dio_toggleChannel(u8 portId, u8 pinId);
/*Read logic of pin*/
u8 dio_readChannel(u8 portId, u8 pinId);
/*Enable internal pull-up resistors*/
void dio_enablePullUp(u8 portId, u8 pinId);

#endif /* DIO_H_ */