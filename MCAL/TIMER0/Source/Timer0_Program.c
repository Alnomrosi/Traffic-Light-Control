/*
 * Timer0_Program.c
 *
 * Created: 11/2/2022 11:52:08 PM
 *  Author: LENOVO
 */ 


#include "../../../Common/Bitwise.h"
#include "../../../Common/Macros.h"
#include "../../../Common/Typedefs.h"

#include "../Header/Timer0_Interface.h"
#include "../Header/Timer0_Register.h"
#include "../Header/Timer0_Private.h"

void Timer0_VoidInitNomralMode()
{
	// Normal Mode
	Timer0_TCCR0 = 0x00 ;
	// Set Initial Value
	Timer0_TCNT0 = 0x00 ;
	
}

void Timer0_VoidStartNormalMode(u16 Time_Delay)
{
	
	
	if(Time_Delay == 5)			// 5 Seconed Timer
	{
	 Number_overFlow = 305; 
	//Initial Value
	Timer0_TCNT0 = 0xFF ;
	// Set 1/64 prescaller
	SET_Bit(Timer0_TCCR0,Timer0_CS00) ;
	SET_Bit(Timer0_TCCR0,Timer0_CS01) ;
	CLR_Bit(Timer0_TCCR0,Timer0_CS02) ;
	}
	else if(Time_Delay == 1)	// 1 Seconed Timer
	{
		Number_overFlow = 3906 ;
		Timer0_TCNT0 = 0x00 ;
		// Set 1/64 prescaller
		SET_Bit(Timer0_TCCR0,Timer0_CS00) ;
		CLR_Bit(Timer0_TCCR0,Timer0_CS01) ;
		CLR_Bit(Timer0_TCCR0,Timer0_CS02) ;
	}
	
	
	// Check OTOV
	while(Counter_OverFlow < Number_overFlow )
	{
		while((GET_Bit(Timer0_TIFR,Timer0_TOV0)) == 0);
		
		// Rest Over flow
		SET_Bit(Timer0_TIFR,Timer0_TOV0);
		Counter_OverFlow ++ ;
	};
	
	// Set Counter to 0 to repeate 
	Counter_OverFlow = 0 ;
	// Set Initial value to 256
	//Timer0_TCCR0 = 0XFF ;
	
}

