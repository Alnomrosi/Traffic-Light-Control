/*
 * DIO_Program.c
 *
 * Created: 11/2/2022 10:54:45 PM
 *  Author: LENOVO
 */ 
#include "../../../Common/Bitwise.h"
#include "../../../Common/Macros.h"
#include "../../../Common/Typedefs.h"
#include "../Header/DIO_Interface.h"
#include "../Header/DIO_Register.h"


void DIO_VoidSetPinDir(u8 Group_Name, u8 Pin_Number, u8 Pin_State)
{
		if (Pin_State == Output)
		{
			switch(Group_Name)
			{
				case Group_A:
				SET_Bit(DIO_DDRA,Pin_Number);
				break;
				case Group_B:
				SET_Bit(DIO_DDRB,Pin_Number);
				break;
				case Group_C:
				SET_Bit(DIO_DDRC,Pin_Number);
				break;
				case Group_D:
				SET_Bit(DIO_DDRD,Pin_Number);
				break;
			}
		}
		else if (Pin_State == Input)
		{
			switch(Group_Name)
			{
				case Group_A:
				CLR_Bit(DIO_DDRA,Pin_Number);
				break;
				case Group_B:
				CLR_Bit(DIO_DDRB,Pin_Number);
				break;
				case Group_C:
				CLR_Bit(DIO_DDRC,Pin_Number);
				break;
				case Group_D:
				CLR_Bit(DIO_DDRD,Pin_Number);
				break;
			}
			
		}
	
}

void DIO_VoidWritePin(u8 Group_Name, u8 Pin_Number, u8 Pin_State)
{
	if (Pin_State == HIGH)
	{
		switch(Group_Name)
		{
			case Group_A:
			SET_Bit(DIO_PORTA,Pin_Number);
			break;
			case Group_B:
			SET_Bit(DIO_PORTB,Pin_Number);
			break;
			case Group_C:
			SET_Bit(DIO_PORTC,Pin_Number);
			break;
			case Group_D:
			SET_Bit(DIO_PORTD,Pin_Number);
			break;
		}
	}
	else if (Pin_State == LOW)
	{
		switch(Group_Name)
		{
			case Group_A:
			CLR_Bit(DIO_PORTA,Pin_Number);
			break;
			case Group_B:
			CLR_Bit(DIO_PORTB,Pin_Number);
			break;
			case Group_C:
			CLR_Bit(DIO_PORTC,Pin_Number);
			break;
			case Group_D:
			CLR_Bit(DIO_PORTD,Pin_Number);
			break;
		}
		
	}
	
}

u8 u8_ReadPin(u8 Group_Name, u8 Pin_Number)
{
	u8  Return_Value = 0;
	switch(Group_Name)
	{
		case Group_A:
		Return_Value = GET_Bit(DIO_PINA,Pin_Number);
		break;
		
		case Group_B:
		Return_Value = GET_Bit(DIO_PINB,Pin_Number);
		break;
		
		case Group_C:
		Return_Value = GET_Bit(DIO_PINC,Pin_Number);
		break;
		
		case Group_D:
		Return_Value = GET_Bit(DIO_PIND,Pin_Number);
		break;
	}
	
	return Return_Value ;
	
}

void DIO_VoidTogglePin(u8 Group_Name, u8 Pin_Number)
{
		switch(Group_Name)
		{
			case Group_A:	TOG_Bit(DIO_PORTA,Pin_Number); break;
			case Group_B:	TOG_Bit(DIO_PORTB,Pin_Number); break;
			case Group_C:	TOG_Bit(DIO_PORTC,Pin_Number); break;
			case Group_D:	TOG_Bit(DIO_PORTD,Pin_Number); break;
		}
	
}