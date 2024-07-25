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

#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LCD/LCD_Confg.h"

#include "../HAL/KEYPAD/KEYPAD_CONF.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../FreeRTOS.h"
#include "../task.h"
#include "../HAL/MOTOR/MOTOR_CONF.h"
#include "../HAL/MOTOR/MOTOR_init.h"
#include "util/delay.h"

int main()
{

	while (1)
	{
		Forward_Move();
		_delay_ms(1000);
		STop_motor(MOTOR_A);
		STop_motor(MOTOR_B);
		_delay_ms(1000);
		Backward_Move();
		_delay_ms(1000);
		Turn_Right();
		_delay_ms(1000);
		Turn_Left();
		_delay_ms(1000);
	}
}
