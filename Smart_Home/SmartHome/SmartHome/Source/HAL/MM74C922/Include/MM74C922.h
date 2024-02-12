#ifndef MM74C922_H_
#define MM74C922_H_

#include "std_types.h"

#define KEY_A			('A')
#define KEY_B			('B')
#define KEY_C			('C')
#define KEY_D			('D')
#define KEY_Asterisk	('*')
#define KEY_Hashtag		('#')

void MM74C922_Init(u8 portId, u8 pinId_S , u8 pinId_E);
void MM74C922_Decode();
u8 MM74C922_GetKey(void);

#endif /* MM74C922_H_ */