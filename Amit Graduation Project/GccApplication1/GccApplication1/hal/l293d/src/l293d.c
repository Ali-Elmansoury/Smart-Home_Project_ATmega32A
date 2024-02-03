/*
* l293d.c
*
* Created: 01-Nov-23 7:07:19 PM
*  Author: pc
*/
#include "l293d.h"
#include "dio.h"
#include "std_types.h"
#include "timer0.h"
void l293d_init(void){
	/* set each motor pins output */
	dio_setPinDirection(PORTD_ID, PIN4_ID, OUTPUT);
	dio_setPinDirection(PORTD_ID, PIN5_ID, OUTPUT);
	dio_setPinDirection(PORTC_ID, PIN3_ID, OUTPUT);
	dio_setPinDirection(PORTC_ID, PIN4_ID, OUTPUT);
	dio_setPinDirection(PORTC_ID, PIN5_ID, OUTPUT);
	dio_setPinDirection(PORTC_ID, PIN6_ID, OUTPUT);
	
	pwm0_init(TIMER0_NON_INVERTED_PWM_FAST, PWM_F_62_5KHZ);
}

void l293d_setDirection(u8 dir, u8 motorId){
	switch(motorId){
		case MOTOR_A_ID:
		if(dir==CW_DIR){
			dio_writeChannel(PORTC_ID, PIN3_ID, LOW);
			dio_writeChannel(PORTC_ID, PIN4_ID, HIGH);
		}
		else if(dir==CCW_DIR){
			dio_writeChannel(PORTC_ID, PIN3_ID, HIGH);
			dio_writeChannel(PORTC_ID, PIN4_ID, LOW);
		}
		else {
			/* return error */
			
		}
		break;
		
		case MOTOR_B_ID:
		
		if(dir==CW_DIR) {
			dio_writeChannel(PORTC_ID, PIN5_ID, LOW);
			dio_writeChannel(PORTC_ID, PIN6_ID, HIGH);
		}
		else if(dir==CCW_DIR){
			dio_writeChannel(PORTC_ID, PIN5_ID, HIGH);
			dio_writeChannel(PORTC_ID, PIN6_ID, LOW);
		}
		else {
			/* return error */
		}
		break;
		
	}
}

void l293d_setSpeed(u8 speed, u8 motorId){
	switch(motorId){
		case MOTOR_A_ID:
		pwm0_setDutyCycle(speed);
		break;
		case MOTOR_B_ID:
		pwm0_setDutyCycle(speed);
		break;
	}
}