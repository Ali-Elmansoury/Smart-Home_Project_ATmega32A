/*
 * localDB.c
 *
 * Created: 2/5/2024 8:35:03 PM
 *  Author: ali_e
 */ 

#define F_CPU 16000000UL
#include <stdio.h>
#include <util/delay.h>
#include "localDB.h"
#include "lcd.h"
#include "keypad.h"
#include "eeprom.h"
#include "string.h"

user_local localUsers[DB_MAX_SIZE];
boolean login_flag_local = FALSE;
u8 userCount_local = 0;

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
			getUserFromEEPROM_local(i, &localUsers);
			
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
		else if (key == 'C')
		{  // Backspace
			if (index > 0)
			{
				index--;
				password[index] = '\0';
				lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);  // Clear the LCD
				lcd_displayStr("Enter Password:");
			}
		}
		else if (key >= '0' && key <= '9')
		{  // Numeric keys
			password[index] = key;
			index++;
		}
		// Add more conditions for other keys as needed
	}
	password[index] = '\0';  // Null-terminate the password
}

void writeUserToEEPROM_local(user_local *user, u8 userId) {
	u16 startAddress = EEPROM_USER_DATA_ADDR_LOCAL + (userId * 26);
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

		writeUserToEEPROM_local(&localUsers,userCount_local);

		userCount_local++;
		EEPROM_write(EEPROM_USER_COUNT_ADDR_LOCAL, userCount_local);
		return REGISTRATION_SUCCESS;
		} else {
		// Handle error: User array is full
		return ERROR_USER_ARRAY_FULL;
	}
}


void getUserFromEEPROM_local(u8 id, user_local* user)
{
	if (id >= 0 && id <= 9) {  // Assuming a maximum of 10 users
		readUserFromEEPROM_local(user,id);
	}
}


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
	for (u8 i = startIndex; i < endIndex && i < userCount_local; i++) {  // Assuming a maximum of 10 users
		char displayText[50];
		snprintf(displayText, sizeof(displayText), "User: %s,ID: %d", localUsers[i].uname, localUsers[i].id);
		lcd_displayStr(displayText);
	}
	lcd_goTo(1,0);
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
	u8 selectedID;
	lcd_displayStr("Enter User ID:");

	selectedID = keypad_readKey();

	if (selectedID >= 1 && selectedID <= 10)
	{  // Assuming a maximum of 10 users
		char enteredPassword[9];
		lcd_displayStr("Enter Password:");

		getPassword_local(enteredPassword,9);

		if (strcmp(enteredPassword, localUsers[selectedID-1].password) == 0)
		{
			lcd_displayStr("Login Successful");
			login_flag_local = TRUE;
		}
		else
		{
			lcd_displayStr("Error: Incorrect Password");
		}
	}
	else
	{
		lcd_displayStr("Error: Invalid User Order");
	}
}


void scrollUsersOnLCD()
{
	u8 startIndex = 0;
	u8 endIndex = 2;  // Display two users at a time

	displayUsersOnLCD(startIndex, endIndex);

	u8 key = MM74C922_GetKey();  // Assume keypad_readKey() returns the pressed key

	if (key == 'A') {  // Scroll up
		if (startIndex >= 2) {
			startIndex -= 2;
			endIndex -= 2;
		}
		} else if (key == 'B') {  // Scroll down
		if (endIndex < 11) {  // Assuming a maximum of 10 users
			startIndex += 2;
			endIndex += 2;
			if (endIndex == 10)
			{
				return;
			}
		}
	}
	// Add a delay to avoid rapid scrolling due to continuous key press
	_delay_ms(200);

	selectUserAndLogin_local();
}

boolean loginAck_local()
{
	return login_flag_local;
}

void logout_local()
{
	login_flag_local = FALSE;
}