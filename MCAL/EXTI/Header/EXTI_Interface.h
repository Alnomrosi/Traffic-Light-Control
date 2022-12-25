/*
 * EXTI_Interface.h
 *
 * Created: 11/3/2022 1:59:48 AM
 *  Author: LENOVO
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "../../../Common/Typedefs.h"

void EXTI_VoidInitINT0();
u8 EXTI_u8INT0_VoidCallbackFunction(void (*Copy_Func)(void)) ;



#endif /* EXTI_INTERFACE_H_ */