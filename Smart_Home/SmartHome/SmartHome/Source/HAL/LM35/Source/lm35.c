

#include "lm35.h"

void LM35_init(void)
{
	adc_init();
}

u16 LM35_read(void)
{
	u16 adcRead = 0;
	f32 volt = 0;
	u16 tempRead = 0;
	adcRead = adc_read(LM35_PIN);
	volt = (f32)(adcRead*(VOLT_PER_STEP));
	tempRead = (u16)(volt/VOLT_PER_DEG);
	return tempRead;
}
