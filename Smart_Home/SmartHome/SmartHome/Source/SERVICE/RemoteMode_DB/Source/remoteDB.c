/*
 * remoteDB.c
 *
 * Created: 2/6/2024 7:11:20 PM
 *  Author: ali_e
 */ 

#define F_CPU 16000000UL
#include <stdio.h>
#include <util/delay.h>
#include "remoteDB.h"
#include "lcd.h"
#include "uart.h"
#include "eeprom.h"
#include "string.h"

user remoteUsers[DB_MAX_SIZE];
boolean login_flag_remote = FALSE;

void remoteDB_init()
{
	uart_init(BAUD_RATE_9600);
}

// Function to get an 8-digit password from the user securely
void getPassword_remote(char* password, u8 maxLength)
{
	u8 index = 0;

	uart_sendString("Enter Password:\n");

	// Simulate getting secure user input for the password
	while (index < maxLength - 1)
	{
		u8 key = uart_receiveByte();

		// Check for Enter key
		if (key == 'D')
		{
			// Check if the password is exactly 8 digits
			if (index == 8)
			{
				break;
			}
			else
			{
				// Password length is incorrect, clear and ask again
				uart_sendString("Invalid Password\n");
				_delay_ms(1000);  // Wait for 1 second
				uart_sendString("Enter Password:\n");
				index = 0;
				continue;
			}
		}
		else if (key == 'C')
		{  // Backspace
			if (index > 0)
			{
				index--;
				password[index] = '\0';
				uart_sendString("Enter Password:\n");

				// Display asterisks for entered characters
				for (u8 i = 0; i < index; ++i) {
					uart_sendByte("*");
				}
			}
		}
		else if (key >= '0' && key <= '9')
		{  // Numeric keys
			password[index] = key;
			index++;
			uart_sendByte("*");
		}
		// Add more conditions for other keys as needed
	}
	password[index] = '\0';  // Null-terminate the password
}

