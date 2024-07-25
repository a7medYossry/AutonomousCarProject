/*
 * ADC_prog.c
 *
 *  Created on: Nov 4, 2023
 *      Author: WIN 10 PRO
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_init.h"
#include "ADC_praivate.h"


void ADC_Init (u8 volt_ref,u8 prescaller)// ADC Initialization And Enable
{
	switch(volt_ref)
	{
	case EREF:
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
	case AVCC:
		CLEAR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
	case internal:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;

	}
	CLEAR_BIT(ADMUX,ADLAR);
	SET_BIT(ADCSRA,ADEN);
	switch(prescaller)
	{
	case prescaller2:
		CLEAR_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);
		break;
	case prescaller4:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);
		break;
	case prescaller8:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);
		break;
	case prescaller16:
		CLEAR_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
	case prescaller32:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
	case prescaller128:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
	}



}



u16 ADC_Read (u8 Channel)// Read From The ADC Channel
{
  ADMUX=ADMUX&0b11100000;
  ADMUX=ADMUX|Channel;
  // START CONVERTION
  SET_BIT(ADCSRA,ADSC);

  //CHEAK FLAG
  while(!GET_BIT(ADCSRA,ADIF));

  //CLEAR FLAG BY SET BIT
  SET_BIT(ADCSRA,ADIF);

  return ADC_Reg;


}
f32  ADC_VOLT(u8  channel)
{
	f32  volt , adc;

	adc = ADC_Read(channel);

	volt=((adc*5)/1023)*1000;
	return volt;

}

u16  convert_volt_to_temp(u8 channel)
{
	u16 temp;
	temp=ADC_VOLT(channel)*100;
	return temp;
}



