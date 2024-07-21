


#ifndef DOOR_H_
#define DOOR_H_

#define DOOR_CLOSED			(0)
#define DOOR_OPENED			(1)

/*Function prototype*/

/*Door service initialization*/
void doorService_init();
/*Open door*/
void doorOpen();
/*Close door*/
void doorClose();
/*Door toggle*/
void doorToggle();
/*Door service*/
void doorService();

#endif /* DOOR_H_ */