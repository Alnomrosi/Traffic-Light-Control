/*
 * LED_Interface.h
 *
 * Created: 11/2/2022 10:59:11 PM
 *  Author: LENOVO
 */ 



#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../../Common/Typedefs.h"
/* LED Prototypes */

u8 LED_VoidInit(u8 LEDGroup_Name, u8 LEDPIN_Number);
u8 LED_Void_ON(u8 LEDGroup_Name, u8 LEDPIN_Number);
u8 LED_VOID_OFF(u8 LEDGroup_Name, u8 LEDPIN_Number);
u8 LED_Void_Blink(u8 Mode_Type);


#endif /* LED_INTERFACE_H_ */