


#ifndef TIMER2_H_
#define TIMER2_H_

#include "std_types.h"
#include "timer2_reg.h"

/*Timer modes*/
#define TIMER2_MODE_NORMAL							(0b00000000)
#define TIMER2_MODE_CTC								(0b00001000)

/*Fast PWM modes*/
#define TIMER2_NON_INVERTED_PWM_FAST				(0b01101000)
#define TIMER2_INVERTED_PWM_FAST					(0b01111000)

/*PWM phase correct modes*/
#define TIMER2_NON_INVERTED_PWM_PHASE_CORRECT		(0b01100000)
#define TIMER2_INVERTED_PWM_PHASE_CORRECT			(0b01110000)

/*Timer prescaler*/
#define TIMER2_NO_CLOCK								(0b00000000)
#define TIMER2_F_CPU								(0b00000001)
#define TIMER2_F_CPU_DIV_8							(0b00000010)
#define TIMER2_F_CPU_DIV_32							(0b00000011)
#define TIMER2_F_CPU_DIV_64							(0b00000100)
#define TIMER2_F_CPU_DIV_128						(0b00000101)
#define TIMER2_F_CPU_DIV_256						(0b00000110)
#define TIMER2_F_CPU_DIV_1024						(0b00000111)

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

#define TIMER2_STOP_MASK							(0xF8)
#define TIMER2_TOP									(255)

/*Function prototype*/

/*Timer2 initialization*/
void timer2_init(u8 mode);
/*Timer2 start*/
void timer2_start(u8 clk);
/*Timer2 stop*/
void timer2_stop(void);
/*Timer2 setting preload*/
void timer2_setPreLoad(u8 value);
/*Enable timer2 overflow interrupt*/
void timer2_enableOvInterrupt(void);
/*Disable timer2 overflow interrupt*/
void timer2_disableOvInterrupt(void);
/*Timer2 set overflow callback*/
void timer2_setOvCallBack(void (*fptr) (void));

/*Set compare value*/
void timer2_setCompareValue(u8 value);
/*Enable timer2 CTC interrupt*/
void timer2_enableCTCInterrupt(void);
/*Disable timer2 CTC interrupt*/
void timer2_disableCTCInterrupt(void);
/*Timer2 set CTC callback*/
void timer2_setCTCCallBack(void (*fptr) (void));

/*PWM2 initialization and frequency*/
void pwm2_init(u8 mode, u8 freq);
/*PWM2 set duty cycle*/
void pwm2_setDutyCycle(u8 dutyCycle);

#endif /* TIMER2_H_ */