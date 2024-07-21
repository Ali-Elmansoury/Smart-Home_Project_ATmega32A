 

#define F_CPU 16000000UL
#include <stdio.h>
#include <util/delay.h>
#include "localDB.h"
#include "lcd.h"
#include "keypad.h"
#include "eeprom.h"
#include "string.h"
#include "Stop.h"

user_local localUsers[DB_MAX_SIZE];
boolean login_flag_local = FALSE;
u8 userCount_local = 0;

void localDB_init();
void getPassword_local(u8* password, u8 maxLength);
void writeUserToEEPROM_local(user_local *user);
void readUserFromEEPROM_local(user_local *user, u8 userId);
u8 addUserToEEPROM_local(const u8 *username, const u8* password);
void displayUsersOnLCD(u8 startIndex, u8 endIndex);
void selectUserAndLogin_local();
void scrollUsersOnLCD();
boolean loginAck_local();
void logout_local();



void localDB_init()
{
	if (EEPROM_read(EEPROM_USER_COUNT_ADDR_LOCAL) == 0xFF)
	{
		EEPROM_write(EEPROM_USER_COUNT_ADDR_LOCAL, userCount_local);
	}
	else
	{
		userCount_local = EEPROM_read(EEPROM_USER_COUNT_ADDR_LOCAL);
		for (u8 i = 0; i < userCount_local; i++) {
			readUserFromEEPROM_local(&localUsers[i], i);
			
		}
		
	}
}

// Function to get an 8-digit password from the user securely
void getPassword_local(u8* password, u8 maxLength)
{
	u8 index = 0;

	lcd_displayStr("Enter Password:");

	// Simulate getting user input for the password
	while (index < maxLength - 1)
	{
		u8 key = MM74C922_GetKey();

		// Check for Enter key
		if (key == 'D')
		{
			// Check if the password is exactly 8 digits
			if (index == 8)
			{
				lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
				break;
			}
			else
			{
				// Password length is incorrect, clear and ask again
				lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
				lcd_displayStr("Invalid Password");
				_delay_ms(1000);  // Wait for 1 second
				lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
				lcd_displayStr("Enter Password:");
				index = 0;
				continue;
			}
		}
		else if (key == 'C' && index > 0)
		{  // Backspace
			index--;
			password[index] = '\0';
			lcd_goTo(1,index);
			lcd_displayChar(' ');
			lcd_goTo(1,index);
		}
		else if (key >= 0 && key <= 9)
		{  // Numeric keys
			key += '0';
			lcd_goTo(1,index);
			lcd_displayChar('*');
			password[index] = key;
			index++;
		}
		// Add more conditions for other keys as needed
	}
	password[index] = '\0';  // Null-terminate the password
}

void writeUserToEEPROM_local(user_local *user) {
	u16 startAddress = EEPROM_USER_DATA_ADDR_LOCAL + (userCount_local * 26);
	EEPROM_write_block(user->uname, startAddress, 16);
	startAddress+=16;
	EEPROM_write_block(user->password,startAddress, 9);
	startAddress+=9;
	EEPROM_write(startAddress,user->id);
}

void readUserFromEEPROM_local(user_local *user, u8 userId) {
	u16 startAddress = EEPROM_USER_DATA_ADDR_LOCAL + (userId * 26);
	EEPROM_read_block(user->uname, startAddress, 16);
	startAddress+=16;
	EEPROM_read_block(user->password, startAddress, 9);
	startAddress+=9;
	user->id = EEPROM_read(startAddress);
}

u8 addUserToEEPROM_local(const u8 *username, const u8* password)
{
	if (userCount_local < 10) {  // Assuming a maximum of 10 users
		strcpy(&localUsers[userCount_local].uname, username);
		strcpy(&localUsers[userCount_local].password, password);
		localUsers[userCount_local].id = userCount_local + 1;

		writeUserToEEPROM_local(&localUsers[userCount_local]);

		userCount_local++;
		EEPROM_write(EEPROM_USER_COUNT_ADDR_LOCAL, userCount_local);
		return REGISTRATION_SUCCESS;
		} else {
		// Handle error: User array is full
		return ERROR_USER_ARRAY_FULL;
	}
}


// void getUserFromEEPROM_local(u8 id, user_local* user)
// {
// 	if (id >= 0 && id <= 9) {  // Assuming a maximum of 10 users

// 		readUserFromEEPROM_local(user,id);

// 	}
// }


//void deleteUserFromEEPROM_local(u8 id)
//{
	//if (id >= 1 && id <= 10) {  // Assuming a maximum of 10 users
		//u8 userCount;
		//EEPROM_read_block(&userCount, (const void*)EEPROM_USER_COUNT_ADDR_LOCAL, sizeof(userCount));
