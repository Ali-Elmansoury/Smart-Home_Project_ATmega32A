


#ifndef LM35_H_
#define LM35_H_

#include "adc.h"

#define VOLT_PER_DEG		(10)
#define VOLT_PER_STEP		(5000.0/1023.0)
#define LM35_PIN			(ADC5_CHANNEL)

/*Function prototype*/

/*Enable LM35*/
void LM35_init(void);
/*Read temperature from sensor*/
u16 LM35_read(void);

#endif /* TEMP_SENSOR_H_ */