#include "eeprom.h"
#include "avr/io.h"
void EEPROM_write(u16 address, u8 data)
{
	/* Wait for completion of previous write */
	while(EEPROM_EECR_REG & (1<<EEPROM_WRITE_ENABLE_BIT_NO));
	/* Set up address and data registers */
	EEAR = address;
	EEPROM_EEDR_REG = data;
	/* Write logical one to EEMWE */
	EEPROM_EECR_REG |= (1<<EEPROM_MASTER_WRITE_ENABLE_BIT_NO);
	/* Start EEPROM write by setting EEWE */
	EEPROM_EECR_REG |= (1<<EEPROM_WRITE_ENABLE_BIT_NO);
}

u8 EEPROM_read(u16 address)
{
	/* Wait for completion of previous write */
	while(EEPROM_EECR_REG & (1<<EEPROM_WRITE_ENABLE_BIT_NO));
	/* Set up address register */
	EEAR = address;
	/* Start EEPROM read by writing EERE */
	EEPROM_EECR_REG |= (1<<EEPROM_READ_ENABLE_BIT_NO);
	/* Return data from data register */
	return EEPROM_EEDR_REG;
}

void EEPROM_write_block(u8 *str, u16 start_byte_adr,u8 n_byte)
{
	u16 end_byte_adr = start_byte_adr + n_byte;
	while(start_byte_adr < end_byte_adr) /* Loop For Counts And Copy */
	{
		EEPROM_write(start_byte_adr, str[0]);
		str++;
		start_byte_adr++;
	}
}

void EEPROM_read_block(u8 *str, u16 start_byte_adr, u8 n_byte)
{
	u16 end_byte_adr = start_byte_adr + n_byte;
	while (start_byte_adr < end_byte_adr) /* Loop For Counts And Copy */
	{
		*str = EEPROM_read(start_byte_adr);
		str++;
		start_byte_adr++;
	}
}

