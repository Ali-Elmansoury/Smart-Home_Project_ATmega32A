 


#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADC_ADMUX_REG			(*(volatile u8*)0x27)
#define ADC_ADCSRA_REG			(*(volatile u8*)0x26)
#define ADC_ADCREAD_REG			(*(volatile u16*)0x24)

#define ADC_ENABLE_BIT_NO				(7)
#define ADC_START_CONVERSION_BIT_NO		(6)
#define ADC_INT_FLAG_BIT_NO				(4)

#endif /* ADC_REG_H_ */