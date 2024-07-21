


#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "dio.h"

/*LCD commands*/
#define LCD_CMD_CLEAR_DISPLAY					(0x01)
#define LCD_CMD_CURSOR_OFF						(0x0C)
#define LCD_CMD_CURSOR_ON						(0x0F)
#define LCD_CMD_4BIT_MODE						(0x28)
#define LCD_CMD_8BIT_MODE						(0x38)
#define LCD_CMD_ON								(0x0F)
#define LCD_CMD_CURSOR_UNDERLINE				(0x0E)
#define LCD_CMD_CURSOR_SHIFT_LEFT				(0x10)
#define LCD_CMD_CURSOR_SHIFT_RIGHT				(0x14)
#define LCD_CMD_CURSOR_INCREMENT				(0x06)
#define LCD_CMD_CGRAM_START_ADDRESS				(0x40)
#define LCD_CMD_DDRAM_START_ADDRESS				(0x80)

/*Rows*/
#define row0				(0)
#define row1				(1)

/*LCD pins*/
#define LCD_DATA_PORT		PORTC_ID
#define LCD_CMD_PORT		PORTC_ID
#define LCD_RS				(PIN6_ID)
#define LCD_RW				(PIN5_ID)
#define LCD_EN				(PIN4_ID)
#define LCD_D4				(PIN0_ID)
#define LCD_D5				(PIN1_ID)
#define LCD_D6				(PIN2_ID)
#define LCD_D7				(PIN3_ID)


/*Functions prototype*/

/*LCD initialization*/
void lcd_init(void);
/*Send commands to LCD*/
void lcd_sendCommand(u8 cmd);
/*Send data to LCD*/
void lcd_writeData(u8 data);
/*Set cursor to specific row & column*/
void lcd_goTo(u8 row, u8 col);
/*Display character*/
void lcd_displayChar(u8 character);
/*Display string*/
void lcd_displayStr(u8 str[]);
/*Display numbers*/
void lcd_displayNums(u16 num);
/*Display custom chars*/
void lcd_writeCustomChar(void);

#endif /* LCD_H_ */