

#include "dc.h"
#include "dio.h"

void dcMotor_init(void)
{
	dio_setPinDirection(PORTA_ID,PIN6_ID,OUTPUT);
}

void dcMotor_on(void)
{
	dio_writeChannel(PORTA_ID,PIN6_ID,HIGH);
}

void dcMotor_off(void)
{
	dio_writeChannel(PORTA_ID,PIN6_ID,LOW);
}
