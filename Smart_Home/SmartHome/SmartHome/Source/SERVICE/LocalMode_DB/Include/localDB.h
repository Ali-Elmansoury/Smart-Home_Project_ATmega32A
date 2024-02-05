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

typedef struct localDB
{
	u8 uname[UNAME_MAZ_SIZE];
	u32 password;
}user;

user localUsers[DB_MAX_SIZE];

/*Function prototype*/

/*Add user*/
boolean registerUser(u8* uname, u32 pass);
/*Delete user*/
boolean deleteUser(u8* uname);
/**/ 

#endif /* LOCALDB_H_ */