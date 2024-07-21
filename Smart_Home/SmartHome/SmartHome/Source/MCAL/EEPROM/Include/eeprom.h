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
void EEPROM_write_block(u8 *str, u16 start_byte_adr,u8 n_byte);
/*EEPROM Read Block*/
void EEPROM_read_block(u8 *str, u16 start_byte_adr, u8 n_byte);

#endif /* EEPROM_H_ */