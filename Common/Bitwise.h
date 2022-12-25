/*
 * Bitwise.h
 *
 * Created: 11/2/2022 10:27:13 PM
 *  Author: LENOVO
 */ 


#ifndef BITWISE_H_
#define BITWISE_H_

	#define SET_Bit(Reg,Bit)  (Reg|=(1<<Bit))
	#define CLR_Bit(Reg,Bit)  (Reg&=~(1<<Bit))
	#define TOG_Bit(Reg,Bit)  (Reg^=(1<<Bit))
	#define GET_Bit(Reg,Bit)  ((Reg>>Bit)&1)



#endif /* BITWISE_H_ */