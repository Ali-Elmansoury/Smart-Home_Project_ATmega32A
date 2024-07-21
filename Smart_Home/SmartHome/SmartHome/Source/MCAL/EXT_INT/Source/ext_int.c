#include "ext_int.h"
#include "bit_math.h"
#include <avr/interrupt.h>
#include <stdio.h>

void (*int0ClbkPtr)(void) = NULL;
void (*int1ClbkPtr)(void) = NULL;
void (*int2ClbkPtr)(void) = NULL;

void extINT_enable(u8 interruptId)
{
	switch (interruptId)
	{
		case EXT_INT0_ID:
			SET_BIT(EXT_INT_GICR_REG,GICR_EXT_INT0_EN_BIT);
		break;
		
		case EXT_INT1_ID:
			SET_BIT(EXT_INT_GICR_REG,GICR_EXT_INT1_EN_BIT);
		break;
		
		case EXT_INT2_ID:
			SET_BIT(EXT_INT_GICR_REG,GICR_EXT_INT2_EN_BIT);
		break;
	}
}

void extINT_disable(u8 interruptId)
{
	switch (interruptId)
	{
		case EXT_INT0_ID:
			CLEAR_BIT(EXT_INT_GICR_REG,GICR_EXT_INT0_EN_BIT);
		break;
		
		case EXT_INT1_ID:
			CLEAR_BIT(EXT_INT_GICR_REG,GICR_EXT_INT1_EN_BIT);
		break;
		
		case EXT_INT2_ID:
			CLEAR_BIT(EXT_INT_GICR_REG,GICR_EXT_INT2_EN_BIT);
		break;
	}
}

void extINT_setSenseControl(u8 interruptId, u8 senseControl)
{
	switch (interruptId)
	{
		case EXT_INT0_ID:
			if (senseControl == LOW_LEVEL)
			{
				CLEAR_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC00_BIT_NO);
				CLEAR_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC01_BIT_NO);
			}
			else if (senseControl == ANY_LOGICAL_CHANGE)
			{
				SET_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC00_BIT_NO);
				CLEAR_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC01_BIT_NO);
			}
			else if (senseControl == FALLING_EDGE)
			{
				CLEAR_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC00_BIT_NO);
				SET_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC01_BIT_NO);
			}
			else if (senseControl == RISING_EDGE)
			{
				SET_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC00_BIT_NO);
				SET_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC01_BIT_NO);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		
		case EXT_INT1_ID:
			if (senseControl == LOW_LEVEL)
			{
				CLEAR_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC10_BIT_NO);
				CLEAR_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC11_BIT_NO);
			}
			else if (senseControl == ANY_LOGICAL_CHANGE)
			{
				SET_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC10_BIT_NO);
				CLEAR_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC11_BIT_NO);
			}
			else if (senseControl == FALLING_EDGE)
			{
				CLEAR_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC10_BIT_NO);
				SET_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC11_BIT_NO);
			}
			else if (senseControl == RISING_EDGE)
			{
				SET_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC10_BIT_NO);
				SET_BIT(EXT_INT_MCUCR_REG,MCUCR_ISC11_BIT_NO);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		
		case EXT_INT2_ID:
			if (senseControl == FALLING_EDGE)
			{
				CLEAR_BIT(EXT_INT_MCUCSR_REG,MCUCSR_ISC2_BIT_NO);
			}
			else if (senseControl == RISING_EDGE)
			{
				SET_BIT(EXT_INT_MCUCSR_REG,MCUCSR_ISC2_BIT_NO);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
	}
}

void extINT_setCallBack(u8 interruptId, void(*fptr)(void))
{
	switch (interruptId)
	{
		case EXT_INT0_ID:
			int0ClbkPtr = fptr;
		break;
		
		case EXT_INT1_ID:
			int1ClbkPtr = fptr;
		break;
		
		case EXT_INT2_ID:
			int2ClbkPtr = fptr;
		break;
	}
}

ISR(INT0_vect)
{
	if (int0ClbkPtr != NULL)
	{
		int0ClbkPtr();
	}
}

ISR(INT1_vect)
{
	if (int1ClbkPtr != NULL)
	{
		int1ClbkPtr();
	}
}

ISR(INT2_vect)
{
	if (int2ClbkPtr != NULL)
	{
		int2ClbkPtr();
	}
}