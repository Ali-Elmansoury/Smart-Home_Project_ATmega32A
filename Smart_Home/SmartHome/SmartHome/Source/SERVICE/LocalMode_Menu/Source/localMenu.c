#include "std_types.h"
#include "lcd.h"
#include "ac.h"
#include "localMenu.h"
#include "keypad.h"
#include "lamp.h"
#include "Lamp_Dim_Service.h"
u8 number_of_active_devices = 0;



void local_Menu_Slector_Display(const u8 *menu_selector_position)
{
    switch (*menu_selector_position)
    {
    case 0:
        lcd_goTo(0, 0);
        lcd_displayChar('>');
        break;
    case 1:
        lcd_goTo(1, 0);
        lcd_displayChar('>');
        break;
    default:
        break;
    }
}

void local_Menu_Display(const u8 *menu_position)
{
    lcd_goTo(0,1);
    switch (*menu_position)
    {
    case 0:
        lcd_displayStr("LED ON/OFF");
        lcd_goTo(1, 1);
        lcd_displayStr("AC Control");
        break;
    case 1:
        lcd_displayStr("AC Control");
        lcd_goTo(1, 1);
        lcd_displayStr("Log-out");
        break;    
    default:
        break;
    }
}

void local_Menu_LED_Display(const u8 *menu_position)
{
   lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
    lcd_goTo(0,1);
    switch (*menu_position)
    {
    case 0:
		
        lcd_displayStr("Lamp1 [ON]");
		lcd_displayStr(Lamp_Service_state() ? "[ON]" : "[OFF]");
        lcd_goTo(1, 1);
        lcd_displayStr("Lamp2 [ON]");
        break;
    case 1:
        lcd_displayStr("Lamp2 [ON]");
        lcd_goTo(1, 1);
        lcd_displayStr("Lamp3 [ON]");
        break;
    case 2:
        lcd_displayStr("Lamp3 [ON]");
        lcd_goTo(1, 1);
        lcd_displayStr("Lamp4 [ON]");
        break;
    case 3:
        lcd_displayStr("Lamp4 [ON]");
        lcd_goTo(1, 1);
        lcd_displayStr("Lamp5 [ON]");
        break;
    case 4:
        lcd_displayStr("Lamp5 [ON]");
        lcd_goTo(1, 1);
        lcd_displayStr("DimLamp ");
		lcd_displayStr(Lamp_Service_state() ? "[ON]" : "[OFF]");
        break;
    case 5:
		lcd_displayStr("DimLamp ");
        lcd_displayStr(Lamp_Service_state() ? "[ON]" : "[OFF]");
        lcd_goTo(1, 1);
        lcd_displayStr("Return");
        break;    
    default:
        break;
    }
}

void local_Menu_AC_Display(const u8 *menu_position)
{
    lcd_sendCommand(LCD_CMD_CLEAR_DISPLAY);
    lcd_goTo(0,1);
	AC AC_Status = airConditioner_Status();
    switch (*menu_position)
    {
    case 0:
        lcd_displayStr("AC ");
        lcd_displayStr(AC_Status.AC_Status ? "[ON]" : "[OFF]");
        lcd_goTo(1, 1);
        lcd_displayStr("Run Temp:");
        lcd_displayNums(AC_Status.AC_Run_Temperature_threshold);
        lcd_displayChar('C');
        break;
    case 1:
        lcd_displayStr("Stop Temp:");
        lcd_displayNums(AC_Status.AC_Stop_Temperature_threshold);
        lcd_displayChar('C');
        lcd_goTo(1, 1);
        lcd_displayStr("Return");
        break;    
    default:
        break;
    }
}

void local_Menu_Move_Selector(int direction, u8 *menu_selector_position, u8 *menu_position, u8 max_menu_position)
{
    if (direction == MOVE_UP && *menu_position > 0)
    {
        (*menu_position)--;
    }
    else if (direction == MOVE_DOWN && *menu_position < max_menu_position)
    {
        (*menu_position)++;
    }
    else
    {
        *menu_position = direction == MOVE_UP ? max_menu_position : 0;
    }
}

void local_Menu(u8 *Last_key, u8 *current_menu)
{
    static u8 menu_position = 0;
    static u8 menu_selector_position = 0;
    static u8 max_menu_position = 1;

    local_Menu_Display(&menu_position);
    local_Menu_Slector_Display(&menu_selector_position);
    switch (*Last_key)
    {
    case KEY_A:
        local_Menu_Move_Selector(MOVE_UP,&menu_selector_position, &menu_position, max_menu_position);
        break;
    case KEY_B:
        local_Menu_Move_Selector(MOVE_DOWN,&menu_selector_position, &menu_position, max_menu_position);
        break;
    case KEY_D:
    switch (menu_position+menu_selector_position)
    {
    case LED_MENU:
        *current_menu = LED_MENU;   // Select LED Menu
        break;
    case AC_MENU:
        *current_menu = AC_MENU;    // Select AC Menu
        break;
    case 2:
        // Log-out
        break;
    default:
        break;
    }
    default:
        break;
    }
}

