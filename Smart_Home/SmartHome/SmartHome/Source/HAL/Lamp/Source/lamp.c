/*
 * lamp.c
 *
 * Created: 2/5/2024 3:06:05 AM
 *  Author: ali_e
 */ 

#include "relay.h"
#include "lamp.h"

void lamp_init_state();

void lamp_init(void)
{
	relay_init();
}



void lamp_toggle(u8 id)
{
	switch(id)
	{
		case LAMP_DIM_ID:
			
			break;
		default:
			relay_toggle(id);
			break;
	}
}