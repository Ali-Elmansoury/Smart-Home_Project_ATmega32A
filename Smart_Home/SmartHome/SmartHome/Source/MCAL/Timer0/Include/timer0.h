


#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_types.h"
#include "timer0_reg.h"

/*Timer modes*/
#define TIMER0_MODE_NORMAL							(0b00000000)
#define TIMER0_MODE_CTC								(0b00001000)

/*Fast PWM modes*/
#define TIMER0_NON_INVERTED_PWM_FAST				(0b01101000)
#define TIMER0_INVERTED_PWM_FAST					(0b01111000)

/*PWM phase correct modes*/
#define TIMER0_NON_INVERTED_PWM_PHASE_CORRECT		(0b01100000)
#define TIMER0_INVERTED_PWM_PHASE_CORRECT			(0b01110000)

/*Timer prescaler*/
#define TIMER0_NO_CLOCK								(0b00000000)
#define TIMER0_F_CPU								(0b00000001)
#define TIMER0_F_CPU_DIV_8							(0b00000010)
#define TIMER0_F_CPU_DIV_64							(0b00000011)
#define TIMER0_F_CPU_DIV_256						(0b00000100)
#define TIMER0_F_CPU_DIV_1024						(0b00000101)
#define TIMER0_COUNTER_FAILING						(0b00000110)
#define TIMER0_COUNTER_RISING						(0b00000111)

/*Fast PWM frequencies*/
#define PWM_F_62_5KHZ								(0b00000001)
#define PWM_F_7_8KHZ								(0b00000010)
#define PWM_F_1KHZ									(0b00000011)
#define PWM_F_244HZ									(0b00000100)
#define PWM_F_61HZ									(0b00000101)

/*Phase correct frequencies*/
#define PWM_F_31_25KHZ								(0b00000001)
#define PWM_F_3_9KHZ								(0b00000010)
#define PWM_F_500HZ									(0b00000011)
#define PWM_F_122HZ									(0b00000100)
#define PWM_F_30_5HZ								(0b00000101)

#define TIMER0_STOP_MASK							(0xF8)
#define TIMER0_TOP									(255)

/*Function prototype*/

/*Timer0 initialization*/
void timer0_init(u8 mode);
/*Timer0 start*/
void timer0_start(u8 clk);
/*Timer0 stop*/
void timer0_stop(void);
/*Timer0 setting preload*/
void timer0_setPreLoad(u8 value);
/*Enable timer0 overflow interrupt*/
void timer0_enableOvInterrupt(void);
/*Disable timer0 overflow interrupt*/
void timer0_disableOvInterrupt(void);
/*Timer0 set overflow callback*/
void timer0_setOvCallBack(void (*fptr) (void));

/*Set compare value*/
void timer0_setCompareValue(u8 value);
/*Enable timer0 CTC interrupt*/
void timer0_enableCTCInterrupt(void);
/*Disable timer0 CTC interrupt*/
void timer0_disableCTCInterrupt(void);
/*Timer0 set CTC callback*/
void timer0_setCTCCallBack(void (*fptr) (void));

/*PWM0 initialization and frequency*/
void pwm0_init(u8 mode, u8 freq);
/*PWM0 set duty cycle*/
void pwm0_setDutyCycle(u8 dutyCycle);

#endif /* TIMER0_H_ */