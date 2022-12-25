/*
 * LED_Program.c
 *
 * Created: 11/2/2022 10:59:29 PM
 *  Author: LENOVO
 */ 

#include "../../../Common/Bitwise.h"
#include "../../../Common/Macros.h"
#include "../../../Common/Typedefs.h"
#include "../Header/LED_Interface.h"
#include "../Header/LED_Private.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/TIMER0/Header/Timer0_Interface.h"

/*
Initiation function for LED
*/
u8 LED_VoidInit(u8 LEDGroup_Name, u8 LEDPIN_Number)
{
	switch(LEDGroup_Name)
	{
		case Group_A:
		DIO_VoidSetPinDir(Group_A, LEDPIN_Number, Output);
		LED_ErrorStatus = LED_Ok ;
		break;
		case Group_B:
		DIO_VoidSetPinDir(Group_B, LEDPIN_Number, Output);
		LED_ErrorStatus = LED_Ok ;
		break;
		case Group_C:
		DIO_VoidSetPinDir(Group_C, LEDPIN_Number, Output);
		LED_ErrorStatus = LED_Ok ;
		break;
		case Group_D:
		DIO_VoidSetPinDir(Group_D, LEDPIN_Number, Output);
		LED_ErrorStatus = LED_Ok ;
		break;
		default:
		LED_ErrorStatus = LED_Fail ;
		break;
	}
	return LED_ErrorStatus ;
}

/*
Turn on LED
*/
u8 LED_Void_ON(u8 LEDGroup_Name, u8 LEDPIN_Number)
{
	switch(LEDGroup_Name)
	{
		case Group_A:
		DIO_VoidWritePin(Group_A,LEDPIN_Number, HIGH);
		LED_ErrorStatus = LED_Ok ;
		break;
		case Group_B:
		DIO_VoidWritePin(Group_B,LEDPIN_Number, HIGH);
		LED_ErrorStatus = LED_Ok ;
		break;
		case Group_C:
		DIO_VoidWritePin(Group_C,LEDPIN_Number, HIGH);
		LED_ErrorStatus = LED_Ok ;
		break;
		case Group_D:
		DIO_VoidWritePin(Group_D,LEDPIN_Number, HIGH);
		LED_ErrorStatus = LED_Ok ;
		break;
		default:
		LED_ErrorStatus = LED_Fail ;
		break;
	}
	
	return LED_ErrorStatus ;
	
}

/*
Turn of LED
*/
u8 LED_VOID_OFF(u8 LEDGroup_Name, u8 LEDPIN_Number)
{
				switch(LEDGroup_Name)
				{
					case Group_A:
					DIO_VoidWritePin(Group_A,LEDPIN_Number, LOW);
					LED_ErrorStatus = LED_Ok ;
					break;
					case Group_B:
					DIO_VoidWritePin(Group_B,LEDPIN_Number, LOW);
					LED_ErrorStatus = LED_Ok ;
					break;
					case Group_C:
					DIO_VoidWritePin(Group_C,LEDPIN_Number, LOW);
					LED_ErrorStatus = LED_Ok ;
					break;
					case Group_D:
					DIO_VoidWritePin(Group_D,LEDPIN_Number, LOW);
					LED_ErrorStatus = LED_Ok ;
					break;
					default:
					LED_ErrorStatus = LED_Fail;
					break;
				}
	return LED_ErrorStatus;
}

/*
Blinking Yellow Lights
*/

u8 LED_Void_Blink(u8 Mode_Type)
{
	u16 Counter_Value = 0 ;

switch(Mode_Type)
{
LED_ErrorStatus = LED_Fail ;
case Pedestrian_Mode:	
	while(Counter_Value != 5)
	{	
	DIO_VoidTogglePin(Group_A, PIN1);	// Yellow CARS
	DIO_VoidTogglePin(Group_B, PIN1);	// YELLOW Peds
	Timer0_VoidStartNormalMode(1);
	Counter_Value ++ ;
	LED_ErrorStatus = LED_Ok ;
	};
	
	Counter_Value = 0 ;
	break;
case Cars_Mode:
	while(Counter_Value != 5)
	{
		DIO_VoidTogglePin(Group_A, PIN1);	// Yellow CARS
		Timer0_VoidStartNormalMode(1);
		Counter_Value ++ ;
		LED_ErrorStatus = LED_Ok ;
	};
	Counter_Value = 0 ;
}

return LED_ErrorStatus ;

}