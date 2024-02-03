/*
* timer0.c
*
* Created: 25-Oct-23 9:29:01 PM
*  Author: pc
*/
#include "timer0.h"
#include "timer0_reg.h"
#include "bit_math.h"
#include <stdio.h>
#include <avr/interrupt.h>

void(*timer0OVClbkPtr)(void)= NULL;
void (*timer0CtcClbkPtr)(void) = NULL;
void timer0_init(u8 mode){
	TIMER0_TCCR0_REG|= mode;
}
void timer0_start(u8 clk){
	TIMER0_TCCR0_REG|=clk;

}
void timer0_stop(void){
	TIMER0_TCCR0_REG&=TIMER_STOP_MASK; //0b11111000

}
void timer0_setPreLoad(u8 value){
	TIMER0_TCNT0_REG=value;
}
void timer0_enableOVInterrupt(void){
	SET_BIT(TIMER0_TIMSK_REG,TOIE_BIT_NO);
}
void timer0_disableOVInterrupt(void){
	CLEAR_BIT(TIMER0_TIMSK_REG,TOIE_BIT_NO);
}



void timer0_setOvCallBack(void(*fptr)(void)){
	timer0OVClbkPtr=fptr;
}
void timer0_setCompareValue(u8 value)
{
	TIMER0_OCR0_REG = value;
}

void timer0_enableCtcInterrupt(void)
{
	/*	enable Ctc interrupt	*/
	SET_BIT(TIMER0_TIMSK_REG, OCIE_BIT_NO);
}
void timer0_disableCtcInterrupt(void)
{
	/*	enable Ctc interrupt	*/
	CLEAR_BIT(TIMER0_TIMSK_REG, OCIE_BIT_NO);
}
void timer0_setCtcCallBack(void (*fptr)(void))
{
	timer0CtcClbkPtr =fptr;
}



void pwm0_init(u8 mode, u8 freq){
	/* set mode */
	TIMER0_TCCR0_REG|= mode;
	
	/* set frequency */
	TIMER0_TCCR0_REG|=freq;

}

void pwm0_setDutyCycle(u8 dutyCycle){
	TIMER0_OCR0_REG=((f32)dutyCycle/100)*(TIMER0_TOP);
}

ISR(TIMER0_OVF_vect)
{
	if (timer0OVClbkPtr != NULL)
	{
		timer0OVClbkPtr();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(timer0CtcClbkPtr !=NULL)
	{
		timer0CtcClbkPtr();
	}
}