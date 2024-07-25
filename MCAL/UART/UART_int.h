/*
 * UART_int.h
 *
 *  Created on: May 24, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void UART_INIT();
void UART_Send_Char(u8 data);
u8 UART_Recive_Char();

#endif /* MCAL_UART_UART_INT_H_ */
