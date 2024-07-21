
#include "dimmer.h"
#include "pot.h"
#include "timer0.h"
#include "dio.h"

void dimmer_init(void)
{
	pwm0_init(TIMER0_NON_INVERTED_PWM_FAST, PWM_F_61HZ);
	POT_init();
	dio_setPinDirection(PORTB_ID,PIN3_ID,OUTPUT);
}

void dimmer_setIntensity(void)
{
	u16 potRead = 0;
	potRead = POT_read();
	potRead = (((f32)potRead/1023)*100);
	pwm0_setDutyCycle(potRead);
}

void dimmer_turnOff(void)
{
	pwm0_setDutyCycle(DIMMER_TURN_OFF);
}
