/*
 * ADC_init.h
 *
 *  Created on: Nov 4, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_




#define Channel_A0 0
#define Channel_A1 1
#define Channel_A2 2
#define Channel_A3 3
#define Channel_A4 4
#define Channel_A5 5
#define Channel_A6 6
#define Channel_A7 7


#define EREF         0
#define AVCC         1
#define internal     3

#define prescaller2   0
#define prescaller4   1
#define prescaller8   2
#define prescaller16  3
#define prescaller32  4
#define prescaller128 5

void ADC_Init (u8 volt_ref,u8 prescaller);// ADC Initialization And Enable
u16 ADC_Read (u8 Channel); // Read From The ADC Channel
f32 ADC_VOLT(u8 channel);
u16 convert_volt_to_temp(u8 channel);
#endif /* MCAL_ADC_ADC_INIT_H_ */
