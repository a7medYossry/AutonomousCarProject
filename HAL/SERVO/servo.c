/*
 * servo.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Ahmedyossry
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_CONF.h"

#include "../../MCAL/TIMERS/TIMER_confg.h"
#include "../../MCAL/TIMERS/TIMER_init.h"

#include "util/delay.h"

#include "servo.h"

void servo_init(void)
{
	// Set SERVO_PIN as output
	vSet_Pin_Direction(SERVO_PORT, SERVO_PIN, OUTPUT);
	// Initialize Timer2
	//vTIMER2_INIT();

	// Set prescaler to 64
	//vTIMER2_START();
}
void servo_set_angle(u16 angle)
{
	switch (angle)
	{
	case 0:
		vSet_Pin_OUTPUTvalue(PORT_D, PIN_7, HIGH);
		_delay_ms(1);
		vSet_Pin_OUTPUTvalue(PORT_D, PIN_7, LOW);
		_delay_ms(19);
		break;
	case 90:
		vSet_Pin_OUTPUTvalue(PORT_D, PIN_7, HIGH);
		_delay_us(1350);
		vSet_Pin_OUTPUTvalue(PORT_D, PIN_7, LOW);
		_delay_us(18650);
		break;
	case 180:
		vSet_Pin_OUTPUTvalue(PORT_D, PIN_7, HIGH);
		_delay_us(2000);
		vSet_Pin_OUTPUTvalue(PORT_D, PIN_7, LOW);
		_delay_us(18000);
		break;
	}
}
