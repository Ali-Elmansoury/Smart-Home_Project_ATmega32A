
#include "dio.h"
#include "buzzer.h"

void buzzer_init(void)
{
	dio_setPinDirection(PORTB_ID,PIN2_ID,OUTPUT);
}

void buzzer_on(void)
{
	dio_writeChannel(PORTB_ID,PIN2_ID,HIGH);
}