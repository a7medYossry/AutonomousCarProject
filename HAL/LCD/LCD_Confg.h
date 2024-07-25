/*
 * LCD_Confg.h
 *
 *  Created on: Apr 20, 2024
 *      Author: Mahmoud
 */

#ifndef HAL_LCD_LCD_CONFG_H_
#define HAL_LCD_LCD_CONFG_H_



#define LCD_MODE  BIT_4
//*************8 BIT MODE************
#define DATA_PORT           PORT_A
#define RS_PORT             PORT_B
#define RS_PIN              PIN_1
#define R_W_PORT            PORT_B
#define R_W_PIN             PIN_2
#define E_PORT              PORT_B
#define E_PIN               PIN_3
//*************4 BIT MODE************
#define D7  PIN_7
#define D6  PIN_6
#define D5  PIN_5
#define D4  PIN_4
#endif /* HAL_LCD_LCD_CONFG_H_ */
