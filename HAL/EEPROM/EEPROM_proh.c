/*
 * EEPROM_proh.c
 *
 *  Created on: Jun 1, 2024
 *      Author: Mahmoud
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/TWI/TWI_init.h"

#include <util/delay.h>





void EEPROM_WRITE(u16 wordadd,u8 data)
{
//
//	u16 add = wordadd;
//	add=add>>8;
	u8 add=(wordadd>>8)|0b01010000;

	vMASTER_init();
	vMASTER_START_condition();

	//MASTER_SEND_ADDRESS_WRITE(0b01010000|add);
	MASTER_SEND_ADDRESS_WRITE(add);
	MASTER_SEND_DATA((u8)wordadd);

	MASTER_SEND_DATA(data);
	vMASTER_STOP_condition();
	_delay_ms(5);
}



u8 EEPROM_READ(u16 wordadd)
{
	u8 add=(wordadd>>8)|0b01010000;

		vMASTER_init();
		vMASTER_START_condition();
		MASTER_SEND_ADDRESS_WRITE(add);
		MASTER_SEND_DATA((u8)wordadd);
		vMASTER_REP_START_condition();
		MASTER_SEND_ADDRESS_READ(add);
		u8 data = MASTER_RECIVE_DATA();
		vMASTER_STOP_condition();
		return data;
     _delay_ms(5);

}
