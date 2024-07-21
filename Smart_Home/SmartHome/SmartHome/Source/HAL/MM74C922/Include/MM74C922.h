#ifndef MM74C922_H_
#define MM74C922_H_

#include "std_types.h"

#define KEY_A			('A')
#define KEY_B			('B')
#define KEY_C			('C')
#define KEY_D			('D')
#define KEY_Asterisk	('*')
#define KEY_HASH		('#')

#define NO_DATA			(0xFF)

void MM74C922_Init();
void MM74C922_Decode();
u8 MM74C922_GetKey(void);

#endif /* MM74C922_H_ */