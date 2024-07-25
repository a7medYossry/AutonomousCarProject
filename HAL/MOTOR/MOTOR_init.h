/*
 * MOTOR_init.h
 *
 *  Created on: May 17, 2024
 *      Author: Mahmoud
 */

#ifndef HAL_MOTOR_MOTOR_INIT_H_
#define HAL_MOTOR_MOTOR_INIT_H_

#define MOTOR_A          0
#define MOTOR_B          1


#define DIRECTION_CW     0
#define DIRECTION_CCW    1

void Start_motor(u8 motorID,u8 Direction);
void STop_motor(u8 motorID);
void speed_control (u8 motorID,u8 Direction,u8 duty_cycle);

#endif /* HAL_MOTOR_MOTOR_INIT_H_ */
