/*
 * External_Interrupt_Interface.h
 *
 *  Created on: May 3, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_INTERFACE_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_INTERFACE_H_

typedef enum Interrupt_Mood
{
	Raising_edge,
	Flling_edge,
	Low_level,
	Logical_change
}I_mood_t;

typedef enum Interrupt_Number
{
	EXTI0,
	EXTI1,
	EXTI2

}I_num_t;
void vExternal_Interrupt_Enable(I_num_t EXTI, I_mood_t EXTI_Mood);
void vExternal_Interrupt_Disable(I_num_t EXTI);

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_INTERFACE_H_ */
