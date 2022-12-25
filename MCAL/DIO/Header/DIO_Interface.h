/*
 * DIO_Interface.h
 *
 * Created: 11/2/2022 10:49:40 PM
 *  Author: LENOVO
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_VoidSetPinDir(u8 Group_Name, u8 Pin_Number, u8 Pin_State);
void DIO_VoidWritePin(u8 Group_Name, u8 Pin_Number, u8 Pin_State);
u8 u8_ReadPin(u8 Group_Name, u8 Pin_Number);
void DIO_VoidTogglePin(u8 Group_Name, u8 Pin_Number);



#endif /* DIO_INTERFACE_H_ */