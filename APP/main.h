/*
 * main.h
 *
 *  Created on: Jul 27, 2024
 *      Author: Ahmedyossry
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

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

#include "../HAL/SERVO/servo.h"

#include "util/delay.h"



#define OBSTACLE_THRESHOLD 20  // Distance in cm to consider as an obstacle

#define TURN_DELAY 2000
#define SERVO_DELAY 4000
#define MOVE_DELAY 1000


#endif /* APP_MAIN_H_ */
