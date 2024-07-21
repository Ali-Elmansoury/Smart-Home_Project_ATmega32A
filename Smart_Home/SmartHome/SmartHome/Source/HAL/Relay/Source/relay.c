
#include "dio.h"
#include "relay.h"

void relay_init(void)
{
	dio_setPinDirection(PORTA_ID,PIN0_ID,OUTPUT);
	dio_setPinDirection(PORTA_ID,PIN1_ID,OUTPUT);
	dio_setPinDirection(PORTA_ID,PIN2_ID,OUTPUT);
	dio_setPinDirection(PORTA_ID,PIN3_ID,OUTPUT);
	dio_setPinDirection(PORTA_ID,PIN4_ID,OUTPUT);
}

void relay_toggle(u8 id)
{
	switch(id)
	{
		case RELAY1_ID:
			dio_toggleChannel(PORTA_ID,PIN0_ID);
		break;
		
		case RELAY2_ID:
			dio_toggleChannel(PORTA_ID,PIN1_ID);
		break;
		
		case RELAY3_ID:
			dio_toggleChannel(PORTA_ID,PIN2_ID);
		break;
		
		case RELAY4_ID:
			dio_toggleChannel(PORTA_ID,PIN3_ID);
		break;
		
		case RELAY5_ID:
			dio_toggleChannel(PORTA_ID,PIN4_ID);
		break;
	}
}