//
		//if (userCount > 0) {
			//// Shift remaining users to fill the gap
			//for (int i = id - 1; i < userCount - 1; ++i) {
				//getUserFromEEPROM_local(i + 2, &localUsers);  // Shift next user to the current position
				//EEPROM_write_block(&localUsers, (void*)(EEPROM_USER_DATA_ADDR_LOCAL + i * sizeof(user_local)), sizeof(user_local));
			//}
//
			//// Decrement user count
			//userCount--;
			//EEPROM_write_block(&userCount, (void*)EEPROM_USER_COUNT_ADDR_LOCAL, sizeof(userCount));
		//}
	//}
//}

void displayUsersOnLCD(u8 startIndex, u8 endIndex)
{
	lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
	if (userCount_local == 0)
	{lcd_displayStr("No Local Users");
	}
	for (u8 i = startIndex; i < endIndex && i < userCount_local; i++) {  // Assuming a maximum of 10 users
		char displayText[50];
		snprintf(displayText, sizeof(displayText), "%s,ID: %d", localUsers[i].uname, localUsers[i].id);
		lcd_displayStr(displayText);
		lcd_goTo(1,0);
	}
}


//void scrollUsersOnLCD()
//{
	//u8 startIndex = 0;
	//u8 endIndex = 2;  // Display two users at a time
//
	//while (1) {
		//displayUsersOnLCD(startIndex, endIndex);
//
		//char key = keypad_readKey();  // Assume keypad_readKey() returns the pressed key
//
		//if (key == 'A') {  // Scroll up
			//if (startIndex >= 2) {
				//startIndex -= 2;
				//endIndex -= 2;
			//}
			//} else if (key == 'B') {  // Scroll down
			//if (endIndex < 11) {  // Assuming a maximum of 10 users
				//startIndex += 2;
				//endIndex += 2;
			//}
		//}
//
		//// Add a delay to avoid rapid scrolling due to continuous key press
		//_delay_ms(200);
	//}
//}


void selectUserAndLogin_local()
{
	static boolean Show_Display_ID = TRUE;
	static u8 selectedID = NO_DATA;
	static u8 Try = 0;
	if (Show_Display_ID)
	{
		lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
		lcd_displayStr("Enter User ID:");
		Show_Display_ID = FALSE;
	}

	selectedID = MM74C922_GetKey();

	if (selectedID >= 1 && selectedID <= 10)
	{  // Assuming a maximum of 10 users
		char enteredPassword[9];
		lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);

		getPassword_local(enteredPassword,9);

		if (strcmp(enteredPassword, localUsers[selectedID-1].password) == 0)
		{
			lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
			lcd_displayStr("Login Successful");
			login_flag_local = TRUE;
			selectedID = NO_DATA;
			Show_Display_ID = TRUE;
			_delay_ms(1000);
			lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
		}
		else
		{
			lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
			lcd_displayStr("Error: Incorrect");
			Try++;
			lcd_goTo(1,3);
			lcd_displayStr("Password");
			if (Try==3)
			{
				Set_System_Stop();
				lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
				lcd_displayStr("<<Error>>");
				lcd_goTo(1,0);
				lcd_displayStr("<System  Halted>");
				return;
			}
			_delay_ms(1000);
			lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
			selectedID = NO_DATA;
			Show_Display_ID = TRUE;
		}
	}
	else if (selectedID == NO_DATA)
	{
		return;
	}
	else
	{
		lcd_displayStr("Error: Invalid User Order");
	}
}


void scrollUsersOnLCD()
{
	static u8 startIndex = 0;
	static u8 endIndex = 2;  // Display two users at a time
	static u8 key = NO_DATA;
	static boolean login = FALSE;
	static boolean Show_Data = TRUE;
	if (Show_Data)
	{
		lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
		displayUsersOnLCD(startIndex, endIndex);
		Show_Data = FALSE;
	}
	if (!login)
	{
		key = MM74C922_GetKey();
	}
	
	switch(key)
	{
		case KEY_A:
			if (startIndex >= 2)
			{
				startIndex -= 2;
				endIndex -= 2;
				Show_Data = TRUE;
			}
			break;
		case KEY_B:
			if (endIndex < 11)
			{  // Assuming a maximum of 10 users
				startIndex += 2;
				endIndex += 2;
				Show_Data = TRUE;
				if (endIndex == 10)
				{
					break;
				}
			}
			break;
		case KEY_C:
			selectUserAndLogin_local();
			login = TRUE;
			startIndex = 0;
			endIndex = 2;
			if (login_flag_local)
			{Show_Data = TRUE;
			 login = FALSE;}
			break;
		default:
			break;
			
	}	
}

boolean loginAck_local()
{
	return login_flag_local;
}

void logout_local()
{
	login_flag_local = FALSE;
}