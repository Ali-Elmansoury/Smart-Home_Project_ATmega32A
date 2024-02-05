/*
 * gie.c
 *
 * Created: 10/11/2023 7:33:17 PM
 *  Author: ali_e
 */ 

#include "gie.h"
#include "bit_math.h"

void gie_enableAllInterrupts(void)
{
	SET_BIT(GIE_SREG,I_BIT_NO);
}

void gie_disableAllInterrupts(void)
{
	CLEAR_BIT(GIE_SREG,I_BIT_NO);
}