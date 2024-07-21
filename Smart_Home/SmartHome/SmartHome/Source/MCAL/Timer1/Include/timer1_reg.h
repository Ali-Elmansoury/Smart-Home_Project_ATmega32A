#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

#include "sfr.h"

#define TIMER1_TCCR1A_REG			(*(volatile u8*)0x4F)
#define TIMER1_TCCR1B_REG			(*(volatile u8*)0x4E)
#define TIMER1_TCNT1H_REG			(*(volatile u8*)0x4D)
#define TIMER1_TCNT1L_REG			(*(volatile u8*)0x4C)
#define TIMER1_TIMSK_REG			(*(volatile u8*)0x59)
#define TIMER1_TIFR_REG				(*(volatile u8*)0x58)

/* Combine ICR1L and ICR1H */
#define TIMER1_ICR1_REG    _SFR_IO16(0x26)

#define ICR1L			   _SFR_IO8(0x26)
#define ICR1H			   _SFR_IO8(0x27)

/* Combine OCR1BL and OCR1BH */
#define TIMER1_OCR1B_REG   _SFR_IO16(0x28)

#define OCR1BL			   _SFR_IO8(0x28)
#define OCR1BH			   _SFR_IO8(0x29)

/* Combine OCR1AL and OCR1AH */
#define TIMER1_OCR1A_REG    _SFR_IO16(0x2A)

#define OCR1AL			    _SFR_IO8(0x2A)
#define OCR1AH			    _SFR_IO8(0x2B)


#define TOIE1_BIT_NO				(2)

#endif /* TIMER1_REG_H_ */