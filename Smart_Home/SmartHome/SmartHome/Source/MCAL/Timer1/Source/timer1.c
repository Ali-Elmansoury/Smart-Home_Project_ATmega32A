#include "timer1.h"
#include "bit_math.h"
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void (*timer1OvClbkPtr)(void)= NULL;

void timer1_init(u8 mode)
{
	TIMER1_TCCR1A_REG |= mode;
}

void timer1_start(u8 clk)
{
	TIMER1_TCCR1B_REG |= clk;
}

void timer1_stop(void)
{
	TIMER1_TCCR1B_REG &= TIMER1_STOP_MASK; //0b11111000
}

void timer1_setPreLoad(u8 highByte, u8 lowByte)
{
	TIMER1_TCNT1L_REG = lowByte;
	TIMER1_TCNT1H_REG = highByte;
}

void timer1_enableOvInterrupt(void)
{
	SET_BIT(TIMER1_TIMSK_REG,TOIE1_BIT_NO);
}

void timer1_disableOvInterrupt(void)
{
	CLEAR_BIT(TIMER1_TIMSK_REG,TOIE1_BIT_NO);
}

void timer1_setOvCallBack(void (*fptr) (void))
{
	timer1OvClbkPtr = fptr;
}

ISR(TIMER1_OVF_vect)
{
	if (timer1OvClbkPtr != NULL)
	{
		timer1OvClbkPtr();
	}
}

void pwm1_init(u8 modeA, u8 modeB, u8 freq)
{
	/*Set mode*/
	TIMER1_TCCR1A_REG |= modeA;
	/*Set mode & freq*/
	TIMER1_TCCR1B_REG |= (modeB | freq);
	
// 	TIMER1_TCCR1B_REG |= modeB;
// 	/*Set frequency*/
// 	TIMER1_TCCR1B_REG |= freq;
}

void pwm1_setTopValue(u8 topValue)
{
	ICR1 = topValue;
}

void pwm1_setDutyCycle(u8 dutyCycle)
{
	OCR1A = dutyCycle;
}