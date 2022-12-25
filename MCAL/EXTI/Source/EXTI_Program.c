/*
 * CFile1.c
 *
 * Created: 11/3/2022 2:00:11 AM
 *  Author: LENOVO
 */ 


#include "../Header/EXTI_Interface.h"
#include "../Header/EXTI_Register.h"
#include "../../../Common/bitwise.h"
#include "../../../Common/Macros.h"
#include "../../../Common/Typedefs.h"

/* Pointer to function to store the function address*/
static void (*EXTI_INT0Func)(void ) = NULL ;

void EXTI_VoidInitINT0()
{
	/* Enable Globale Interupt */
	SET_Bit(GLI_SREG,SREG_GEI);
	
	/* Generate Interrupt in rising edge for Interrupt 0 */
	SET_Bit(EXTI_MCUCR,MCUCR_ISC01);
	SET_Bit(EXTI_MCUCR,MCUCR_ISC00);

	/*Enable Interrupt 0 from General Interrupt control register  */
	SET_Bit(EXTI_GICR,GICR_INT0);
}

u8 EXTI_u8INT0_VoidCallbackFunction(void (*Copy_Func)(void))
{
	u8 Return_value ;

	if (Copy_Func != NULL)
	{
		
		EXTI_INT0Func = Copy_Func ;
	}
	else
	{
		Return_value = 0 ;
	}

	return 	Return_value ;

}


// ISR
void __vector_1 (void) __attribute__ ((signal));
void __vector_1	(void)
{
	if(EXTI_INT0Func != NULL)
	{
		EXTI_INT0Func();
	}
	else
	{
		// Do nothing
	}
}