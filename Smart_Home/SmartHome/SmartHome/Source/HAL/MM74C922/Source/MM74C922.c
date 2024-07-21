#include "MM74C922.h"
#include "std_types.h"
#include "dio.h"
#include "stdio.h"
#include "ext_int.h"
#include "MM74C922_Cfg_Priv.h"
#include "gie.h"
#include "localMenu.h"

volatile u8 Last_key = NO_DATA;

static u8 Table[16] = {KEY_HASH, 0, KEY_Asterisk, KEY_D,
                       1, 2, 3, KEY_C,
                       4, 5, 6, KEY_B,
                       7, 8, 9, KEY_A};

void MM74C922_Init()
{
	for (u8 i = PIN_S_ID; i <= PIN_E_ID; i++)
    {
		dio_setPinDirection(PORT_ID, i, INPUT);
    }
	extINT_setCallBack(EXT_INT0_ID, &MM74C922_Decode);
	extINT_setSenseControl(EXT_INT0_ID,FALLING_EDGE);
	extINT_enable(EXT_INT0_ID);
	gie_enableAllInterrupts();
	
}

void MM74C922_Decode()
{
    u8 temp = 0;
    for (u8 i = 0; i < 4; i++)
    {
        temp |= (dio_readChannel(PORT_ID, PIN_S_ID + i) << i);
    }
    Last_key = Table[temp];
	local_menu_Idle_Reset();
}

u8 MM74C922_GetKey(void)
{
	u8 temp = Last_key;
	Last_key = NO_DATA;
    return temp;
}