

#include "door.h"
#include "servo.h"
#include "uart.h"

//u8 doorState = DOOR_CLOSED;

//Global Variables
boolean get_Choice = TRUE,
		Display_door_menu = TRUE;
	

void doorService_init()
{
	servo_init(PORTD_ID,PIN5_ID,OUTPUT,TIMER1_NON_INVERTED_PWM_FAST_OC1A,TIMER1_PWM_FAST_ICR,TIMER1_F_CPU_DIV_64,SERVO_TOP_VALUE_50_HZ);
}

void doorOpen()
{
	servo_setAngleDegree(1900);
	//doorState = DOOR_OPENED;
}

void doorClose()
{
	servo_setAngleDegree(950);
	//doorState = DOOR_CLOSED;
}

// void doorToggle()
// {
// 	if (doorState == DOOR_CLOSED) {
// 		doorOpen();
// 		} else {
// 		doorClose();
// 	}
// }

void doorService()
{
	static u8 choice;
	if (Display_door_menu)
	{
		uart_sendString("\nPress 'o' to open the door, 'c' to close the door, 'b' to go back: \n");
		Display_door_menu = FALSE;
	}
	if (get_Choice)
	{
		choice = uart_receiveByte();
	}
	if (choice != 255)
	{
		get_Choice = FALSE;
		switch (choice) {
			case 'o':
			doorOpen();
			get_Choice = TRUE;
			break;
			case 'c':
			doorClose();
			get_Choice = TRUE;
			break;
			case 'b':
			return;
			default:
			uart_sendString("Invalid choice.\n");
			get_Choice = TRUE;
			break;
		}
	}
}
