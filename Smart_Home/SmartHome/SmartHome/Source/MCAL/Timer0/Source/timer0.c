 

#include "timer0.h"
#include "bit_math.h"
#include <stdio.h>
#include <avr/interrupt.h>

void (*timer0OvClbkPtr)(void)= NULL;
void (*timer0CTCClbkPtr)(void)= NULL;

void timer0_init(u8 mode)
{
	TIMER0_TCCR0_REG |= mode;
}

void timer0_start(u8 clk)
{
	TIMER0_TCCR0_REG |= clk;
}

void timer0_stop(void)
{
	TIMER0_TCCR0_REG &= TIMER0_STOP_MASK; //0b11111000
}

void timer0_setPreLoad(u8 value)
{
	TIMER0_TCNT0_REG = value;
}

void timer0_enableOvInterrupt(void)
{
	SET_BIT(TIMER0_TIMSK_REG,TOIE_BIT_NO);
}

void timer0_disableOvInterrupt(void)
{
	CLEAR_BIT(TIMER0_TIMSK_REG,TOIE_BIT_NO);
}

void timer0_setOvCallBack(void (*fptr) (void))
{
	timer0OvClbkPtr = fptr;
}

ISR(TIMER0_OVF_vect)
{
	if (timer0OvClbkPtr != NULL)
	{
		timer0OvClbkPtr();
	}
}


void timer0_setCompareValue(u8 value)
{
	TIMER0_OCR0_REG = value;
}

void timer0_enableCTCInterrupt(void)
{
	SET_BIT(TIMER0_TIMSK_REG,OCIE_BIT_NO);
}

void timer0_disableCTCInterrupt(void)
{
	CLEAR_BIT(TIMER0_TIMSK_REG,OCIE_BIT_NO);
}

void timer0_setCTCCallBack(void (*fptr) (void))
{
	timer0CTCClbkPtr = fptr;
}

ISR(TIMER0_COMP_vect)
{
	if (timer0CTCClbkPtr != NULL)
	{
		timer0CTCClbkPtr();
	}
}


void pwm0_init(u8 mode, u8 freq)
{
	/*Set mode*/
	TIMER0_TCCR0_REG |= mode;
	/*Set frequency*/
	TIMER0_TCCR0_REG |= freq;
}


void pwm0_setDutyCycle(u8 dutyCycle)
{
	TIMER0_OCR0_REG = ((f32)dutyCycle/100)*(TIMER0_TOP);
}