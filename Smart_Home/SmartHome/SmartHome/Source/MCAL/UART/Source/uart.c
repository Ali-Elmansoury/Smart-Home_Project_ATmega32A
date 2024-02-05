/*
 * uart.c
 *
 * Created: 11/6/2023 8:55:34 PM
 *  Author: ali_e
 */ 

#include "uart.h"
#include "bit_math.h"

void uart_init(u16 baud)
{
	/*Set baud rate*/
	UART_UBRRL_REG = baud;
	UART_UBRRH_REG = baud >> 8;
	
	/*Enable Tx, Rx*/
	SET_BIT(UART_UCSRB_REG,TX_ENABLE_BIT_NO);
	SET_BIT(UART_UCSRB_REG,RX_ENABLE_BIT_NO);
	
	/*Set data size=8, parity=even, stop=2*/
	UART_UCSRC_REG = URSEL_SET|DATA_8BIT|PARITY_EVEN|STOP_BIT2;
}

void uart_sendByte(u8 byte)
{
	/*Make sure UDRE is empty*/
	while(CHECK_BIT(UART_UCSRA_REG,UDR_EMPTY_FLAG)==0);
	
	/*Set UDR with data*/
	UART_UDR_REG = byte;
}

void uart_sendString(u8* str)
{
	while(*str != '\0')
	{
		uart_sendByte(*str);
		str++;
	}
}

u8 uart_receiveByte(void)
{
	/*Wait until byte is received in UDR*/
	while(CHECK_BIT(UART_UCSRA_REG,UDR_RECEIVE_COMPLETE_FLAG)==0);
	
	/*Return the received byte*/
	return UART_UDR_REG;
}

void uart_receiveString(u8* receivedStr)
{
	// Receive the string
	while (*receivedStr != '\0')
	{
		*receivedStr = uart_receiveByte();
		receivedStr++;
	}
}