/*
 * SmartHome.c
 *
 * Created: 2/3/2024 3:02:10 AM
 * Author : ali_e
 */ 

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

int main(void)
{
	airConditioner_init();
	//doorService_init();
	//lamp_Dim_service_init();
	//local_menu_init();
	lcd_init();
	uart_init(BAUD_RATE_9600);
	remoteDB_init();
	//localDB_init();
	lamp_init();
	
    /* Replace with your application code */
    while (1) 
    {
		airConditioner_service();
		//lamp_Dim_service();
		//local_menu_Service();
		remote_menu_Service();
		_delay_ms(1000);
    }
}

