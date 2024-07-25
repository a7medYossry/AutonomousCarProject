/*
 * TWI_init.h
 *
 *  Created on: May 31, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_TWI_TWI_INIT_H_
#define MCAL_TWI_TWI_INIT_H_
#define ACK1        0
#define NOT_ACK    1


void vMASTER_init                 (void);
void vMASTER_START_condition      (void);
void vMASTER_REP_START_condition  (void);

void vMASTER_STOP_condition       (void);

void MASTER_SEND_ADDRESS_WRITE    (u8 adress);
void MASTER_SEND_ADDRESS_READ     (u8 adress);

void MASTER_SEND_DATA             (u8 data);
u8 MASTER_RECIVE_DATA             (void);


#endif /* MCAL_TWI_TWI_INIT_H_ */
