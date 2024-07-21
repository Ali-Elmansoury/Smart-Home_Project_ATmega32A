

#include "l293d.h"
#include "dio.h"
#include "timer0.h"

void L293D_init(void)
{
	/*Set each motor direction*/
	dio_setPinDirection(PORTB_ID,PIN3_ID,OUTPUT); //EN1-PWM TIMER0
	dio_setPinDirection(PORTD_ID,PIN7_ID,OUTPUT); //EN2-PWM TIMER2
	
	dio_setPinDirection(PORTC_ID,PIN3_ID,OUTPUT);
	dio_setPinDirection(PORTC_ID,PIN4_ID,OUTPUT);
	dio_setPinDirection(PORTC_ID,PIN5_ID,OUTPUT);
	dio_setPinDirection(PORTC_ID,PIN6_ID,OUTPUT);
	
	pwm0_init(TIMER0_NON_INVERTED_PWM_FAST, PWM_F_62_5KHZ);
}

void L293D_setDirection(u8 direcion, u8 motorId)
{
	switch(motorId)
	{
		case MOTOR_A_ID:
			if (direcion == CW_DIR)
			{
				dio_writeChannel(PORTC_ID,PIN3_ID,HIGH);
				dio_writeChannel(PORTC_ID,PIN4_ID,LOW);
			}
			else if (direcion == CCW_DIR)
			{
				dio_writeChannel(PORTC_ID,PIN3_ID,LOW);
				dio_writeChannel(PORTC_ID,PIN4_ID,HIGH);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		
		case MOTOR_B_ID:
			if (direcion == CW_DIR)
			{
				dio_writeChannel(PORTC_ID,PIN5_ID,HIGH);
				dio_writeChannel(PORTC_ID,PIN6_ID,LOW);
			}
			else if (direcion == CCW_DIR)
			{
				dio_writeChannel(PORTC_ID,PIN5_ID,LOW);
				dio_writeChannel(PORTC_ID,PIN6_ID,HIGH);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
	}
}

void L293D_setSpeed(u8 speed, u8 motorId)
{
	switch(motorId)
	{
		case MOTOR_A_ID:
			pwm0_setDutyCycle(speed);
		break;
		
		case MOTOR_B_ID:
			//pwm2_setDutyCycle(speed);
		break;
	}
}