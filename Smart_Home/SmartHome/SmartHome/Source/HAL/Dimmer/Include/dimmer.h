

#ifndef DIMMER_H_
#define DIMMER_H_

#define DIMMER_TURN_OFF			(0)

/*Function prototype*/

/*Dimmer lamp Initialization*/
void dimmer_init(void);
/*Set intensity of dimmer lamp*/
void dimmer_setIntensity(void);
/*Dimmer lamp off*/
void dimmer_turnOff(void);

#endif /* DIMMER_H_ */