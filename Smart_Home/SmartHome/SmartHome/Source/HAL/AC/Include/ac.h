/*
 * ac.h
 *
 * Created: 2/5/2024 4:55:29 AM
 *  Author: ali_e
 */ 


#ifndef AC_H_
#define AC_H_

#include "std_types.h"

typedef struct 
{
    boolean AC_Status = FALSE;
    u8 AC_Run_Temperature_threshold=21;
    u8 AC_Stop_Temperature_threshold=28;
}AC;

/*Function prototype*/

/*Air conditioner initialization*/
void airConditioner_init(void);
/* Air conditioner status check*/
void airConditioner_status(void);
/*Air conditioner ON*/
void airConditioner_on(void);
/*Air conditioner OFF*/
void airConditioner_off(void);

#endif /* AC_H_ */