/*
 * eeprom.h
 *
 * Created: 2/4/2024 6:28:35 PM
 *  Author: ali_e
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "std_types.h"
#include "eeprom_reg.h"

/*Function prototype*/

/*EEPROM Write Data*/
void EEPROM_write(u16 address, u8 data);
/*EEPROM Read Data*/
u8 EEPROM_read(u16 address);

#endif /* EEPROM_H_ */