/*
 * sfr.h
 *
 * Created: 2/4/2024 3:42:33 AM
 *  Author: ali_e
 */ 


#ifndef SFR_H_
#define SFR_H_

#define _SFR_IO8(addr) _MMIO_BYTE((addr))
#define _MMIO_BYTE(mem_addr) (*(volatile u8*)(mem_addr))

#define _SFR_IO16(addr) _MMIO_WORD((addr))
#define _MMIO_WORD(mem_addr) (*(volatile u8*)(mem_addr))

#endif /* SFR_H_ */