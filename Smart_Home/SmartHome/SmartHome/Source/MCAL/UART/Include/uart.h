#ifndef UART_H_
#define UART_H_

#include "uart_reg.h"

#define URSEL_SET			(1<<7)

/*Data bit size*/
#define DATA_5BIT			(0<<1)
#define DATA_6BIT			(1<<1)
#define DATA_7BIT			(2<<1)
#define DATA_8BIT			(3<<1)

/*Stop bits*/
#define STOP_BIT1			(0<<3)
#define STOP_BIT2			(1<<3)

/*Parity set*/
#define PARITY_OFF			(0<<4)
#define PARITY_EVEN			(2<<4)
#define PARITY_ODD			(1<<4)

/*Baud rates*/
#define BAUD_RATE_9600		(103)
#define BAUD_RATE_115200	(8)


/*Functions prototype*/

/*UART initialization*/
void uart_init(u16 baud);
/*UART send data byte*/
void uart_sendByte(u8 byte);
/*UART send string*/
void uart_sendString(u8* str);
/*UART receive data byte*/
u8 uart_receiveByte(void);
/*UART receive string*/
void uart_receiveString(u8* receivedStr);

#endif /* UART_H_ */