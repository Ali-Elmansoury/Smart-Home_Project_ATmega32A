

#include "pot.h"

void POT_init(void)
{
	adc_init();
}

u16 POT_read(void)
{
	u16 adcRead = 0;
	adcRead = adc_read(POT_PIN);
	return adcRead;
}