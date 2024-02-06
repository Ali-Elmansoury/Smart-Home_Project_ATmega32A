#ifndef MM74C922_H_
#define MM74C922_H_

#include "std_types.h"

void MM74C922_Init(u8 portId, u8 pinId_S , u8 pinId_E);
void MM74C922_Decode(u8 *data);
u8 MM74C922_GetKey(void);

#endif /* MM74C922_H_ */