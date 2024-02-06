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

// Function to get an 8-digit password from the user securely
void getPassword_local(char* password, u8 maxLength) 
{
	u8 index = 0;

	lcd_displayStr("Enter Password:");

	// Simulate getting secure user input for the password
	while (index < maxLength - 1) 
	{
		u8 key = keypad_readKey();

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

				// Display asterisks for entered characters
				for (u8 i = 0; i < index; ++i) {
					lcd_displayChar("*");
				}
			}
		} 
		else if (key >= '0' && key <= '9') 
		{  // Numeric keys
			password[index] = key;
			index++;
			lcd_displayChar("*");
		}
		// Add more conditions for other keys as needed
	}
	password[index] = '\0';  // Null-terminate the password
}

void addUserToEEPROM_local(const u8 *username, const u32 password) 
{
	u8 userCount;
	EEPROM_read_block(&userCount, (const void*)EEPROM_USER_COUNT_ADDR_LOCAL, sizeof(userCount));

	if (userCount < 11) {  // Assuming a maximum of 10 users
		strncpy(localUsers->uname, username, sizeof(localUsers->uname) - 1);
		localUsers->password = password;
		localUsers->id = userCount + 1;

		EEPROM_write_block(&localUsers, (void*)(EEPROM_USER_DATA_ADDR_LOCAL + userCount * sizeof(user_local)), sizeof(user_local));

		userCount++;
		EEPROM_write_block(&userCount, (void*)EEPROM_USER_COUNT_ADDR_LOCAL, sizeof(userCount));
		} else {
		// Handle error: User array is full
	}
}

void getUserFromEEPROM_local(u8 id, user_local* users)
{
	if (id >= 1 && id <= 10) {  // Assuming a maximum of 10 users
		EEPROM_read_block(users, (const void*)(EEPROM_USER_DATA_ADDR_LOCAL + (id - 1) * sizeof(user_local)), sizeof(user_local));
	}
}

void deleteUserFromEEPROM_local(u8 id)
{
	if (id >= 1 && id <= 10) {  // Assuming a maximum of 10 users
		u8 userCount;
		EEPROM_read_block(&userCount, (const void*)EEPROM_USER_COUNT_ADDR_LOCAL, sizeof(userCount));

		if (userCount > 0) {
			// Shift remaining users to fill the gap
			for (int i = id - 1; i < userCount - 1; ++i) {
				getUserFromEEPROM_local(i + 2, &localUsers);  // Shift next user to the current position
				EEPROM_write_block(&localUsers, (void*)(EEPROM_USER_DATA_ADDR_LOCAL + i * sizeof(user_local)), sizeof(user_local));
			}

			// Decrement user count
			userCount--;
			EEPROM_write_block(&userCount, (void*)EEPROM_USER_COUNT_ADDR_LOCAL, sizeof(userCount));
		}
	}
}

void displayUsersOnLCD(u8 startIndex, u8 endIndex) 
{
	lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
	for (u8 i = startIndex; i < endIndex && i < 10; ++i) {  // Assuming a maximum of 10 users
		getUserFromEEPROM_local(i + 1, &localUsers);

		char displayText[50];
		snprintf(displayText, sizeof(displayText), "User: %s, ID: %d", localUsers->uname, localUsers->id);
		lcd_displayStr(displayText);
	}
}

void scrollUsersOnLCD()
{
	u8 startIndex = 0;
	u8 endIndex = 2;  // Display two users at a time

	while (1) {
		displayUsersOnLCD(startIndex, endIndex);

		char key = keypad_readKey();  // Assume keypad_readKey() returns the pressed key

		if (key == 'A') {  // Scroll up
			if (startIndex >= 2) {
				startIndex -= 2;
				endIndex -= 2;
			}
			} else if (key == 'B') {  // Scroll down
			if (endIndex < 11) {  // Assuming a maximum of 10 users
				startIndex += 2;
				endIndex += 2;
			}
		}

		// Add a delay to avoid rapid scrolling due to continuous key press
		_delay_ms(200);
	}
}


void selectUserAndLogin_local() 
{
	u8 selectedID;
	lcd_displayStr("Enter User ID:");

	selectedID = keypad_readKey();

	if (selectedID >= 1 && selectedID <= 10) 
	{  // Assuming a maximum of 10 users
		getUserFromEEPROM_local(selectedID, &localUsers);

		char enteredPassword[20];
		lcd_displayStr("Enter Password:");

		getPassword_local(enteredPassword, sizeof(enteredPassword));

		if (strcmp(enteredPassword, localUsers->password) == 0) 
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

boolean loginAck_local()
{
	return login_flag_local;
}

void logout_local()
{
	login_flag_local = FALSE;
}