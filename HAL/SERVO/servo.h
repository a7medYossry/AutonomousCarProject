/*
 * servo.h
 *
 *  Created on: Jul 27, 2024
 *      Author: Ahmedyossry
 */


#define SERVO_PORT PORT_D 
#define SERVO_PIN PIN_7 


void servo_init(void);
void servo_set_angle(u16 angle);
