

#include "remoteMenu.h"
#include "std_types.h"
#include "uart.h"
#include "ac.h"
#include "lamp.h"
#include "Lamp_Dim_Service.h"
#include "door.h"
#include "localDB.h"
#include "remoteDB.h"
#include "eeprom.h"

//Global Variables
boolean Get_Choice = TRUE,
		users_Dispaly = TRUE,
		Display_user_menu = TRUE,
		Display_admin_menu = TRUE;

// Function prototypes
void remote_admin_register(void);
void registerUserRemote(void);
void registerUserLocal(void);
void remote_login_menu(void);
void remote_Menu_User(void);
void remote_Menu_Admin(void);
void lamp_menu(void);
void AC_menu(void);
void remote_menu_Service(void);

void remote_admin_register()
{
	if (EEPROM_read(EEPROM_USER_COUNT_ADDR)>0)
	{return;}
	else
	{
		uart_sendString("Register as an admin\n");
		uart_sendString("Enter username: ");
		u8 username[16];
		uart_receiveString(&username);
		uart_sendString("\n");
		u8 password[9];
		getPassword_remote(&password);  // Get password from user
		u8 registrationResult = addUserToEEPROM_remote(&username,&password);
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
}

void registerUserRemote(void)
{
	u8 registrationResult = ERROR_USER_ARRAY_FULL;
	uart_sendString("Register a new user\n");
	uart_sendString("Enter username: ");
	u8 username[16];
	uart_receiveString(&username);
	u8 password[9];
	getPassword_remote(&password);  // Get password from user
	registrationResult = addUserToEEPROM_remote(&username,&password);
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
	Get_Choice = TRUE;
	Display_user_menu = TRUE;
	Display_admin_menu = TRUE;
}

void registerUserLocal()
{
	uart_sendString("Register a new user\n");
	uart_sendString("Enter username: ");
	u8 username[16];
	uart_receiveString(&username);
	u8 password[9];
	getPassword_remote(&password);  // Get password from user
	u8 registrationResult = addUserToEEPROM_local(&username,&password);
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
	Get_Choice = TRUE;
	Display_user_menu = TRUE;
	Display_admin_menu = TRUE;
}

void remote_login_menu()
{
	static u8 id = 0;
	if (users_Dispaly && loginAck_remote()!=TRUE)
	{
		displayAllUsersOnRemote();
		users_Dispaly = FALSE;
	}
	switch(loginAck_remote())
	{
		case FALSE:
			id = selectUserAndLogin_remote();
			break;
		case TRUE:
			switch(id)
			{
				case 1:
					remote_Menu_Admin();
					break;
				default:
					remote_Menu_User();
					break;
			}
			break;
		default:
			break;
	}
}

void remote_Menu_User()
{
	static u8 userChoice;
	
	if (Display_user_menu)
	{
		uart_sendString("User Menu:\n");
		uart_sendString("1. Lamps\n");
		uart_sendString("2. AC\n");
		uart_sendString("3. Logout\n");
		Display_user_menu = FALSE;
	}
	if (Get_Choice)
	{
		 userChoice = uart_receiveByte();
	}
	if (userChoice!=255)
	{
		Get_Choice = FALSE;
		switch (userChoice) {
			case '1':
			lamp_menu();
			break;
			case '2':
			AC_menu();
			break;
			case '3':
			logout_remote();
			Get_Choice = TRUE;
			users_Dispaly = TRUE;
			Display_user_menu = TRUE; 
			default:
			uart_sendString("Invalid choice. Please try again.\n");
			Get_Choice = TRUE;
			break;
		}
	}
}

void remote_Menu_Admin(void)
{
	static u8 adminChoice;
	if (Display_admin_menu)
	{
		uart_sendString("Admin Menu:\n");
		uart_sendString("1. Register User (Remote)\n");
		uart_sendString("2. Register User (Local)\n");
		uart_sendString("3. Lamps\n");
		uart_sendString("4. AC\n");
		uart_sendString("5. Control Door (Open/Close)\n");
		uart_sendString("6. Logout\n");
		Display_admin_menu = FALSE;
	}
	if (Get_Choice)
	{
		adminChoice = uart_receiveByte();
	}
	
	if (adminChoice!=255)
	{
		Get_Choice = FALSE;
		switch (adminChoice) {
			case '1':
			registerUserRemote();
			break;
			case '2':
			registerUserLocal();
			break;
			case '3':
			lamp_menu();
			break;
			case '4':
			AC_menu();
			break;
			case '5':
			doorService();
			break;
			case '6':
			logout_remote();
			users_Dispaly = TRUE;
			Get_Choice = TRUE;
			Display_admin_menu = TRUE;
			break;
			default:
			uart_sendString("Invalid choice. Please try again.\n");
			Get_Choice = TRUE;
			break;
		}
	}
}

void lamp_menu(void)
{
	static u8 Display_lamp_menu = TRUE;
	if (Display_lamp_menu)
	{
		uart_sendString("Lamp Menu\n");
		uart_sendString("Choose lamp number you want to turn on/off: \n");
		uart_sendString("1. Lamp1\n");
		uart_sendString("2. Lamp2\n");
		uart_sendString("3. Lamp3\n");
		uart_sendString("4. Lamp4\n");
		uart_sendString("5. Lamp5\n");
		uart_sendString("6. Dimmer\n");
		uart_sendString("7. Return\n");
		Display_lamp_menu = FALSE;
	}
	u8 lamp_choice = uart_receiveByte();
	if (lamp_choice!=255)
	{
		lamp_choice -= '0'; 
		switch (lamp_choice)
		{
			case 1:
				// Lamp1 ON/OFF (Toggle LED1 Status)
				lamp_toggle(LAMP1_ID);
				break;
			case 2:
				// LED2 ON/OFF (Toggle LED2 Status)
				lamp_toggle(LAMP2_ID);
				break;
			case 3:
				// LED3 ON/OFF (Toggle LED3 Status)
				lamp_toggle(LAMP3_ID);
				break;
			case 4:
				// LED4 ON/OFF (Toggle LED4 Status)
				lamp_toggle(LAMP4_ID);
				break;
			case 5:
				// LED5 ON/OFF (Toggle LED5 Status)
				lamp_toggle(LAMP5_ID);
				break;
			case 6:
				// DimmerLED ON/OFF (Toggle DimmerLED Status)
				Lamp_Service_Dim_Toggle();
				break;
			case 7:
				Get_Choice = TRUE;
				Display_user_menu = TRUE;
				Display_admin_menu = TRUE;
				break;
			default:
				uart_sendString("Invalid choice. Please try again.\n");
				break;
		}
		Display_lamp_menu = TRUE;
	}
}

void AC_menu(void)
{
	static u8 Display_AC_menu = TRUE;
	if (Display_AC_menu)
	{
		uart_sendString("AC Menu");
		AC ac_struct = airConditioner_Status();
		uart_sendString(ac_struct.AC_Status ? "[ON]" : "[OFF]");
		uart_sendString("Press (T) to turn ");
		uart_sendString(ac_struct.AC_Status ? "[OFF]" : "[ON]");
		uart_sendString("Press (E) to Exit\n");
		Display_AC_menu=FALSE;
	}
	
	u8 AC_choice = uart_receiveByte();
	if (AC_choice!=255)
	{
		switch(AC_choice)
		{
			case 'T':
			airConditioner_Toggle();
			break;
			case 'E':
			Get_Choice = TRUE;
			Display_user_menu = TRUE;
			Display_admin_menu = TRUE;
			break;
			default:
			uart_sendString("Wrong Input");
			break;
		}
	}

}

void remote_menu_Service(void)
{
// 	uart_sendString("System is starting in remote mode\n");
	remote_login_menu();
}
void remote_menu_init()
{
	remote_admin_register();
}