#ifndef GIE_H_
#define GIE_H_

#include "gie_reg.h"
#include "std_types.h"

#define I_BIT_NO		(7)


/*Functions prototype*/

/*Enable all interrupts*/
void gie_enableAllInterrupts(void);
/*Disable all interrupts*/
void gie_disableAllInterrupts(void);

#endif /* GIE_H_ */