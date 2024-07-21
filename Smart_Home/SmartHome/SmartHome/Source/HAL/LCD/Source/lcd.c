

#define F_CPU	16000000UL
#include "LCD.h"
#include "bit_math.h"
#include "lcd_cfg.h"
#include <util/delay.h>
#include <stdio.h>

extern u8 customChar[NO_CUSTOM_CHAR][NO_CUSTOM_CHAR_BYTES];

void lcd_init(void)
{
	/*Set LCD control lines direction --> output*/
	dio_setPinDirection(LCD_CMD_PORT,LCD_RS,OUTPUT);
	dio_setPinDirection(LCD_CMD_PORT,LCD_RW,OUTPUT);
	dio_setPinDirection(LCD_CMD_PORT,LCD_EN,OUTPUT);
	
	/*Set LCD data lines direction --> output*/
	dio_setPinDirection(LCD_DATA_PORT,LCD_D4,OUTPUT);
	dio_setPinDirection(LCD_DATA_PORT,LCD_D5,OUTPUT);
	dio_setPinDirection(LCD_DATA_PORT,LCD_D6,OUTPUT);
	dio_setPinDirection(LCD_DATA_PORT,LCD_D7,OUTPUT);
	
	/*Always write to LCD*/
	dio_writeChannel(LCD_CMD_PORT,LCD_RW,LOW);
	
	/*Initialization by instructions*/
	lcd_writeData(0x00);
	_delay_ms(30);
	lcd_sendCommand(0x03);
	_delay_ms(5);
	lcd_sendCommand(0x03);
	_delay_us(150);
	lcd_sendCommand(0x03);
	lcd_sendCommand(0x02);
	lcd_sendCommand(0x02);
	lcd_sendCommand(LCD_CMD_4BIT_MODE);
	lcd_sendCommand(0x08);
	lcd_sendCommand(0x00);
	lcd_sendCommand(0x0C);
	lcd_sendCommand(0x00);
	lcd_sendCommand(LCD_CMD_CURSOR_INCREMENT);
	
	/*Write custom chars*/
	//lcd_writeCustomChar();
	//lcd_sendCommand(LCD_CMD_DDRAM_START_ADDRESS);
}

static void enablePulse(void)
{
	/*Enable pulse*/
	_delay_ms(1);
	dio_writeChannel(LCD_CMD_PORT,LCD_EN,HIGH);
	_delay_ms(1);
	dio_writeChannel(LCD_CMD_PORT,LCD_EN,LOW);
	_delay_ms(1);
}

void lcd_sendCommand(u8 cmd)
{
	/*MSB first*/
	/*Set RS--> 0 (Command) */
	dio_writeChannel(LCD_CMD_PORT,LCD_RS,LOW);
	
	/*Set MSB data part*/
	dio_writeChannel(LCD_DATA_PORT,LCD_D4,CHECK_BIT(cmd,4));
	dio_writeChannel(LCD_DATA_PORT,LCD_D5,CHECK_BIT(cmd,5));
	dio_writeChannel(LCD_DATA_PORT,LCD_D6,CHECK_BIT(cmd,6));
	dio_writeChannel(LCD_DATA_PORT,LCD_D7,CHECK_BIT(cmd,7));
	
	enablePulse();
	
	/*Set LSB data part*/
	dio_writeChannel(LCD_DATA_PORT,LCD_D4,CHECK_BIT(cmd,0));
	dio_writeChannel(LCD_DATA_PORT,LCD_D5,CHECK_BIT(cmd,1));
	dio_writeChannel(LCD_DATA_PORT,LCD_D6,CHECK_BIT(cmd,2));
	dio_writeChannel(LCD_DATA_PORT,LCD_D7,CHECK_BIT(cmd,3));
	
	enablePulse();
}

void lcd_writeData(u8 data)
{
	/*MSB first*/
	/*Set RS--> 1 (Data) */
	dio_writeChannel(LCD_CMD_PORT,LCD_RS,HIGH);
	
	/*Set MSB data part*/
	dio_writeChannel(LCD_DATA_PORT,LCD_D4,CHECK_BIT(data,4));
	dio_writeChannel(LCD_DATA_PORT,LCD_D5,CHECK_BIT(data,5));
	dio_writeChannel(LCD_DATA_PORT,LCD_D6,CHECK_BIT(data,6));
	dio_writeChannel(LCD_DATA_PORT,LCD_D7,CHECK_BIT(data,7));
	
	enablePulse();
	
	/*Set LSB data part*/
	dio_writeChannel(LCD_DATA_PORT,LCD_D4,CHECK_BIT(data,0));
	dio_writeChannel(LCD_DATA_PORT,LCD_D5,CHECK_BIT(data,1));
	dio_writeChannel(LCD_DATA_PORT,LCD_D6,CHECK_BIT(data,2));
	dio_writeChannel(LCD_DATA_PORT,LCD_D7,CHECK_BIT(data,3));
	
	enablePulse();
}

void lcd_goTo(u8 row, u8 col)
{
	switch (row)
	{
		case row0:
			lcd_sendCommand(0x80 + col);
		break;
		
		case row1:
			lcd_sendCommand(0xC0 + col);		//0xC0 = 0x80 + 0x40
		break;
	}
}

void lcd_displayChar(u8 character)
{
	lcd_writeData(character);
}

void lcd_displayStr(u8 str[])
{
	u8 i=0;
	while (str[i] != '\0')
	{
		lcd_displayChar(str[i]);
		i++;
	}
}

void lcd_displayNums(u16 num)
{
	u8 buffer[33];
	sprintf(buffer,"%d",num);
	lcd_displayStr(buffer);
}

void lcd_writeCustomChar(void)
{
	u8 i,j;
	for (i = 0; i < NO_CUSTOM_CHAR; i++)
	{
		lcd_sendCommand(LCD_CMD_CGRAM_START_ADDRESS + (i*8));
		for (j = 0; j<NO_CUSTOM_CHAR_BYTES; j++)
		{
			lcd_writeData(customChar[i][j]);
		}
	}
}