/*
 * door.c
 *
 * Created: 2/7/2024 4:56:03 AM
 *  Author: ali_e
 */ 

#include "door.h"
#include "servo.h"

u8 doorState = DOOR_CLOSED;

void doorService_init()
{
	servo_init(PORTD_ID,PIN5_ID,OUTPUT,TIMER1_NON_INVERTED_PWM_FAST_OC1A,TIMER1_PWM_FAST_ICR,TIMER1_F_CPU_DIV_64,SERVO_TOP_VALUE_50_HZ);
}

void doorOpen()
{
	servo_setAngleDegree(SERVO_ANGLE_90_DEGREE);
	doorState = DOOR_OPENED;
}

void doorClose()
{
	servo_setAngleDegree(SERVO_ANGLE_0_DEGREE);
	doorState = DOOR_CLOSED;
}

void doorToggle()
{
	if (doorState == DOOR_CLOSED) {
		doorOpen();
		} else {
		doorClose();
	}
}

void doorService()
{
	doorToggle();
}
