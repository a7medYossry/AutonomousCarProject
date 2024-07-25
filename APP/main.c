/*
 * main.c
 *
 *  Created on: Apr 6, 2024
 *      Author: Mahmoud
 *      APP LAYER MAIN.C
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/DIO/DIO_CONF.h"
#include "../MCAL/TIMERS/TIMER_confg.h"
#include "../MCAL/TIMERS/TIMER_init.h"
#include "../MCAL/TIMERS/TIMER_praivat.h"

#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LCD/LCD_Confg.h"

#include "../HAL/ULTRASONIC/ultrasonic.h"

#include "../HAL/MOTOR/MOTOR_CONF.h"
#include "../HAL/MOTOR/MOTOR_init.h"
#include "util/delay.h"

int main()
{
	vGlobal_interrupt_Enable();
	u16 distance = 0;
	vLCD_init();
	ultrasonic_init();



	while (1)
	{
				// _delay_ms(1000);

			send_trigger_pulse();

		distance = read_echo_pulse();
			vLCD_Convert_numTOchar(distance);
		// send_trigger_pulse();

		// distance = read_echo_pulse();
		// vLCD_Convert_numTOchar(distance);
		_delay_ms(1000);

		vLCD_Clear();
		_delay_ms(1000);
//		vTIMER0_STOP();


		// 	Forward_Move();
		// 	_delay_ms(1000);
		// 	Stop_Move();
		// 	_delay_ms(1000);
		// 	Backward_Move();
		// 	_delay_ms(1000);
		// 	Turn_Right();
		// 	_delay_ms(1000);
		// 	Turn_Left();
		// 	_delay_ms(1000);
	}
}
