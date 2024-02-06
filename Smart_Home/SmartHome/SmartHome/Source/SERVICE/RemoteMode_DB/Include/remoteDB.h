/*
 * remoteDB.h
 *
 * Created: 2/6/2024 7:11:08 PM
 *  Author: ali_e
 */ 


#ifndef REMOTEDB_H_
#define REMOTEDB_H_

#include "std_types.h"

#define DB_MAX_SIZE				(10)
#define UNAME_MAZ_SIZE			(16)

// EEPROM addresses for storing user data
#define EEPROM_START_ADDR 211
#define EEPROM_USER_COUNT_ADDR EEPROM_START_ADDR
#define EEPROM_USER_DATA_ADDR (EEPROM_START_ADDR + 1)

typedef struct remoteDB
{
	u8 uname[UNAME_MAZ_SIZE];
	u32 password;
	u8 id;
}user;

/*Function prototype*/

/*Function to add a new user and store in EEPROM*/
void addUserToEEPROM_remote(const u8 *username, const u32 password);
/*Function to delete a user from EEPROM by id number*/
void deleteUserFromEEPROM_remote(u8 id);
/*Function to select a user by order number and verify the password*/
void selectUserAndLogin_remote();
/*Function to retrieve a user from EEPROM by order number*/
void getUserFromEEPROM_remote(u8 id, user* users);
/*Function to display users on Terminal*/
void displayAllUsersOnRemote();
/*Login acknowledgment*/
boolean loginAck();
/*Logout*/
void logout();
/*Initialization*/
void remoteDB_init();

#endif /* REMOTEDB_H_ */