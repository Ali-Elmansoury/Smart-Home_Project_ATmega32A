#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "MM74C922.h"

/*Function prototype*/

/*Keypad Initialization*/
void keypad_init(void);
/*Read Key*/
u8 keypad_readKey(void);

#endif /* KEYPAD_H_ */