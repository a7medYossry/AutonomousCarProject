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
#include "../MCAL/External_Interrupt/External_Interrupt_Interface.h"
#include "../MCAL/GLOBAL_INTERRUPT/Global_Interrupt_interface.h"
#include "../MCAL/ADC/ADC_init.h"
#include "../MCAL/DIO/DIO_CONF.h"

#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LCD/LCD_Confg.h"
#include "../HAL/EEPROM/EEPROM_init.h"
#include "../MCAL/UART/UART_int.h"
#include "../MCAL/SPI/SPI_init.h"
#include "../MCAL/SPI/SPI_conf.h"
#include "../MCAL/SPI/SPI_praivat.h"
#include "../MCAL/TWI/TWI_init.h"
#include "../MCAL/WDT/WDT.h"


#include "../HAL/KEYPAD/KEYPAD_CONF.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include <util/delay.h>
#include <avr/io.h>
#include "../FreeRTOS.h"
#include "../task.h"

void LED1 (void)
{
	while(1)
	{
		vTOGGLE_Pin(PORT_C,PIN_7);//
		vTaskDelay(1000);
	}
}
void LED0 (void)
{
	while(1)
	{
		vTOGGLE_Pin(PORT_C,PIN_2);
		vTaskDelay(3000);
	}
}


void LED2 (void)
{
	while(1)
	{
		vTOGGLE_Pin(PORT_D,PIN_3);
		vTaskDelay(2000);
	}
}


void func (void)
{
	vTOGGLE_Pin(PORT_C,PIN_7);

}
//MASTER
int main()
{
	vSet_Pin_Direction(PORT_C,PIN_2,OUTPUT);
	vSet_Pin_Direction(PORT_C,PIN_7,OUTPUT);
	vSet_Pin_Direction(PORT_D,PIN_3,OUTPUT);
	//vSet_Pin_OUTPUTvalue(PORT_A,PIN_3,OUTPUT);
	xTaskCreate(&LED1,NULL,150,NULL,1,NULL);
	xTaskCreate(&LED0,NULL,150,NULL,2,NULL);
	xTaskCreate(&LED2,NULL,150,NULL,3,NULL);
	vTaskStartScheduler();
	while(1)
	{




	}

}
