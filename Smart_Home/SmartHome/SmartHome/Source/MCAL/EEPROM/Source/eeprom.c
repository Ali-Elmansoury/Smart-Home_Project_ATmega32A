/*
 * eeprom.c
 *
 * Created: 2/4/2024 6:28:46 PM
 *  Author: ali_e
 */ 

#include "eeprom.h"

void EEPROM_write(u16 address, u8 data)
{
	/* Wait for completion of previous write */
	while(EEPROM_EECR_REG & (1<<EEPROM_WRITE_ENABLE_BIT_NO));
	/* Set up address and data registers */
	EEPROM_EEAR_REG = address;
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
	EEPROM_EEAR_REG = address;
	/* Start EEPROM read by writing EERE */
	EEPROM_EECR_REG |= (1<<EEPROM_READ_ENABLE_BIT_NO);
	/* Return data from data register */
	return EEPROM_EEDR_REG;
}