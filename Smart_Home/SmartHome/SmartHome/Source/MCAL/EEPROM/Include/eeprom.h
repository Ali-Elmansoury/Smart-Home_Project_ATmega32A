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
/*EEPROM Write Block*/
void EEPROM_write_block(const void *src, void *dst, u8 size);
/*EEPROM Read Block*/
void EEPROM_read_block(void *dst, const void *src, u8 size);

#endif /* EEPROM_H_ */