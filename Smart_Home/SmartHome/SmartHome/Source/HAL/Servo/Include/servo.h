


#ifndef SERVO_H_
#define SERVO_H_

#include "std_types.h"
#include "timer1.h"
#include "dio.h"

#define SERVO_TOP_VALUE_50_HZ			(4999)

#define SERVO_ANGLE_0_DEGREE			(350)
#define SERVO_ANGLE_90_DEGREE			(600)
#define SERVO_ANGLE_180_DEGREE			(130)

/*Function prototype*/

/*Servo Initialization*/
void servo_init(u8 portId, u8 pinId, u8 direction, u8 modeA, u8 modeB, u8 freq, u16 topValue);
/*Set angle of servo*/
void servo_setAngleDegree(u16 degree);

#endif /* SERVO_H_ */