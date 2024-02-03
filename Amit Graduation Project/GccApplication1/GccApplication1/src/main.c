/*
 * GccApplication1.c
 *
 * Created: 02-Feb-24 8:16:38 PM
 * Author : pc
 */ 

#include <avr/io.h>
#include "std_types.h"
#include "dio.h"
#include "lm35.h"
#include "l293d.h"

void airConditioner(void);

int main(void)
{
	lm35_init();
	l293d_init();


    while (1) 
    {
    }
}



void airConditioner(void){
	// Sample temperature value
	u16 current_temperature = lm35_readTemp();  // Get temp sensor reading

	// Thresholds for turning on and off the air conditioner
	u16 turn_on_threshold = 28;  // If the temperature goes above 28°C, turn on the AC
	u16 turn_off_threshold = 21;  // If the temperature goes below 21°C, turn off the AC

	// Check if the temperature is above the turn on threshold
	if (current_temperature > turn_on_threshold) {
		// Run the DC motor for the air conditioner
		// Code to activate DC motor goes here
	}

	// Check if the temperature is below the turn off threshold
	else if (current_temperature < turn_off_threshold) {
		// Turn off the DC motor for the air conditioner
		// Code to deactivate DC motor goes here
	}

	// If the temperature is within the desired range, do nothing
	else {
		;
	}

}