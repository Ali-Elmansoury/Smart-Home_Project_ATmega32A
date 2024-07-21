#ifndef LAMP_H_
#define LAMP_H_

#include "std_types.h"

/*Lamp IDs*/

#define LAMP1_ID			(1)
#define LAMP2_ID			(2)
#define LAMP3_ID			(3)
#define LAMP4_ID			(4)
#define LAMP5_ID			(5)
#define LAMP_DIM_ID			(6)

/*Function prototypes*/

/*Lamp initialization*/
void lamp_init(void);
/*toggle lamp state*/
void lamp_toggle(u8 id);
/*return lamp state*/
boolean lamp_Getstate(u8 id);

#endif /* LAMP_H_ */