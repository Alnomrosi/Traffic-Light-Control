/*
 * EXTI_Register.h
 *
 * Created: 11/3/2022 1:59:38 AM
 *  Author: LENOVO
 */ 


#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


#define GLI_SREG		(*((volatile u8*)0x5F))
#define EXTI_MCUCR		(*((volatile u8*)0x55))
#define EXTI_MCUCSR		(*((volatile u8*)0x54))
#define EXTI_GICR		(*((volatile u8*)0x5B))		//General Interrupt Control Register


/* Global Register */
#define SREG_GEI	7

/* EXTI_MCUCR Register */

#define MCUCR_ISC11 3
#define MCUCR_ISC10 2
#define MCUCR_ISC01 1
#define MCUCR_ISC00 0

/* EXTI_MCUCR Register */

#define MCUCSR_ISC2 6

/* EXTI_GICR Register */
#define GICR_INT1 7
#define GICR_INT0 6
#define GICR_INT2 5



#endif /* EXTI_REGISTER_H_ */