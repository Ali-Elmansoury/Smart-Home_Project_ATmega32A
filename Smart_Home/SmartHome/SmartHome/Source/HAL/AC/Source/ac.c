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
}

void airConditioner_on(void)
{
	dcMotor_on();
}

void airConditioner_off(void)
{
	dcMotor_off();
}
