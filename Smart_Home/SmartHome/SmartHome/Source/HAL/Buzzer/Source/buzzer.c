/*
 * buzzer.c
 *
 * Created: 9/28/2023 5:15:47 PM
 *  Author: ali_e
 */ 

#include "dio.h"
#include "buzzer.h"

void buzzer_init(void)
{
	dio_setPinDirection(PORTC_ID,PIN7_ID,OUTPUT);
}

void buzzer_on(void)
{
	dio_writeChannel(PORTC_ID,PIN7_ID,HIGH);
}

void buzzer_off(void)
{
	dio_writeChannel(PORTC_ID,PIN7_ID,LOW);
}