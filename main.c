

#include "App/App_Interface.h"
#include "Common/Macros.h"
#include "Common/Typedefs.h"
#include "Common/Bitwise.h"
#include "ECUAL/LED Driver/Header/LED_Interface.h"
#include "MCAL/TIMER0/Header/Timer0_Interface.h"
#include "MCAL/EXTI/Header/EXTI_Interface.h"



int main(void)
{	
	//TestDrivers();
	
	
	/* Initiations section */
	
	/* CAR'S LED */
	LED_VoidInit(Group_A,PIN0);
	LED_VoidInit(Group_A,PIN1);
	LED_VoidInit(Group_A,PIN2);
	
	/* Pedestrian  LEDs */
	LED_VoidInit(Group_B,PIN0);
	LED_VoidInit(Group_B,PIN1);
	LED_VoidInit(Group_B,PIN2);
	
	/* Timer0 */
	Timer0_VoidInitNomralMode();
		
	/* Interrupts */
	EXTI_VoidInitINT0();
	EXTI_u8INT0_VoidCallbackFunction(INT0_ISR);		//Callback function

	
    /* Replace with your application code */
	
	
    while (1) 
    {
		

	TrafficLight_APP();
		


    }
}

