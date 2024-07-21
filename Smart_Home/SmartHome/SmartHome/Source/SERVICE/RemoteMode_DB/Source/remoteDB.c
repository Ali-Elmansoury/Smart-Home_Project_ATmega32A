#define F_CPU 16000000UL
#include <stdio.h>
#include <util/delay.h>
#include "remoteDB.h"
#include "lcd.h"
#include "uart.h"
#include "eeprom.h"
#include "string.h"

user_remote remoteUsers[DB_MAX_SIZE];
boolean login_flag_remote = FALSE;
u8 userCount = 0;

void readUserFromEEPROM(user_remote *user,u8 id);

void remoteDB_init()
{
	if (EEPROM_read(EEPROM_USER_COUNT_ADDR) == 0xFF)
	{
		EEPROM_write(EEPROM_USER_COUNT_ADDR, userCount);
	}
	else
	{
		userCount = EEPROM_read(EEPROM_USER_COUNT_ADDR);
		for (u8 id = 0; id < userCount; id++) {
			readUserFromEEPROM(&remoteUsers[id],id);
			
		}
		
	}
	uart_init(BAUD_RATE_9600);
}

// Function to get an 8-digit password from the user securely
void getPassword_remote(u8* password)
{
	uart_sendString("Enter Password:");

	// Simulate getting user input for the password
	uart_receiveString(password);

	uart_sendString("\n");  // Move to the next line after password entry
}

void writeUserToEEPROM(user_remote *user) {
	u16 startAddress = EEPROM_USER_DATA_ADDR_REMOTE + (userCount * 26);
	EEPROM_write_block(user->uname, startAddress, 16);
	startAddress+=16;
	EEPROM_write_block(user->password,startAddress, 9);
	startAddress+=9;
	EEPROM_write(startAddress,user->id);
}

void readUserFromEEPROM(user_remote *user, u8 id) {
	u16 startAddress = EEPROM_USER_DATA_ADDR_REMOTE + (id * 26);
	EEPROM_read_block(user->uname, startAddress, 16);
	startAddress+=16;
	EEPROM_read_block(user->password, startAddress, 9);
	startAddress+=9;
	user->id = EEPROM_read(startAddress);
}


u8 addUserToEEPROM_remote(const u8 *username, const u8* password)
{

	if (userCount < 10) {  // Assuming a maximum of 10 users
		strcpy(remoteUsers[userCount].uname, username);
		strcpy(remoteUsers[userCount].password, password);
		remoteUsers[userCount].id = userCount + 1;

		writeUserToEEPROM(&remoteUsers[userCount]);

		userCount++;
		EEPROM_write(EEPROM_USER_COUNT_ADDR, userCount);
		return REGISTRATION_SUCCESS;
		} else {
		// Handle error: User array is full
		return ERROR_USER_ARRAY_FULL;
	}
}

// void getUserFromEEPROM_remote(u8 id, user_remote* users)
// {
// 	if (id >= 0 && id <= 9) {  // Assuming a maximum of 10 users
// 		readUserFromEEPROM(users, id);
// 	}
// }

//void deleteUserFromEEPROM_remote(u8 id)
//{
	//if (id >= 1 && id <= 10) {  // Assuming a maximum of 10 users
		//u8 userCount;
		//EEPROM_read_block(&userCount, (const void*)EEPROM_USER_COUNT_ADDR_REMOTE, sizeof(userCount));
//
		//if (userCount > 0) {
			//// Shift remaining users to fill the gap
			//for (int i = id - 1; i < userCount - 1; ++i) {
				//getUserFromEEPROM_remote(i + 2, &remoteUsers);  // Shift next user to the current position
				//EEPROM_write_block(&remoteUsers, (void*)(EEPROM_USER_DATA_ADDR_REMOTE + i * sizeof(user_remote)), sizeof(user_remote));
			//}
//
			//// Decrement user count
			//userCount--;
			//EEPROM_write_block(&userCount, (void*)EEPROM_USER_COUNT_ADDR_REMOTE, sizeof(userCount));
		//}
	//}
//}

void displayAllUsersOnRemote() {
	uart_sendString("Displaying all users:\n");

	for (u8 i = 0; i < userCount; i++) {
		char displayText[50];
		snprintf(displayText, sizeof(displayText), "Remote: User: %s, ID: %d\n", remoteUsers[i].uname, remoteUsers[i].id);
		uart_sendString(displayText);
	}
}


u8 selectUserAndLogin_remote()
{
    u8 selectedID;
	static u8 Display_Flag = TRUE;
	if (Display_Flag)
	{
		uart_sendString("Enter User ID:");
		Display_Flag = FALSE;
	}
    selectedID = uart_receiveByte();

    

    if (selectedID != 255) // Check if the received byte is not 255
    {
		uart_sendString("\n");
		selectedID -= '0';
        if (selectedID >= 1 && selectedID <= 10)
        { // Assuming a maximum of 10 users

            char enteredPassword[9];
            getPassword_remote(enteredPassword);

            if (strcmp(enteredPassword, remoteUsers[selectedID - 1].password) == 0)
            {
                uart_sendString("Login Successful\n");

                login_flag_remote = TRUE;
            }
            else
            {
                uart_sendString("Error: Incorrect Password\n");
            }
        }
        else
        {
            uart_sendString("Error: Invalid User ID\n");
        }
		Display_Flag = TRUE;
    }
    return selectedID;
}


boolean loginAck_remote()
{
	return login_flag_remote;
}

void logout_remote()
{
	login_flag_remote = FALSE;
}