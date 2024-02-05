/*
 * relay.h
 *
 * Created: 9/29/2023 2:11:01 AM
 *  Author: ali_e
 */ 


#ifndef RELAY_H_
#define RELAY_H_

#include "std_types.h"

/*Relay IDs*/

#define RELAY1_ID			(1)
#define RELAY2_ID			(2)
#define RELAY3_ID			(3)
#define RELAY4_ID			(4)
#define RELAY5_ID			(5)

/*Function prototypes*/

/*Relay initialization*/
void relay_init(void);
/*Turn relay on*/
void relay_on(u8 id);
/*Turn relay off*/
void relay_off(u8 id);

#endif /* RELAY_H_ */