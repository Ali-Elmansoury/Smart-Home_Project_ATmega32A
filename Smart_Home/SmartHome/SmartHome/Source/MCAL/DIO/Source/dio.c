#include "dio.h"
#include "bit_math.h"

void dio_setPinDirection(u8 portId, u8 pinId, u8 direction)
{
	switch (portId)
	{
		case PORTA_ID:
		//DDRA
			if (direction == OUTPUT) 
			{
				SET_BIT(DIO_DDRA_REG,pinId);
			}
			else if (direction == INPUT)
			{
				CLEAR_BIT(DIO_DDRA_REG,pinId);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		
		case PORTB_ID:
		//DDRB
			if (direction == OUTPUT)
			{
				SET_BIT(DIO_DDRB_REG,pinId);
			}
			else if (direction == INPUT)
			{
				CLEAR_BIT(DIO_DDRB_REG,pinId);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		
		case PORTC_ID:
		//DDRC
			if (direction == OUTPUT)
			{
				SET_BIT(DIO_DDRC_REG,pinId);
			}
			else if (direction == INPUT)
			{
				CLEAR_BIT(DIO_DDRC_REG,pinId);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		
		case PORTD_ID:
		//DDRD
			if (direction == OUTPUT)
			{
				SET_BIT(DIO_DDRD_REG,pinId);
			}
			else if (direction == INPUT)
			{
				CLEAR_BIT(DIO_DDRD_REG,pinId);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
	}
}

void dio_writeChannel(u8 portId, u8 pinId, u8 level)
{
	switch (portId)
	{
		case PORTA_ID:
		//PORTA
			if (level == HIGH)
			{
				SET_BIT(DIO_PORTA_REG,pinId);
			}
			else if (level == LOW)
			{
				CLEAR_BIT(DIO_PORTA_REG,pinId);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		
		case PORTB_ID:
		//PORTB
			if (level == HIGH)
			{
				SET_BIT(DIO_PORTB_REG,pinId);
			}
			else if (level == LOW)
			{
				CLEAR_BIT(DIO_PORTB_REG,pinId);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		
		case PORTC_ID:
		//PORTC
			if (level == HIGH)
			{
				SET_BIT(DIO_PORTC_REG,pinId);
			}
			else if (level == LOW)
			{
				CLEAR_BIT(DIO_PORTC_REG,pinId);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		
		case PORTD_ID:
		//PORTD
			if (level == HIGH)
			{
				SET_BIT(DIO_PORTD_REG,pinId);
			}
			else if (level == LOW)
			{
				CLEAR_BIT(DIO_PORTD_REG,pinId);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
	}
}

void dio_toggleChannel(u8 portId, u8 pinId)
{
	switch (portId)
	{
		case PORTA_ID:
		//PORTA
			TOGGLE_BIT(DIO_PORTA_REG,pinId);
		break;
		
		case PORTB_ID:
		//PORTB
			TOGGLE_BIT(DIO_PORTB_REG,pinId);
		break;
		
		case PORTC_ID:
		//PORTC
			TOGGLE_BIT(DIO_PORTC_REG,pinId);
		break;
		
		case PORTD_ID:
		//PORTD
			TOGGLE_BIT(DIO_PORTD_REG,pinId);
		break;
	}
}

u8 dio_readChannel(u8 portId, u8 pinId)
{
	u8 pinRead = LOW;
	switch (portId)
	{
		case PORTA_ID:
			pinRead = CHECK_BIT(DIO_PINA_REG,pinId);
		break;
		
		case PORTB_ID:
			pinRead = CHECK_BIT(DIO_PINB_REG,pinId);
		break;
		
		case PORTC_ID:
			pinRead = CHECK_BIT(DIO_PINC_REG,pinId);
		break;
		
		case PORTD_ID:
			pinRead = CHECK_BIT(DIO_PIND_REG,pinId);
		break;
	}
	return pinRead;
}

void dio_enablePullUp(u8 portId, u8 pinId)
{
	switch (portId)
	{
		case PORTA_ID:
			SET_BIT(DIO_PORTA_REG,pinId);
		break;
		
		case PORTB_ID:
			SET_BIT(DIO_PORTB_REG,pinId);
		break;
		
		case PORTC_ID:
			SET_BIT(DIO_PORTC_REG,pinId);
		break;
		
		case PORTD_ID:
			SET_BIT(DIO_PORTD_REG,pinId);
		break;
	}
}