


#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

#define TIMER0_TCCR0_REG			(*(volatile u8*)0x53)
#define TIMER0_TCNT0_REG			(*(volatile u8*)0x52)
#define TIMER0_OCR0_REG				(*(volatile u8*)0x5C)
#define TIMER0_TIMSK_REG			(*(volatile u8*)0x59)
#define TIMER0_TIFR_REG				(*(volatile u8*)0x58)

#define TOV_BIT_NO					(0)
#define TOIE_BIT_NO					(0)
#define OCIE_BIT_NO					(1)
#define OCF_BIT_NO					(1)

#endif /* TIMER0_REG_H_ */