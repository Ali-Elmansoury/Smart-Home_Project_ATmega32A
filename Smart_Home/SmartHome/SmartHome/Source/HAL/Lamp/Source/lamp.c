/*
 * lamp.c
 *
 * Created: 2/5/2024 3:06:05 AM
 *  Author: ali_e
 */ 

#include "relay.h"
#include "lamp.h"

void lamp_init(void)
{
	relay_init();
}

void lamp_on(u8 id)
{
	switch(id)
	{
		case LAMP1_ID:
			relay_on(RELAY1_ID);
		break;
		
		case LAMP2_ID:
			relay_on(RELAY2_ID);
		break;
		
		case LAMP3_ID:
			relay_on(RELAY3_ID);
		break;
		
		case LAMP4_ID:
			relay_on(RELAY4_ID);
		break;
		
		case LAMP5_ID:
			relay_on(RELAY5_ID);
		break;
	}
}

void lamp_off(u8 id)
{
	switch(id)
	{
		case LAMP1_ID:
			relay_off(RELAY1_ID);
		break;
		
		case LAMP2_ID:
			relay_off(RELAY2_ID);
		break;
		
		case LAMP3_ID:
			relay_off(RELAY3_ID);
		break;
		
		case LAMP4_ID:
			relay_off(RELAY4_ID);
		break;
		
		case LAMP5_ID:
			relay_off(RELAY5_ID);
		break;
	}
}
