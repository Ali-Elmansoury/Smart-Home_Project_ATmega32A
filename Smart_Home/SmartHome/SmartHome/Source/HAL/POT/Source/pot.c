/*
 * pot.c
 *
 * Created: 2/5/2024 4:18:05 AM
 *  Author: ali_e
 */ 

#include "pot.h"

void POT_init(void)
{
	adc_init();
}

u16 POT_read(void)
{
	u16 adcRead = 0;
	f32 volt = 0;
	adcRead = adc_read(POT_PIN);
	volt = (f32)(adcRead*(VOLT_PER_STEP));
	return volt;
}