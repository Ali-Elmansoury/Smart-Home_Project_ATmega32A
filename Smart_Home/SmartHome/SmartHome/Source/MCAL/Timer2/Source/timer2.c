 

#include "timer2.h"
#include "bit_math.h"
#include <stdio.h>
#include <avr/interrupt.h>

void (*timer2OvClbkPtr)(void)= NULL;
void (*timer2CTCClbkPtr)(void)= NULL;

void timer2_init(u8 mode)
{
	TIMER2_TCCR2_REG |= mode;
}

void timer2_start(u8 clk)
{
	TIMER2_TCCR2_REG |= clk;
}

void timer2_stop(void)
{
	TIMER2_TCCR2_REG &= TIMER2_STOP_MASK; //0b11111000
}

void timer2_setPreLoad(u8 value)
{
	TIMER2_TCNT2_REG = value;
}

void timer2_enableOvInterrupt(void)
{
	SET_BIT(TIMER2_TIMSK_REG,TOIE_BIT_NO);
}

void timer2_disableOvInterrupt(void)
{
	CLEAR_BIT(TIMER2_TIMSK_REG,TOIE_BIT_NO);
}

void timer2_setOvCallBack(void (*fptr) (void))
{
	timer2OvClbkPtr = fptr;
}

ISR(TIMER2_OVF_vect)
{
	if (timer2OvClbkPtr != NULL)
	{
		timer2OvClbkPtr();
	}
}


void timer2_setCompareValue(u8 value)
{
	TIMER2_OCR2_REG = value;
}

void timer2_enableCTCInterrupt(void)
{
	SET_BIT(TIMER2_TIMSK_REG,OCIE_BIT_NO);
}

void timer2_disableCTCInterrupt(void)
{
	CLEAR_BIT(TIMER2_TIMSK_REG,OCIE_BIT_NO);
}

void timer2_setCTCCallBack(void (*fptr) (void))
{
	timer2CTCClbkPtr = fptr;
}

ISR(TIMER2_COMP_vect)
{
	if (timer2CTCClbkPtr != NULL)
	{
		timer2CTCClbkPtr();
	}
}


void pwm2_init(u8 mode, u8 freq)
{
	/*Set mode*/
	TIMER2_TCCR2_REG |= mode;
	/*Set frequency*/
	TIMER2_TCCR2_REG |= freq;
}

void pwm2_setDutyCycle(u8 dutyCycle)
{
	TIMER2_OCR2_REG = ((f32)dutyCycle/100)*(TIMER2_TOP);
}
