


#ifndef TIMER2_REG_H_
#define TIMER2_REG_H_

#define TIMER2_TCCR2_REG			(*(volatile u8*)0x45)
#define TIMER2_TCNT2_REG			(*(volatile u8*)0x44)
#define TIMER2_OCR2_REG				(*(volatile u8*)0x43)
#define TIMER2_TIMSK_REG			(*(volatile u8*)0x59)
#define TIMER2_TIFR_REG				(*(volatile u8*)0x58)

#define TOV_BIT_NO					(6)
#define TOIE_BIT_NO					(6)
#define OCIE_BIT_NO					(7)
#define OCF_BIT_NO					(7)

#endif /* TIMER2_REG_H_ */