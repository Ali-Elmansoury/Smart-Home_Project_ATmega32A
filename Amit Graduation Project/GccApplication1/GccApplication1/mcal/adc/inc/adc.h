/*
* adc.h
*
* Created: 18-Oct-23 8:43:25 PM
*  Author: pc
*/


#ifndef ADC_H_
#define ADC_H_
#include "adc_reg.h"
/* prescaler configurations */
#define ADC_PSCALER_2	(1)
#define ADC_PSCALER_4	(2)
#define ADC_PSCALER_8	(3)
#define ADC_PSCALER_16  (4)
#define ADC_PSCALER_32	(5)
#define ADC_PSCALER_64	(6)
#define ADC_PSCALER_128	(7)

/* vref configurations */
#define ADC_VREF_AREF (0<<6)
#define ADC_VREF_AVCC (1<<6)
#define ADC_VREF_2_56 (3<<6)

/* ADC channel IDs */
#define ADC0_CHANNEL (0)
#define ADC1_CHANNEL (1)
#define ADC2_CHANNEL (2)
#define ADC3_CHANNEL (3)
#define ADC4_CHANNEL (4)
#define ADC5_CHANNEL (5)
#define ADC6_CHANNEL (6)
#define ADC7_CHANNEL (7)


#define ADC_CHANNEL_ID_CLEAR_MASK (0b11100000)


/*
init function adjusts:
Enable ADC
ADC clock
select Aref
*/
void adc_init(void); //Aref=AVCC(5v)

/* read ADC channel value */
u16 adc_read(u8 channelD);

void adc_enableInterrupt(void);
void adc_disableInterrupt(void);

#endif /* ADC_H_ */