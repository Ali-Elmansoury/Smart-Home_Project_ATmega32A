/*
 * l293d.h
 *
 * Created: 01-Nov-23 7:07:00 PM
 *  Author: pc
 */ 


#ifndef L293D_H_
#define L293D_H_
#include "std_types.h"

#define CW_DIR	(0)
#define CCW_DIR (1)

#define MOTOR_A_ID (0)
#define MOTOR_B_ID (1)

void l293d_init(void);
void l293d_setDirection(u8 dir, u8 motorId);
void l293d_setSpeed(u8 speed, u8 motorId);



#endif /* L293D_H_ */