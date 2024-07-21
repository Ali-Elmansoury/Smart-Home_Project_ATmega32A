#ifndef REMOTEDB_H_
#define REMOTEDB_H_

#include "std_types.h"

#define DB_MAX_SIZE				(10)
#define UNAME_MAZ_SIZE			(16)
#define PASSWORD_MAX_SIZE		(9)

#define REGISTRATION_SUCCESS		(0)
#define ERROR_USER_ARRAY_FULL		(1)
#define ERROR_EEPROM_WRITE			(2)

// EEPROM addresses for storing user data
#define EEPROM_USER_COUNT_ADDR							(0x00)  
#define EEPROM_USER_DATA_ADDR_START						(0x01)
#define EEPROM_USER_DATA_ADDR_REMOTE		(EEPROM_USER_DATA_ADDR_START + 512)

typedef struct remoteDB
{
	u8 uname[UNAME_MAZ_SIZE];
	u8 password[PASSWORD_MAX_SIZE];
	u8 id;
}user_remote;

/*Function prototype*/

/*Function to add a new user and store in EEPROM*/
u8 addUserToEEPROM_remote(const u8 *username, const u8* password);
/*Function to delete a user from EEPROM by id number*/
//void deleteUserFromEEPROM_remote(u8 id);
/*Function to select a user by order number and verify the password*/
u8 selectUserAndLogin_remote();
/*Function to retrieve a user from EEPROM by order number*/
//void getUserFromEEPROM_remote(u8 id, user_remote* users);
/*Function to display users on Terminal*/
void displayAllUsersOnRemote();
/*Login acknowledgment*/
boolean loginAck_remote();
/*Logout*/
void logout_remote();
/*Initialization*/
void remoteDB_init();
/*Function to get an 8-digit password from the user securely*/
void getPassword_remote(u8* password);

#endif /* REMOTEDB_H_ */