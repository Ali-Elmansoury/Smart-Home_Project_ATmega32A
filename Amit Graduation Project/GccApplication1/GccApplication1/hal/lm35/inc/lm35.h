/*
 * lm35.h
 *
 * Created: 25-Oct-23 6:56:28 PM
 *  Author: pc
 */ 


#ifndef LM35_H_
#define LM35_H_
#include "adc.h"
#include "std_types.h"


void lm35_init(void);

u16 lm35_readTemp(void);




#endif /* LM35_H_ */