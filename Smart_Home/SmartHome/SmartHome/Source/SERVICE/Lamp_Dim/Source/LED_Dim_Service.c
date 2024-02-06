/*
 * LED_Service.c
 *
 * Created: 2/6/2024 5:56:05 PM
 *  Author: MrDark
 */ 
#include "std_types.h"
#include "timer0.h"
#include "adc.h"

boolean Dim_Service_state = TRUE;

void lamp_Dim_service_init()
{
	pwm0_init(TIMER0_INVERTED_PWM_PHASE_CORRECT,PWM_F_31_25KHZ);
	adc_init();
}

void lamp_Dim_service()
{
	u8 dim;
	switch(Dim_Service_state)
	{
		case TRUE:
			dim = adc_read(ADC7_CHANNEL);
			dim = ((f32)dim/TIMER0_TOP)*(100);
			pwm0_setDutyCycle(dim);
			break;
		default:
			break;
	}
}

void Lamp_Service_Dim_Toggle()
{
	Dim_Service_state^= TRUE;
}

boolean Lamp_Service_state()
{
	return Dim_Service_state;
}