/*
 * TrafficLightApp_Program.c
 *
 * Created: 11/2/2022 10:36:10 PM
 *  Author: LENOVO
 */ 

#include "../Common/Macros.h"
#include "../ECUAL/LED Driver/Header/LED_Interface.h"
#include "../ECUAL/LED Driver/Header/LED_Private.h"
#include "../MCAL/TIMER0/Header/Timer0_Interface.h"
#include "../MCAL/EXTI/Header/EXTI_Interface.h"


static u8 Light_Status ;

void TrafficLight_APP()
{
	// At start pedestrian Red led will off and cars green led on
	LED_Void_ON(Group_B,PIN2);	
	
	/*
	Normal Mode CAR Traffic Light
	*/
	
	//Green LED	ON for 5 sec
	Light_Status = Green_Light ;		// Light status		GREEN
	LED_Void_ON(Group_A,PIN0);	
	Timer0_VoidStartNormalMode(5);
	// Green LED OFF
	LED_VOID_OFF(Group_A,PIN0);	
		
	// Yellow LEDs Blinking for 5 sec then yellow led off
	Light_Status = Yellow_Light ;		// Light status Yellow 
	LED_Void_Blink(Cars_Mode);			// Blink CARS leds
	LED_VOID_OFF(Group_A,PIN1);
	//LED_VOID_OFF(Group_B,PIN1);
	
	// Cars Red LED on
	Light_Status = Red_Light ;		// Light status	RED
	LED_Void_ON(Group_A,PIN2);	

	// 1 sec between pedestrian and cars LED
	Timer0_VoidStartNormalMode(5);
	// Cars Red LED OFF
	LED_VOID_OFF(Group_A,PIN2);


}



/* pedestrian Mode when push button is activated */
void INT0_ISR(void)
{

/*Check Cars LED's status */
	switch(Light_Status)
{
	
/*
If Car LED is green
*/
	case Green_Light:		
		/* Turn off CARS Green LED*/
		LED_VOID_OFF(Group_A,PIN0);	
		/* Turn off pedestrian Red LED*/
		LED_VOID_OFF(Group_B,PIN2);		
		
		/*Both	Yellow LEDs Blinking for 5 sec then yellow leds off */
		LED_Void_Blink(Pedestrian_Mode);
		LED_VOID_OFF(Group_B,PIN1);
		LED_VOID_OFF(Group_A,PIN1);
		
		/*Cars Red LED on */ 
		LED_Void_ON(Group_A,PIN2);
		// 1 sec between pedestrian and cars LED
		Timer0_VoidStartNormalMode(1);
		
		/*and pedestrian Green LED on for 5 sec*/
		LED_Void_ON(Group_B,PIN0);	
		Timer0_VoidStartNormalMode(5);
		
		/*Cars Red LED off */ 
		LED_VOID_OFF(Group_A,PIN2);		
		
		/*Both	Yellow LEDs Blinking for 5 sec then yellow LEDs off */
		LED_Void_Blink(Pedestrian_Mode);
		LED_VOID_OFF(Group_B,PIN1);
		LED_VOID_OFF(Group_A,PIN1);
		LED_VOID_OFF(Group_B,PIN0);		// pedestrian Green LED of
		
		/*pedestrian Red Led on */
		/* Turn on pedestrian Red LED*/
		LED_Void_ON(Group_B,PIN2);	
		
		/*To start normal mode again: from last interrupt */ 
		// Cars	Green LED On for 5 sec 
		LED_Void_ON(Group_A,PIN0);	
		Timer0_VoidStartNormalMode(1);	// at least 1 sec
		
		break;
	
	case Yellow_Light:
			//Turn off peds red led 
			LED_VOID_OFF(Group_B,PIN2);
			
			// Both Yellow led Blinking for 5 sec
			LED_Void_ON(Group_A, PIN1);
			LED_Void_ON(Group_B, PIN1);
			LED_Void_Blink(Pedestrian_Mode);
			// Turn off Yellow leds
			LED_VOID_OFF(Group_A,PIN1);
			LED_VOID_OFF(Group_B,PIN1);
			
			//Turn on cars Red Led
			LED_Void_ON(Group_A, PIN2);
			//Turn on peds green led for 5 sec
			LED_Void_ON(Group_B,PIN0);
			Timer0_VoidStartNormalMode(5);
			
			//Turn off cars red led 
			LED_VOID_OFF(Group_A,PIN2);
			//Yellow blink for 5 sec
			LED_Void_Blink(Pedestrian_Mode);
			LED_VOID_OFF(Group_A, PIN1);
			LED_VOID_OFF(Group_B, PIN1);
			//turn off peds green led
			LED_VOID_OFF(Group_B,PIN0);
			
			// turn on ped red led 
			LED_Void_ON(Group_B,PIN2);
			
			// turn on cars green led 
			LED_Void_ON(Group_A,PIN0);
			Timer0_VoidStartNormalMode(5);
			LED_VOID_OFF(Group_A,PIN0);
		break; 
		
	case Red_Light:
	
	/* CARS red LED will on */
	LED_Void_ON(Group_A,PIN2);
	
	/*pedestrian Green led on for 5 sec*/
	LED_Void_ON(Group_B,PIN0);
	Timer0_VoidStartNormalMode(5);
		
	
	break;
	

}

}



/* Testing All Drivers */
void TestDrivers()
{
	LED_VoidInit(Group_A,PIN0);
	
	// Turn Led On
	LED_Void_ON(Group_A, PIN0);
	// Turn LED off
	LED_VOID_OFF(Group_A, PIN0);
	
	// Timer0
	Timer0_VoidInitNomralMode();
	//Wait for 5 sec
	 Timer0_VoidStartNormalMode(5);
	//wait for 1 sec
 	Timer0_VoidStartNormalMode(1);
	
	LED_Void_Blink(Pedestrian_Mode);

	//Interrupt activated 
	//EXTI_VoidInitINT0();
	//EXTI_u8INT0_VoidCallbackFunction(LED_Void_ON(Group_A, PIN0));		//Callback function
	
	
}
