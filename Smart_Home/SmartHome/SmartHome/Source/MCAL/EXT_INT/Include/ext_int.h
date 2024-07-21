#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "std_types.h"
#include "ext_int_reg.h"

#define EXT_INT0_ID					(0)
#define EXT_INT1_ID					(1)
#define EXT_INT2_ID					(2)

#define GICR_EXT_INT0_EN_BIT		(6)
#define GICR_EXT_INT1_EN_BIT		(7)
#define GICR_EXT_INT2_EN_BIT		(5)

#define MCUCR_ISC00_BIT_NO			(0)
#define MCUCR_ISC01_BIT_NO			(1)
#define MCUCR_ISC10_BIT_NO			(2)
#define MCUCR_ISC11_BIT_NO			(3)

#define MCUCSR_ISC2_BIT_NO			(6)

#define LOW_LEVEL					(0)
#define ANY_LOGICAL_CHANGE			(1)
#define FALLING_EDGE				(2)
#define RISING_EDGE					(3)


/*Functions prototype*/

/*Enable external interrupt*/
void extINT_enable(u8 interruptId);
/*Disable external interrupt*/
void extINT_disable(u8 interruptId);
/*Set sense control*/
void extINT_setSenseControl(u8 interruptId, u8 senseControl);
/*CallBack function by pointer*/
void extINT_setCallBack(u8 interruptId, void(*fptr)(void));

#endif /* EXT_INT_H_ */