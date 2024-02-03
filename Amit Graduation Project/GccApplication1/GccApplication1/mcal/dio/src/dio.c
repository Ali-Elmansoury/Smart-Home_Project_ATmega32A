/*
* dio.c
*
* Created: 27-Sep-23 7:16:19 PM
*  Author: pc
*/

/*
0->PORTA
1->PORTB
2->PORTC
3->PORTD
---------------
0->PIN0
1->PIN1
2->PIN2
3->PIN3
4->PIN4
5->PIN5
6->PIN6
7->PIN7

*/
#include "std_types.h"
#include "dio.h"
#include "bit_math.h"

void dio_setPinDirection(u8 portId, u8 pinId, u8 direction){
	switch(portId){
		case PORTA_ID:
		//DDRA
		if(direction==OUTPUT){
			SET_BIT(DIO_DDRA_REG, pinId);
		}
		else{
			CLEAR_BIT(DIO_DDRA_REG, pinId);
		}
		
		break;
		
		case PORTB_ID:
		//DDRB
		if(direction==OUTPUT){
			SET_BIT(DIO_DDRB_REG, pinId);
		}
		else{
			CLEAR_BIT(DIO_DDRB_REG, pinId);
		}
		break;
		
		case PORTC_ID:
		//DDRC
		if(direction==OUTPUT){
			SET_BIT(DIO_DDRC_REG, pinId);
		}
		else{
			CLEAR_BIT(DIO_DDRC_REG, pinId);
		}
		break;
		
		case PORTD_ID:
		//DDRD
		if(direction==OUTPUT){
			SET_BIT(DIO_DDRD_REG, pinId);
		}
		else{
			CLEAR_BIT(DIO_DDRD_REG, pinId);
		}
		break;
		
		
		
		
	}
}

void dio_writeChannel(u8 portId, u8 pinId, u8 level){
	switch(portId){
		case PORTA_ID:
		
		if(level==HIGH){
			SET_BIT(DIO_PORTA_REG, pinId);
		}
		
		else{
			CLEAR_BIT(DIO_PORTA_REG, pinId);
		}
		break;
		
		case PORTB_ID:
		
		if(level==HIGH){
			SET_BIT(DIO_PORTB_REG, pinId);
		}
		
		else{
			CLEAR_BIT(DIO_PORTB_REG, pinId);
		}
		
		break;
		
		case PORTC_ID:
		
		if(level==HIGH){
			SET_BIT(DIO_PORTC_REG, pinId);
		}
		
		else{
			CLEAR_BIT(DIO_PORTC_REG, pinId);
		}
		
		break;
		
		case PORTD_ID:
		
		if(level==HIGH){
			SET_BIT(DIO_PORTD_REG, pinId);
		}
		
		else{
			CLEAR_BIT(DIO_PORTD_REG, pinId);
		}
		break;
	}
	
}

u8 dio_readChannel(u8 portId, u8 pinId){
	u8 loc_pinRead= LOW;

	switch(portId){
		
		case PORTA_ID:
		loc_pinRead = CHECK_BIT(DIO_PINA_REG,pinId);
		break;
		case PORTB_ID:
		loc_pinRead = CHECK_BIT(DIO_PINB_REG,pinId);
		break;
		case PORTC_ID:
		loc_pinRead = CHECK_BIT(DIO_PINC_REG,pinId);
		break;
		case PORTD_ID:
		loc_pinRead = CHECK_BIT(DIO_PIND_REG,pinId);
		break;
		
		
	}
	return loc_pinRead;
}

void dio_flipChannel(u8 portId, u8 pinId){
	switch(portId){
		case PORTA_ID:
		FLIP_BIT(DIO_PORTA_REG,pinId);
		break;
		
		case PORTB_ID:
		FLIP_BIT(DIO_PORTB_REG,pinId);
		break;
		
		case PORTC_ID:
		FLIP_BIT(DIO_PORTC_REG,pinId);
		break;
		
		case PORTD_ID:
		FLIP_BIT(DIO_PORTD_REG,pinId);
		break;
	}
}

void dio_enablePullUp(u8 portId, u8 pinId){
	switch(portId){
		case PORTA_ID:
		SET_BIT(DIO_PORTA_REG, pinId);
		break;
		
		case PORTB_ID:
		SET_BIT(DIO_PORTB_REG, pinId);
		break;
		
		case PORTC_ID:
		SET_BIT(DIO_PORTC_REG, pinId);
		break;
		
		case PORTD_ID:
		SET_BIT(DIO_PORTD_REG, pinId);
		break;
	}
}
