/*
* adc.c
*
* Created: 18-Oct-23 8:43:48 PM
*  Author: pc
*/
#include "std_types.h"
#include "adc_reg.h"
#include "adc.h"
#include "bit_math.h"

void adc_init(void){
	/* Enable ADC */
	SET_BIT (ADC_ADCSRA_REG, ADC_ENABLE_BIT_NO);

	/* ADC clock */
	ADC_ADCSRA_REG|= ADC_PSCALER_128;

	/* Select Aref */
	ADC_ADMUX_REG |= ADC_VREF_AVCC;
}

u16 adc_read(u8 channelID){
	/* select channel */
	ADC_ADMUX_REG &= ADC_CHANNEL_ID_CLEAR_MASK; // i want to set the select bits only to zero without changing the MSB 3 bits
	ADC_ADMUX_REG |= channelID;
	
	/* start conversion */
	SET_BIT(ADC_ADCSRA_REG, ADC_START_CONVERSION_BIT_NO);
	
	/* wait until conversion finishes */
	while(CHECK_BIT(ADC_ADCSRA_REG, ADC_INTF_BIT_NO)==0)
	{
		; /* wait */
	}
	
	/* clear conversion complete flag */
	SET_BIT(ADC_ADCSRA_REG, ADC_INTF_BIT_NO);
	
	/* return channel adc conversion value */
	return (ADC_ADCREAD_REG);
	
}

void adc_enableInterrupt(void){
	
}

void adc_disableInterrupt(void){
	
}