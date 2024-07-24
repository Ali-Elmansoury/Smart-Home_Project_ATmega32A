#define F_CPU 16000000UL
#include <util/delay.h>

#include "localMenu.h"
#include "remoteMenu.h"
#include "Lamp_Dim_Service.h"
#include "ac.h"
#include "door.h"
#include "lcd.h"
#include "adc.h"
#include "dio.h"
#include "uart.h"
#include "remoteDB.h"
#include "localDB.h"
#include "lamp.h"
#include "buzzer.h"
#include "Stop.h"

int main(void)
{
	lcd_init();
	airConditioner_init();
	doorService_init();
	lamp_Dim_service_init();
	local_menu_init();
	uart_init(BAUD_RATE_9600);
	remoteDB_init();
	localDB_init();
	lamp_init();
	remote_menu_init();
	buzzer_init();
    while (1) 
    {
		switch(System_Stop())
		{
			case TRUE:
				buzzer_on();
				break;
			default:
				local_menu_Service();
				remote_menu_Service();
				break;
		}
		_delay_ms(20);
		airConditioner_service();
		lamp_Dim_service();
		
    }
}

