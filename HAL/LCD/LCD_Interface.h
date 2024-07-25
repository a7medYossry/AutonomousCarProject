/*
 * LCD_Interface.h
 *
 *  Created on: Apr 20, 2024
 *      Author: Mahmoud
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#define BIT_8  8
#define BIT_4  4



void vLCD_init(void);
void vLCD_sendCOMMAND(u8 command);
void vLCD_sendDATA(u8 data);

void vLCD_Send_String(u8 * str);

void vLCD_Convert_numTOchar(u16 num);//520

void CLCD_voidSendNumber(s32 cpy_u32Number);

void vLCD_Clear();

void vLCD_GO_TO(u8 line ,u8 position );




#endif /* HAL_LCD_LCD_INTERFACE_H_ */
