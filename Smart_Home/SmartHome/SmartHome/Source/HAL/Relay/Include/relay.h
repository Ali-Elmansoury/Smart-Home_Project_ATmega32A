 


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
/*Turn relay state*/
void relay_toggle(u8 id);
#endif /* RELAY_H_ */