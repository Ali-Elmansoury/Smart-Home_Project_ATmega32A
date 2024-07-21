

#include "adc.h"
#include "bit_math.h"

void adc_init(void)
{
	/*Enable ADC*/
	SET_BIT(ADC_ADCSRA_REG,ADC_ENABLE_BIT_NO);
	
	/*ADC clock*/
	ADC_ADCSRA_REG |= ADC_PRESCALER_128;
	
	/*Select AREF*/
	ADC_ADMUX_REG |= ADC_VREF_AVCC;
}

u16 adc_read(u8 channelId)
{
	/*Select channel*/
	ADC_ADMUX_REG &= ADC_CHANNELID_CLEAR_MUSK;
	ADC_ADMUX_REG |= channelId;
	
	/*Start conversion*/
	SET_BIT(ADC_ADCSRA_REG,ADC_START_CONVERSION_BIT_NO);
	
	/*Wait until conversion finishes*/
	while (CHECK_BIT(ADC_ADCSRA_REG,ADC_INT_FLAG_BIT_NO) == 0){
		;
	}
	
	/*Clear conversion complete flag*/
	SET_BIT(ADC_ADCSRA_REG,ADC_INT_FLAG_BIT_NO);
	
	/*Return channel ADC conversion value*/
	return ADC_ADCREAD_REG;
}
