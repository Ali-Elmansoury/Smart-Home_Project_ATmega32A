/*
* timer0.h
*
* Created: 25-Oct-23 10:33:22 PM
*  Author: pc
*/


#ifndef TIMER0_H_
#define TIMER0_H_
#include "timer0_reg.h"
#include "std_types.h"
#define TIMER0_MODE_NORMAL				(0b00000000)
#define TIMER0_MODE_CTC					(0b00001000)

#define TIMER0_NON_INVERTED_PWM_FAST	(0b01101000)
#define TIMER0_INVERTED_PWM_FAST		(0b01111000)

#define TIMER0_NON_INVERTED_PWM_PHASE_CORRECT	(0b01100000)
#define TIMER0_INVERTED_PWM_PHASE_CORRECT		(0b01110000)

#define TIMER0_NO_CLOCK			(0b00000000)
#define TIMER0_F_CPU			(0b00000001)
#define TIMER0_F_CPU_DIV_8		(0b00000010)
#define TIMER0_F_CPU_DIV_64		(0b00000011)
#define TIMER0_F_CPU_DIV_256	(0b00000100)
#define TIMER0_F_CPU_DIV_1024	(0b00000101)

#define TIMER0_COUNTER_FALLING	(0b00000110)
#define TIMER0_COUNTER_RISING	(0b00000111)

/* fast pwm frequencies */
#define PWM_F_62_5KHZ (0b00000001)
#define PWM_F_7_8KHZ  (0b00000010)
#define PWM_F_1KHZ	  (0b00000011)
#define TPWM_F_244HZ  (0b00000100)
#define PWM_F_61KHZ	  (0b00000101)

/* phase correct pwn frequencies */
#define PWM_F_31_25KHZ	(0b00000001)
#define PWM_F_3_9KHZ	(0b00000010)
#define PWM_F_500HZ		(0b00000011)
#define TPWM_F_122HZ	(0b00000100)
#define PWM_F_30_5HZ	(0b00000101)

#define TIMER0_TOP 255

#define TOV_BIT_NO				(0)
#define OCF_BIT_NO				(1)
#define TOIE_BIT_NO				(0)
#define OCIE_BIT_NO				(1)

#define TIMER_STOP_MASK (0xF8)

/*Timer functions*/
/*Noemal Mode*/
void timer0_init(u8 mode);
void timer0_start(u8 clk);
void timer0_stop(void);
void timer0_setPreLoad(u8 value);
void timer0_enableOVInterrupt(void);
void timer0_disableOVInterrupt(void);
void timer0_setOvCallBack(void(*fptr)(void));

/*CTC Mode*/
void timer0_setCompareValue(u8 value);
void timer0_enableCtcInterrupt(void);
void timer0_disableCtcInterrupt(void);
void timer0_setCtcCallBack(void(*fptr)(void));

/*PWM functions*/
void pwm0_init(u8 mode, u8 freq);
void pwm0_setDutyCycle(u8 dutyCycle);
#endif /* TIMER0_H_ */