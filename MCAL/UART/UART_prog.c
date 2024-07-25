/*
 * UART_prog.c
 *
 *  Created on: May 24, 2024
 *      Author: Mahmoud
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "UART_conf.h"
#include "UART_int.h"
#include "UART_praiver.h"



void UART_INIT()
{
	// 2D speed
	if(SPEED_MODE==NOT_SET_2DS)
	{
		CLEAR_BIT(UCSRA,U2X);
	}
	else if(SPEED_MODE==SET_2DS)
	{
		SET_BIT(UCSRA,U2X);
	}

	// select buodrate
	UBRRL=BOUD_RATE;

	u8 UCSRC_var=0x00;
	//SELECT PARITY
	if(PARITY_MODE==DISSABLE_PARITY){
		CLEAR_BIT(UCSRC_var,UPM0);
		CLEAR_BIT(UCSRC_var,UPM1);

	}
	else if(PARITY_MODE==EVEN_PARITY){
		CLEAR_BIT(UCSRC_var,UPM0);
				SET_BIT(UCSRC_var,UPM1);

	}
	else if(PARITY_MODE==ODD_PARITY){
		SET_BIT(UCSRC_var,UPM0);
		SET_BIT(UCSRC_var,UPM1);
	}


	// select stop
	if(SELECT_STOP==ONE_STOP)
	{
		CLEAR_BIT(UCSRC_var,USBS);
	}
	else if(SELECT_STOP==TWO_STOP)
	{
		SET_BIT(UCSRC_var,USBS);
	}

	//SELECT# of bit
	if(SELECT_NUM_BIT==BIT_8)
	{
		SET_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
	}

	//ASENCH
	CLEAR_BIT(UCSRC_var,UMSEL);

	UCSRC=UCSRC_var;




	//enable tx
	SET_BIT(UCSRB,TXEN);
	vSet_Pin_Direction(PORT_D,PIN_1,OUTPUT);
	//enable rx
	SET_BIT(UCSRB,RXEN);
	vSet_Pin_Direction(PORT_D,PIN_0,INPUT);
}

void UART_Send_Char(u8 data)
{
	while(!GET_BIT(UCSRA,UDRE));
	UDR=data;


}
u8 UART_Recive_Char()
{
	while(GET_BIT(UCSRA,RXC)==0);
	return UDR;
}
