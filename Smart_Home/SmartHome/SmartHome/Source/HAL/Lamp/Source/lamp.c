/*
 * lamp.c
 *
 * Created: 2/5/2024 3:06:05 AM
 *  Author: ali_e
 */ 

#include "relay.h"
#include "lamp.h"

boolean lamp_state[5]={FALSE,FALSE,FALSE,FALSE,FALSE};

void lamp_init(void)
{
	relay_init();
}

void lamp_toggle(u8 id)
{
	relay_toggle(id);
	lamp_state[(id-1)] ^= TRUE;
}

boolean lamp_Getstate(u8 id)
{
	return lamp_state[(id-1)];
}

