

#ifndef LOCALDB_H_
#define LOCALDB_H_

#include "std_types.h"

#define DB_MAX_SIZE				(10)
#define UNAME_MAZ_SIZE			(16)
#define PASSWORD_MAX_SIZE		(9)

#define REGISTRATION_SUCCESS		(0)
#define ERROR_USER_ARRAY_FULL		(1)
#define ERROR_EEPROM_WRITE			(2)

// EEPROM addresses for storing user data
#define EEPROM_USER_COUNT_ADDR_LOCAL					(0x12C)
#define EEPROM_USER_DATA_ADDR_START_LOCAL				(0x01)
#define EEPROM_USER_DATA_ADDR_LOCAL			(EEPROM_USER_DATA_ADDR_START_LOCAL)

typedef struct localDB
{
	u8 uname[UNAME_MAZ_SIZE];
	u8 password[PASSWORD_MAX_SIZE];
	u8 id;
}user_local;

/*Function prototype*/

/*Local DB Initialization*/
void localDB_init();
/*Function to add a new user and store in EEPROM*/
u8 addUserToEEPROM_local(const u8 *username, const u8* password);
/*Function to delete a user from EEPROM by id number*/
//void deleteUserFromEEPROM_local(u8 id);
/*Function to select a user by order number and verify the password*/
void selectUserAndLogin_local();
/*Function to retrieve a user from EEPROM by order number*/
//void getUserFromEEPROM_local(u8 id, user_local* users);
/*Function to display users on LCD with scrolling*/
void displayUsersOnLCD(u8 startIndex, u8 endIndex);
/*Function to handle scrolling through users*/
void scrollUsersOnLCD();
/*Login acknowledgment*/
boolean loginAck_local();
/*Logout*/
void logout_local();

#endif /* LOCALDB_H_ */