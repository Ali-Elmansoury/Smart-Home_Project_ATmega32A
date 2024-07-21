

#include "servo.h"

void servo_init(u8 portId, u8 pinId, u8 direction, u8 modeA, u8 modeB, u8 freq, u16 topValue)
{
	dio_setPinDirection(portId,pinId,direction);
	pwm1_setTopValue(topValue);
	pwm1_init(modeA, modeB, freq);
}

void servo_setAngleDegree(u16 degree)
{
	pwm1_setDutyCycle(degree);
}
