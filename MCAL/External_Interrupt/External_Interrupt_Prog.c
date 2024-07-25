#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "External_Interrupt_Interface.h"
#include "External_Interrupt_Praivet.h"


void vExternal_Interrupt_Enable(I_num_t EXTI, I_mood_t EXTI_Mood)
{
	switch(EXTI)
	{
	case EXTI0:
		switch(EXTI_Mood)
		{
		case Raising_edge:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case Flling_edge:
			SET_BIT(MCUCR,ISC01);
			CLEAR_BIT(MCUCR,ISC00);
			break;
		case Low_level:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		case Logical_change:
			CLEAR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
		}

		//Enable PIE
		SET_BIT(GICR,INT0);

		break;
		case EXTI1:
			switch(EXTI_Mood)
			{
			case Raising_edge:
				SET_BIT(MCUCR,ISC11);
				SET_BIT(MCUCR,ISC10);
				break;
			case Flling_edge:
				SET_BIT(MCUCR,ISC11);
				CLEAR_BIT(MCUCR,ISC10);
				break;
			case Low_level:
				CLEAR_BIT(MCUCR,ISC11);
				CLEAR_BIT(MCUCR,ISC10);
				break;
			case Logical_change:
				CLEAR_BIT(MCUCR,ISC11);
				SET_BIT(MCUCR,ISC10);
				break;
			}

			//Enable PIE
			SET_BIT(GICR,INT1);
			break;
			case EXTI2:
				switch(EXTI_Mood)
				{
				case Raising_edge:
					SET_BIT(MCUCSR,ISC2);
					break;
				case Flling_edge:
					CLEAR_BIT(MCUCSR,ISC2);
					break;
				}
					SET_BIT(GICR,INT2);


					break;


	}
}
void vExternal_Interrupt_Disable(I_num_t EXTI)
{

}
