
#include "keypad.h"
#include "dio.h"

void keypad_init(void)
{
	MM74C922_Init(PORTB_ID,PIN4_ID,PIN7_ID);
}

u8 keypad_readKey(void)
{
	u8 key = 0;
	key = MM74C922_GetKey();
	return key;
}
