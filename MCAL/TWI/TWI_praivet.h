/*
 * TWI_praivet.h
 *
 *  Created on: May 31, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_TWI_TWI_PRAIVET_H_
#define MCAL_TWI_TWI_PRAIVET_H_

#define STATUSE_CODE                      (TWSR & 0xF8)

#define  START_condition_transmitted       0x08
#define  repSTART_condition_transmitted    0x10
#define  ADDRESS_W_transmitted             0x18
#define  ADDRESS_R_RECIVE                  0x40
#define  DATA_TRASMIT_WITH_ACK             0x28
#define  DATA_RECIVE_WITH_ACK             0x50


#define TWDR	(*(volatile u8*)0x23)

#define TWAR	(*(volatile u8*)0x22)
#define TWAR_TWGCE	0


#define TWSR	(*(volatile u8*)0x21)
#define TWSR_TWPS0	0
#define TWSR_TWPS1	1

#define TWBR	(*(volatile u8*)0x20)

#define TWCR	(*(volatile u8*)0x56)
#define 	_TWIE	0
#define TWCR_TWEN	2
#define TWCR_TWWC	3
#define TWCR_TWSTO	4
#define TWCR_TWSTA	5
#define TWCR_TWEA	6
#define TWCR_TWINT	7




#endif /* MCAL_TWI_TWI_PRAIVET_H_ */
