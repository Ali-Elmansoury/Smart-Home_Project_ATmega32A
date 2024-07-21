#ifndef TIMER1_H_
#define TIMER1_H_

#include "std_types.h"
#include "timer1_reg.h"

/*Timer modes*/
#define TIMER1_MODE_NORMAL							(0b00000000)

/*Fast PWM modes*/
#define TIMER1_NON_INVERTED_PWM_FAST_OC1A			(0b10000010)
#define TIMER1_PWM_FAST_ICR							(0b00011000)

/*Timer prescaler*/
#define TIMER1_NO_CLOCK								(0b00000000)
#define TIMER1_F_CPU								(0b00000001)
#define TIMER1_F_CPU_DIV_8							(0b00000010)
#define TIMER1_F_CPU_DIV_64							(0b00000011)
#define TIMER1_F_CPU_DIV_256						(0b00000100)
#define TIMER1_F_CPU_DIV_1024						(0b00000101)

#define TIMER1_STOP_MASK							(0xF8)

/*Function prototype*/

/*Timer1 initialization*/
void timer1_init(u8 mode);
/*Timer1 start*/
void timer1_start(u8 clk);
/*Timer1 stop*/
void timer1_stop(void);
/*Timer1 setting preload*/
void timer1_setPreLoad(u8 highByte, u8 lowByte);
/*Enable timer1 overflow interrupt*/
void timer1_enableOvInterrupt(void);
/*Disable timer1 overflow interrupt*/
void timer1_disableOvInterrupt(void);
/*Timer1 set overflow callback*/
void timer1_setOvCallBack(void (*fptr) (void));

/*PWM1 initialization and frequency*/
void pwm1_init(u8 modeA, u8 modeB, u8 freq);
/*PWM1 set top value*/
void pwm1_setTopValue(u8 topValue);
/*PWM1 set duty cycle*/
void pwm1_setDutyCycle(u8 dutyCycle);

#endif /* TIMER1_H_ */