void local_Menu_AC(u8 *current_menu)
{
    static u8 menu_position = 0;
    static u8 menu_selector_position = 0;
    static u8 max_menu_position = 1;
	
	static u8 menu_key = 0;
	static boolean v_adj_flag = FALSE;
	
	AC AC_CFG;
	
	switch (v_adj_flag)
	{
		case FALSE:
			menu_key = keypad_readKey();
			break;
		default:
			break;
	}
	
    local_Menu_AC_Display(&menu_position);
    local_Menu_Slector_Display(&menu_selector_position);
    switch (menu_key)
    {
    case KEY_A:
        local_Menu_Move_Selector(MOVE_UP,&menu_selector_position, &menu_position, max_menu_position);
        break;
    case KEY_B:
        local_Menu_Move_Selector(MOVE_DOWN,&menu_selector_position, &menu_position, max_menu_position);
        break;
    case KEY_C:
        switch (menu_position+menu_selector_position)
        {
        case AC_ON_OFF:
            // AC1 ON/OFF
            airConditioner_Toggle();
            break;
        case AC_RUN_TEMP:
            // AC1 Run Temp
			v_adj_flag=TRUE;
			local_Menu_value_adj(&AC_CFG.AC_Run_Temperature_threshold,&v_adj_flag);
			if (v_adj_flag == FALSE)
				{airConditioner_Set_Config(&AC_CFG);}
			else{/* do nothing */;}
            break;
        case AC_STOP_TEMP:
            // AC1 Stop Temp
			v_adj_flag=TRUE;
			local_Menu_value_adj(&AC_CFG.AC_Stop_Temperature_threshold,&v_adj_flag);
			if (v_adj_flag == FALSE)
				{airConditioner_Set_Config(&AC_CFG);}
			else{/* do nothing */;}
			break;
            break;
        case AC_RETURN:
            // Return
            *current_menu = LOCAL_MENU;
            break;
        default:
            break;
        }
    default:
        break;
    }
}

void local_Menu_AC_Set_Temp(u8 temp, u8 AC_TEMP_MENU)
{
    AC ac_config;
    switch (AC_TEMP_MENU)
    {
    case AC_RUN_TEMP:
        ac_config.AC_Run_Temperature_threshold=temp;
        break;
    case AC_STOP_TEMP:
        ac_config.AC_Stop_Temperature_threshold=temp;
        break;
    default:
        break;
    }
    airConditioner_Set_Config(&ac_config);
}

void local_Menu_LED(u8 *current_menu)
{
    static u8 menu_position = 0;
    static u8 menu_selector_position = 0;
    static u8 max_menu_position = 5;
	
    u8 menu_key = keypad_readKey();
    
    local_Menu_LED_Display(&menu_position);
    local_Menu_Slector_Display(&menu_selector_position);
    switch (menu_key)
    {
    case 'A':
        local_Menu_Move_Selector(MOVE_UP,&menu_selector_position, &menu_position, max_menu_position);
        break;
    case 'B':
        local_Menu_Move_Selector(MOVE_DOWN,&menu_selector_position, &menu_position, max_menu_position);
        break;
    case 'C':
        switch (menu_position+menu_selector_position)
        {
        case 0:
            // LED1 ON/OFF (Toggle LED1 Status)
            break;
        case 1:
            // LED2 ON/OFF (Toggle LED2 Status)
            break;
        case 2:
            // LED3 ON/OFF (Toggle LED3 Status)
            break;
        case 3:
            // LED4 ON/OFF (Toggle LED4 Status)
            break;
        case 4:
            // LED5 ON/OFF (Toggle LED5 Status)
            break;
        case 5:
            // DimmerLED ON/OFF (Toggle DimmerLED Status)
            break;
        case 6:
            // Return
            *current_menu = LOCAL_MENU;
            break;
        default:
            break;
        }
    default:
        break;
    }
}

void local_Menu_value_adj(u8 *value, u8 *v_adj_flag)
{
    switch (keypad_readKey())
    {
    case KEY_A:
        *value++;
        break;
    case KEY_B:
        *value--;
        break;
    case KEY_C:
        *v_adj_flag = FALSE;
        break;
    
    default:
        break;
    }
}