/*
 * timer0.h
 *
 * Created: 25-Oct-23 9:28:51 PM
 *  Author: pc
 */ 


#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_
#define TIMER0_TCCR0_REG (*(volatile u8*)0x53)
#define TIMER0_TCNT0_REG (*(volatile u8*)0x52)
#define TIMER0_OCR0_REG (*(volatile u8*)0x5C)
#define TIMER0_TIMSK_REG (*(volatile u8*)0x59)
#define TIMER0_TIFR_REG (*(volatile u8*)0x58)



#endif /* TIMER0_H_ */