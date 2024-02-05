/*
* ac.c
*
* Created: 2/5/2024 4:55:38 AM
*  Author: ali_e
*/

#include "ac.h"
#include "dc.h"

void airConditioner_init(void)
{
	dcMotor_init();
	LM35_init();
}

void airConditioner_status(void){
	// Sample temperature value
	u16 current_temperature = LM35_read();  // Get temp sensor reading

	// Thresholds for turning on and off the air conditioner
	u16 turn_on_threshold = 28;  // If the temperature goes above 28°C, turn on the AC
	u16 turn_off_threshold = 21;  // If the temperature goes below 21°C, turn off the AC

	// Check if the temperature is above the turn on threshold
	if (current_temperature > turn_on_threshold) {
		airConditioner_on(); // Turn on the DC motor for the air conditioner
	}

	// Check if the temperature is below the turn off threshold
	else if (current_temperature < turn_off_threshold) {
		airConditioner_off(); // Turn off the DC motor for the air conditioner
		
	}

	// If the temperature is within the desired range, do nothing
	else {
		;
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
