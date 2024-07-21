

#ifndef POT_H_
#define POT_H_

#include "adc.h"

#define VOLT_PER_DEG		(10)
#define VOLT_PER_STEP		(5000.0/1023.0)
#define POT_PIN				(ADC7_CHANNEL)

/*Function prototype*/

/*Enable POT*/
void POT_init(void);
/*Read voltage from sensor*/
u16 POT_read(void);

#endif /* POT_H_ */