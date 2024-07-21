


#ifndef LED_SERVICE_H_
#define LED_SERVICE_H_
#include "std_types.h"
/* Dimmer Lamp service init */
void lamp_Dim_service_init();
/* The Dimmer service */
void lamp_Dim_service();
/* Dimmer Toggle */
void Lamp_Service_Dim_Toggle();
/* Return lamp ON/OFF state */
boolean Lamp_Service_Dim_state();
#endif /* LED_SERVICE_H_ */