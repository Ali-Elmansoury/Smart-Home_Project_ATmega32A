#ifndef AC_H_
#define AC_H_

#include "std_types.h"

struct AC
{
    boolean AC_Status;
    u8 AC_Run_Temperature_threshold;
    u8 AC_Stop_Temperature_threshold;
};

typedef struct AC AC;

/*Function prototype*/

/* Air conditioner initialization */
void airConditioner_init(void);
/* Air conditioner status check */
AC airConditioner_Status(void);
/* Air conditioner service */
void airConditioner_service(void);
/* Set AC Temp config */
void airConditioner_Set_Config(AC *ac_config);
/* Turns AC service ON/OFF */
void airConditioner_Toggle(void);
/* Air conditioner ON */
void airConditioner_on(void);
/* Air conditioner OFF */
void airConditioner_off(void);

boolean airConditioner_State(void);

#endif /* AC_H_ */