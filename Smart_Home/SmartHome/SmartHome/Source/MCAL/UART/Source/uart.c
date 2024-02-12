/*
 * uart.c
 *
 * Created: 11/6/2023 8:55:34 PM
 *  Author: ali_e
 */ 

#include "uart.h"
#include "bit_math.h"
#include "avr/interrupt.h"

volatile u8 rx_data;

void uart_init(u16 baud)
{
	/*Set baud rate*/
	UART_UBRRL_REG = baud;
	UART_UBRRH_REG = baud >> 8;
	
	/*Enable Tx, Rx*/
	SET_BIT(UART_UCSRB_REG,TX_ENABLE_BIT_NO);
	SET_BIT(UART_UCSRB_REG,RX_ENABLE_BIT_NO);
	
	/*Enable RXCIE Receive Complete Interrupt Enable*/
	SET_BIT(UART_UCSRB_REG,RX_COMPLETE_INTERRUPT_ENABLE_BIT_NOT);
	
	/*Set data size=8, parity=off, stop=1*/
	UART_UCSRC_REG = URSEL_SET|DATA_8BIT|PARITY_OFF|STOP_BIT1;
}

void uart_sendByte(u8 byte)
{
	/*Make sure UDRE is empty*/
	while(CHECK_BIT(UART_UCSRA_REG,UDR_EMPTY_FLAG)==0);
	
	/*Set UDR with data*/
	UART_UDR_REG = byte;
}

void uart_sendString(u8 *str)
{
	while(*str != '\0')
	{
		uart_sendByte(*str);
		str++;
	}
}

u8 uart_receiveByte(void)
{
	u8 temp = rx_data;
	rx_data = 255;
	return temp;
}

ISR(USART_RXC_vect)
{
	rx_data = UDR;
}

// void uart_receiveString(u8 *receivedStr)
// {
// 	// Receive the string
// 	while (*receivedStr != '\0')
// 	{
// 		*receivedStr = uart_receiveByte();
// 		receivedStr++;
// 	}
// }
void uart_receiveString(u8 *receivedStr)
{
	u8 i = 0;
	receivedStr[i] = uart_receiveByte();
	if (receivedStr[i] == 255)
	{
		return 255;
	}
	else
	{
		while(receivedStr[i] != '#')
		{
			i++;
			receivedStr[i] = uart_receiveByte();
		}
		receivedStr[i] = '\0';
	}
	
}