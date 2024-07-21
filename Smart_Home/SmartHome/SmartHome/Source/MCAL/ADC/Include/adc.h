


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "adc_reg.h"

/*Prescaler configurations*/
#define ADC_PRESCALER_2			(1)
#define ADC_PRESCALER_4			(2)
#define ADC_PRESCALER_8			(3)
#define ADC_PRESCALER_16		(4)
#define ADC_PRESCALER_32		(5)
#define ADC_PRESCALER_64		(6)
#define ADC_PRESCALER_128		(7)

/*VREF configurations*/
#define ADC_VREF_AREF				(0<<6)
#define ADC_VREF_AVCC				(1<<6)
#define ADC_VREF_2_56V				(3<<6)

/*ADC channel IDs*/
#define ADC0_CHANNEL				(0)
#define ADC1_CHANNEL				(1)
#define ADC2_CHANNEL				(2)
#define ADC3_CHANNEL				(3)
#define ADC4_CHANNEL				(4)
#define ADC5_CHANNEL				(5)
#define ADC6_CHANNEL				(6)
#define ADC7_CHANNEL				(7)


#define ADC_CHANNELID_CLEAR_MUSK	(0xE0)


/*Function prototype*/

/*ADC initialization -->Enable ADC, ADC clock, Select AREF*/
void adc_init(void); 
/*Read ADC channel value*/
u16 adc_read(u8 channelId);

#endif /* ADC_H_ */