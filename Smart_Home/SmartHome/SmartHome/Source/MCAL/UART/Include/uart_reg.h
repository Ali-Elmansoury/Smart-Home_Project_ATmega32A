#ifndef UART_REG_H_
#define UART_REG_H_

#include "std_types.h"

#define UART_UDR_REG				(*(volatile u8*)0x2C)
#define UART_UCSRA_REG				(*(volatile u8*)0x2B)
#define UART_UCSRB_REG				(*(volatile u8*)0x2A)
#define UART_UCSRC_REG				(*(volatile u8*)0x40)
#define UART_UBRRL_REG				(*(volatile u8*)0x29)
#define UART_UBRRH_REG				(*(volatile u8*)0x40)

#define TX_ENABLE_BIT_NO			(3)
#define RX_ENABLE_BIT_NO			(4)
#define UDR_EMPTY_FLAG				(5)
#define UDR_RECEIVE_COMPLETE_FLAG	(7)

#define RX_COMPLETE_INTERRUPT_ENABLE_BIT_NOT		(7)

#endif /* UART_REG_H_ */