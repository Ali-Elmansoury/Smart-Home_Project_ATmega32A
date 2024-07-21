
#include "std_types.h"
#include "dimmer.h"

boolean Dim_Service_state = TRUE;

void lamp_Dim_service_init()
{
	dimmer_init();
}

void lamp_Dim_service()
{
	switch(Dim_Service_state)
	{
		case TRUE:
			dimmer_setIntensity();
			break;
		case FALSE:
			dimmer_turnOff();
			break;
		default:
			break;
	}
}

void Lamp_Service_Dim_Toggle()
{
	Dim_Service_state^= TRUE;
}

boolean Lamp_Service_Dim_state()
{
	return Dim_Service_state;
}