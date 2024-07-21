#include "ac.h"
#include "dc.h"
#include "lm35.h"

AC AC_CFG;

void airConditioner_init(void)
{
	dcMotor_init();
	LM35_init();
	AC_CFG.AC_Status = TRUE;
	AC_CFG.AC_Run_Temperature_threshold=28;
	AC_CFG.AC_Stop_Temperature_threshold=21;
}

u16 airConditioner_Temperature(void)
{
	u16 current_temperature = LM35_read();  // Get temp sensor reading
	return current_temperature;
}

void airConditioner_Toggle(void)
{
	AC_CFG.AC_Status^= TRUE;
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

boolean airConditioner_State(void)
{
	return AC_CFG.AC_Status;
}

void airConditioner_service(void){
	u8 current_temperature = 0;
	switch (AC_CFG.AC_Status)
	{
	case 1:
		// Sample temperature value
		 current_temperature = LM35_read();  // Get temp sensor reading

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
