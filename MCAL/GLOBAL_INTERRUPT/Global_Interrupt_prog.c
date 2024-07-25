/*
 * Global_Interrupt_prog.c
 *
 *  Created on: May 3, 2024
 *      Author: Mahmoud
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "Global_Interrupt_interface.h"
#include "Global_Interrupt_Praivet.h"



void vGlobal_interrupt_Enable()
{
	SET_BIT(SREG,I);
}
void vGlobal_interrupt_Disable()
{
	CLEAR_BIT(SREG,I);
}


