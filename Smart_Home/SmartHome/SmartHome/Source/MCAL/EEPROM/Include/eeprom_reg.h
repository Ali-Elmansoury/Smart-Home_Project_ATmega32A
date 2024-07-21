#ifndef EEPROM_REG_H_
#define EEPROM_REG_H_

#include "sfr.h"

/* Combine EEARL and EEARH */
#define EEPROM_EEAR_REG						_SFR_IO16(0x1E)

#define EEARL								_SFR_IO8(0x1E)
#define EEARH								_SFR_IO8(0x1F)

#define EEPROM_EEDR_REG						(*(volatile u8*)0x3D)
#define EEPROM_EECR_REG						(*(volatile u8*)0x3C)
#define EEPROM_READ_ENABLE_BIT_NO					(0)
#define EEPROM_WRITE_ENABLE_BIT_NO					(1)
#define EEPROM_MASTER_WRITE_ENABLE_BIT_NO			(2)
#define EEPROM_READY_INTERRUPT_ENABLE_BIT_NO		(3)

#endif /* EEPROM_REG_H_ */