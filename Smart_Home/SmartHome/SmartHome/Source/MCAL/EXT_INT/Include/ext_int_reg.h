/*
 * ext_int_reg.h
 *
 * Created: 10/11/2023 7:45:17 PM
 *  Author: ali_e
 */ 


#ifndef EXT_INT_REG_H_
#define EXT_INT_REG_H_

#define	EXT_INT_GICR_REG		(*(volatile u8*)0x5B)
#define	EXT_INT_MCUCR_REG		(*(volatile u8*)0x55)
#define	EXT_INT_MCUCSR_REG		(*(volatile u8*)0x54)

#endif /* EXT_INT_REG_H_ */