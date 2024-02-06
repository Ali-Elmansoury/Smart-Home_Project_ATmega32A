/*
* ac.c
*
* Created: 2/5/2024 4:55:38 AM
*  Author: ali_e
*/

#include "ac.h"
#include "dc.h"

static AC ac;
void airConditioner_init(void)
{
	dcMotor_init();
	LM35_init();
}

u8 airConditioner_Temperature(void)
{
	u8 current_temperature = LM35_read();  // Get temp sensor reading
	return current_temperature;
}

void airConditioner_Toggle(void)
{
	switch (ac_on)
	{
	case false:
		ac_on = true;
		break;
	case true:
		ac_on = false;
		break;
	default:
		break;
	}
}

void airConditioner_Set_Config(AC *ac_config)
{
	ac.AC_Run_Temperature_threshold = ac_config->AC_Run_Temperature_threshold;
	ac.AC_Stop_Temperature_threshold = ac_config->AC_Stop_Temperature_threshold;
}

AC airConditioner_Status(void)
{
	return ac;
}

void airConditioner_service(void){
	switch (ac_on)
	{
	case /* constant-expression */:
		/* code */
		break;
	case 1:
		// Sample temperature value
		u8 current_temperature = LM35_read();  // Get temp sensor reading

		// Check if the current temperature is above the turn on threshold
		if (current_temperature > ac.AC_Run_Temperature_threshold) {
			airConditioner_on(); // Turn on the DC motor for the air conditioner
		}

		// Check if the current temperature is below the turn off threshold
		else if (current_temperature < ac.AC_Stop_Temperature_threshold) {
			airConditioner_off(); // Turn off the DC motor for the air conditioner
		}

		// If the temperature is within the desired range, do nothing
		else {
			// Do nothing
		};
		break;
	case 0:
		airConditioner_off(); // Turn off the DC motor for the air conditioner
		break;
	default:
		break;
	}

}
void airConditioner_on(void)
{
	dcMotor_on();
}

void airConditioner_off(void)
{
	dcMotor_off();
}
