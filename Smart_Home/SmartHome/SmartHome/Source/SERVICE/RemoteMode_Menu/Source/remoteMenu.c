/*
 * remoteMenu.c
 *
 * Created: 2/6/2024 9:44:24 PM
 *  Author: ali_e
 */ 

#include "remoteMenu.h"
#include "std_types.h"
#include "uart.h"
#include "ac.h"
#include "lamp.h"
#include "Lamp_Dim_Service.h"
#include "door.h"
#include "localDB.h"
#include "remoteDB.h"
#include "stdlib.h"

void remote_admin_register()
{
	static u8 hasRun = 0;
	if (!hasRun)
	{
		remoteDB_init();
		uart_sendString("Register as an admin\n");
		uart_sendString("Enter username: ");
		u8 username[16];
		uart_receiveString(username);
		u8 password[9];
		getPassword_remote(&password, 9);  // Get password from user
		u32 passwordValue = atoi(&password);
		u8 registrationResult = addUserToEEPROM_remote(username,passwordValue);
		if (registrationResult == REGISTRATION_SUCCESS)
		{
			// Registration successful
			uart_sendString("Registration successful\n");
		}
		else if (registrationResult == ERROR_USER_ARRAY_FULL)
		{
			// User array is full
			uart_sendString("Error: User array is full\n");
		}
		else
		{
			// Other error occurred during EEPROM write
			uart_sendString("Error: EEPROM write failed\n");
		}
		hasRun = 1;
	}
}

void registerUserRemote()
{
	uart_sendString("Register a new user\n");
	uart_sendString("Enter username: ");
	u8 username[16];
	uart_receiveString(username);
	u8 password[9];
	getPassword_remote(&password, 9);  // Get password from user
	u32 passwordValue = atoi(&password);
	u8 registrationResult = addUserToEEPROM_remote(username,passwordValue);
	if (registrationResult == REGISTRATION_SUCCESS)
	{
		// Registration successful
		uart_sendString("Registration successful\n");
	}
	else if (registrationResult == ERROR_USER_ARRAY_FULL)
	{
		// User array is full
		uart_sendString("Error: User array is full\n");
	}
	else
	{
		// Other error occurred during EEPROM write
		uart_sendString("Error: EEPROM write failed\n");
	}
}

void registerUserLocal()
{
	uart_sendString("Register a new user\n");
	uart_sendString("Enter username: ");
	u8 username[16];
	uart_receiveString(username);
	u8 password[9];
	getPassword_remote(&password, 9);  // Get password from user
	u32 passwordValue = atoi(&password);
	u8 registrationResult = addUserToEEPROM_local(username,passwordValue);
	if (registrationResult == REGISTRATION_SUCCESS)
	{
		// Registration successful
		uart_sendString("Registration successful\n");
	}
	else if (registrationResult == ERROR_USER_ARRAY_FULL)
	{
		// User array is full
		uart_sendString("Error: User array is full\n");
	}
	else
	{
		// Other error occurred during EEPROM write
		uart_sendString("Error: EEPROM write failed\n");
	}
}

void remote_Menu_Admin()
{
	while (1) {
		uart_sendString("Admin Menu:\n");
		uart_sendString("1. Register User (Remote)\n");
		uart_sendString("2. Register User (Local)\n");
		uart_sendString("3. Control Door (Open/Close)\n");
		uart_sendString("4. Logout\n");

		u8 adminChoice = uart_receiveByte();

		switch (adminChoice) {
			case '1':
				registerUserRemote();
			break;
			case '2':
				registerUserLocal();
			break;
			case '3':
				doorToggle();
			break;
			case '4':
				logout_remote();
			return;
			default:
				uart_sendString("Invalid choice. Please try again.\n");
			continue;
		}
	}
	
	uart_sendString("Choose a mode:");
	uart_sendString(" 1.Remote Mode\n 2.Local Mode");
	u8 choice = uart_receiveByte();
	switch(choice)
	{
		case '1':
			remote_menu_Service();
		break;
		case '2':
			local_menu_Service();
		break;
		default:
			uart_sendString("Invalid choice. Please try again.\n");
	}
}

void remote_Menu_User()
{
	while (1) {
		uart_sendString("User Menu:\n");
		uart_sendString("1. Lamps\n");
		uart_sendString("2. Dimmer\n");
		uart_sendString("3. AC\n");
		uart_sendString("4. Logout\n");

		u8 userChoice = uart_receiveByte();

		switch (userChoice) {
			case '1':
				//Lamps code
			break;
			case '2':
				//Dimmer code
			break;
			case '3':
				//AC code
			break;
			case '4':
				logout_remote();
			return;
			default:
				uart_sendString("Invalid choice. Please try again.\n");
			continue;
		}
	}
	
	uart_sendString("Choose a mode:");
	uart_sendString(" 1.Remote Mode\n 2.Local Mode");
	u8 choice = uart_receiveByte();
	switch(choice)
	{
		case '1':
			remote_menu_Service();
		break;
		case '2':
			local_menu_Service();
		break;
		default:
			uart_sendString("Invalid choice. Please try again.\n");
	}
}

void remote_menu_Service(void)
{
	uart_sendString("System is starting in remote mode\n");
	remote_admin_register();
	user_remote registeredUsers;
	displayAllUsersOnRemote();
	u8 id = selectUserAndLogin_remote();
	getUserFromEEPROM_remote(id,&registeredUsers);
	if (registeredUsers.id == 1 && loginAck_remote())
	{
		remote_Menu_Admin();
	}
	else
	{
		//login
		if (loginAck_remote())
		{
			remote_Menu_User();
		}
		else{
			//do nothing
		}
	}
}

