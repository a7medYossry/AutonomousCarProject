/*
 * External_Interrupt_Praivet.h
 *
 *  Created on: May 3, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_PRAIVET_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_PRAIVET_H_


#define MCUCR   (*(volatile u8*)(0x55))
#define GIFR    (*(volatile u8*)(0x5A))
#define  GICR   (*(volatile u8*)(0x5B))
#define MCUCSR  (*(volatile u8*)(0x54))


#define ISC11 3    // INT1
#define ISC10 2    // INT1
#define ISC01 1    //INT 0
#define ISC00 0    // INT 0


#define ISC2 6      //INT 2

// to enable and disable interrupt
#define INT1 7
#define INT0 6
#define INT2 5




#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_PRAIVET_H_ */
