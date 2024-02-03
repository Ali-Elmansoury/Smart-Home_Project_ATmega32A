/*
 * lm35.c
 *
 * Created: 25-Oct-23 6:56:41 PM
 *  Author: pc
 */ 
#include "lm35.h"

void lm35_init(void){
	adc_init();
}

u16 lm35_readTemp(void){
	u16 loc_adcRead=0;
	f32 loc_volt=0;
	loc_adcRead=adc_read(ADC1_CHANNEL);
	u16 loc_temp=0;
	loc_volt=(f32)(loc_adcRead*(5000.0/1023));
	loc_temp=(u16)(loc_volt/10);
	
	return loc_temp;
	
}