/*
 * lamp.h
 *
 * Created: 2/5/2024 3:04:59 AM
 *  Author: ali_e
 */ 


#ifndef LAMP_H_
#define LAMP_H_

#include "std_types.h"

/*Lamp IDs*/

#define LAMP1_ID			(1)
#define LAMP2_ID			(2)
#define LAMP3_ID			(3)
#define LAMP4_ID			(4)
#define LAMP5_ID			(5)

/*Function prototypes*/

/*Lamp initialization*/
void lamp_init(void);
/*Turn lamp on*/
void lamp_on(u8 id);
/*Turn lamp off*/
void lamp_off(u8 id);

#endif /* LAMP_H_ */