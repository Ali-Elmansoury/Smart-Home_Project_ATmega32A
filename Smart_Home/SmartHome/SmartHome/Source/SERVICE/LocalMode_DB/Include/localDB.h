/*
 * localDB.h
 *
 * Created: 2/5/2024 8:34:48 PM
 *  Author: ali_e
 */ 


#ifndef LOCALDB_H_
#define LOCALDB_H_

#include "std_types.h"

#define DB_MAX_SIZE				(10)
#define UNAME_MAZ_SIZE			(16)

// EEPROM addresses for storing user data
#define EEPROM_START_ADDR 0
#define EEPROM_USER_COUNT_ADDR EEPROM_START_ADDR
#define EEPROM_USER_DATA_ADDR (EEPROM_START_ADDR + 1)

typedef struct localDB
{
	u8 uname[UNAME_MAZ_SIZE];
	u32 password;
	u8 id;
}user;

/*Function prototype*/

/*Function to add a new user and store in EEPROM*/
void addUserToEEPROM(const u8 username, const u32 password);
/*Function to delete a user from EEPROM by id number*/
void deleteUserFromEEPROM(u8 id);
/*Function to select a user by order number and verify the password*/
void selectUserAndLogin();
/*Function to retrieve a user from EEPROM by order number*/
void getUserFromEEPROM(u8 id, user* users);
/*Function to display users on LCD with scrolling*/
void displayUsersOnLCD(u8 startIndex, u8 endIndex);
/*Function to handle scrolling through users*/
void scrollUsersOnLCD();

#endif /* LOCALDB_H_ */