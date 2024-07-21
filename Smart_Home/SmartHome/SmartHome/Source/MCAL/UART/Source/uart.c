#include "uart.h"
#include "bit_math.h"
#include "avr/interrupt.h"
#include "gie.h"

volatile u8 rx_data;
volatile boolean new_rx_data = FALSE;

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
	gie_enableAllInterrupts();
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
	if (new_rx_data) {
		new_rx_data = FALSE;
		return rx_data;
	}
	else
	{
		return 255;
	}
	//u8 temp = rx_data;
	//rx_data = 255;
	//return temp;
}

ISR(USART_RXC_vect)
{
	rx_data = UART_UDR_REG;
	new_rx_data = TRUE; // Set flag to indicate new data
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
	u8 i = 0, RX_Byte=255;
	RX_Byte = uart_receiveByte();
	while(RX_Byte != '#')
	{
		if (RX_Byte != 255)
		{
			receivedStr[i] = RX_Byte;
			i++;
		}
		RX_Byte = uart_receiveByte();
	}
	receivedStr[i] = '\0';
}