


#ifndef L293D_H_
#define L293D_H_

#include "std_types.h"

/*Directions*/
#define CW_DIR				(0)
#define CCW_DIR				(1)

#define MOTOR_A_ID			(0)
#define MOTOR_B_ID			(1)

/*Function prototype*/

/*L293D Initialization*/
void L293D_init(void);
/*Set direction*/
void L293D_setDirection(u8 direcion, u8 motorId);
/*Set speed*/
void L293D_setSpeed(u8 speed, u8 motorId);

#endif /* L293D_H_ */