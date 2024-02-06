/*
* ac.c
*
* Created: 2/5/2024 4:55:38 AM
*  Author: ali_e
*/

#include "ac.h"
#include "dc.h"
#include "lm35.h"

static AC AC_CFG;

void airConditioner_init(void)
{
	dcMotor_init();
	LM35_init();
}

u16 airConditioner_Temperature(void)
{
	u16 current_temperature = LM35_read();  // Get temp sensor reading
	return current_temperature;
}

void airConditioner_Toggle(void)
{
	switch (AC_CFG.AC_Status)
	{
	case FALSE:
		AC_CFG.AC_Status = TRUE;
		break;
	case TRUE:
		AC_CFG.AC_Status = FALSE;
		break;
	default:
		break;
	}
}

void airConditioner_Set_Config(AC *ac_config)
{
	AC_CFG.AC_Run_Temperature_threshold = ac_config->AC_Run_Temperature_threshold;
	AC_CFG.AC_Stop_Temperature_threshold = ac_config->AC_Stop_Temperature_threshold;
}

AC airConditioner_Status(void)
{
	return AC_CFG;
}

void airConditioner_service(void){
	switch (AC_CFG.AC_Status)
	{
	case 1:
		// Sample temperature value
		u16 current_temperature = LM35_read();  // Get temp sensor reading

		// Check if the current temperature is above the turn on threshold
		if (current_temperature > AC_CFG.AC_Run_Temperature_threshold) {
			airConditioner_on(); // Turn on the DC motor for the air conditioner
		}

		// Check if the current temperature is below the turn off threshold
		else if (current_temperature < AC_CFG.AC_Stop_Temperature_threshold) {
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
