/*
 * Timer0_Register.h
 *
 * Created: 11/2/2022 11:51:56 PM
 *  Author: LENOVO
 */ 


#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

#include "../../../Common/Typedefs.h"

/* TIMER0	Registers	*/
#define Timer0_TCCR0	(*((volatile u8*)0x53))
#define	Timer0_TCNT0	(*((volatile u8*)0x52))
#define Timer0_TIFR		(*((volatile u8*)0x58))


/* TCCR0 Bits	*/
#define Timer0_FOC0		7	// Force Compare Match
#define Timer0_WGM00	6	// Waveform generation Mode
#define Timer0_WGM01	3	// Waveform generation Mode
#define Timer0_COM01	5	// Compare Match Output Mode
#define Timer0_COM00	4	// Compare Match Output Mode
#define	Timer0_CS02		2	// Prescaller
#define	Timer0_CS01		1	// Prescaller
#define	Timer0_CS00		0	// Prescaller

/* TIFR Bits */
#define Timer0_TOV0		0	//	OverFlow flag



#endif /* TIMER0_REGISTER_H_ */