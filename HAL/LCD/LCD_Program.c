/*
 * LCD_Program.c
 *
 *  Created on: Apr 20, 2024
 *      Author: Mahmoud
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Confg.h"
#include <util/delay.h>

#if LCD_MODE == BIT_8
void vLCD_init(void)
{
	vSet_Port_Direction(DATA_PORT,OUTPUT);
	vSet_Pin_Direction(RS_PORT,RS_PIN,OUTPUT);
	vSet_Pin_Direction(R_W_PORT,R_W_PIN,OUTPUT);
	vSet_Pin_Direction(E_PORT,E_PIN,OUTPUT);
	_delay_ms(40);
	vLCD_sendCOMMAND(0b00111000);
	_delay_ms(1);
	vLCD_sendCOMMAND(0b00001111);
	_delay_ms(1);
	vLCD_sendCOMMAND(0b00000001);
	_delay_ms(3);
	vLCD_sendCOMMAND(0b00000110);




}

void vLCD_sendCOMMAND(u8 command)
{
	vSet_Pin_OUTPUTvalue(RS_PORT,RS_PIN,LOW);
	vSet_Pin_OUTPUTvalue(R_W_PORT,R_W_PIN,LOW);
	vSet_Port_OUTPUTvalue(DATA_PORT,command);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,HIGH);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,LOW);
	_delay_ms(1);



}
void vLCD_sendDATA(u8 data)//'A'
{
	vSet_Pin_OUTPUTvalue(RS_PORT,RS_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(R_W_PORT,R_W_PIN,LOW);
	vSet_Port_OUTPUTvalue(DATA_PORT,data);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,HIGH);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,LOW);
	_delay_ms(1);

}

#elif LCD_MODE==BIT_4

void vLCD_init(void)
{
	vSet_Pin_Direction(DATA_PORT,D7,OUTPUT);
	vSet_Pin_Direction(DATA_PORT,D6,OUTPUT);
	vSet_Pin_Direction(DATA_PORT,D5,OUTPUT);
	vSet_Pin_Direction(DATA_PORT,D4,OUTPUT);
	vSet_Pin_Direction(RS_PORT,RS_PIN,OUTPUT);
	vSet_Pin_Direction(R_W_PORT,R_W_PIN,OUTPUT);
	vSet_Pin_Direction(E_PORT,E_PIN,OUTPUT);


	_delay_ms(40);
	vLCD_sendCOMMAND(0b00000010);
	vLCD_sendCOMMAND(0b00101000);
	_delay_ms(1);
	vLCD_sendCOMMAND(0b00001111);
	_delay_ms(1);
	vLCD_sendCOMMAND(0b00000001);
	_delay_ms(3);
	vLCD_sendCOMMAND(0b00000110);

}
void vLCD_sendCOMMAND(u8 command)
{
	vSet_Pin_OUTPUTvalue(RS_PORT,RS_PIN,LOW);
	vSet_Pin_OUTPUTvalue(R_W_PORT,R_W_PIN,LOW);


	vSet_Pin_OUTPUTvalue(DATA_PORT,D7,GET_BIT(command,7));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D6,GET_BIT(command,6));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D5,GET_BIT(command,5));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D4,GET_BIT(command,4));
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,HIGH);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,LOW);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(DATA_PORT,D7,GET_BIT(command,3));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D6,GET_BIT(command,2));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D5,GET_BIT(command,1));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D4,GET_BIT(command,0));
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,HIGH);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,LOW);
	_delay_ms(1);
}
void vLCD_sendDATA(u8 data)
{
	vSet_Pin_OUTPUTvalue(RS_PORT,RS_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(R_W_PORT,R_W_PIN,LOW);


	vSet_Pin_OUTPUTvalue(DATA_PORT,D7,GET_BIT(data,7));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D6,GET_BIT(data,6));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D5,GET_BIT(data,5));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D4,GET_BIT(data,4));
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,HIGH);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,LOW);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(DATA_PORT,D7,GET_BIT(data,3));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D6,GET_BIT(data,2));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D5,GET_BIT(data,1));
	vSet_Pin_OUTPUTvalue(DATA_PORT,D4,GET_BIT(data,0));
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,HIGH);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,LOW);
	_delay_ms(1);
}




#endif


void vLCD_Send_String(u8 * str)
{
	for(u8 i=0;str[i];i++)
	{
		vLCD_sendDATA(str[i]);
	}

}

void vLCD_Convert_numTOchar(u16 num)//-520
{
	u8 str[10];
	u8 res=0,i=0;
	if(num<0)
	{
		num=num*(-1);
		vLCD_sendDATA('-');

	}

	while(num)//520
	{
		res=num%10;//0 2 5
		str[i]=res+'0';//'0' '2' '5'
		num=num/10;//52  5  0
		i++;//1 2 3 4

	}
	for(s8 j=i-1;j>=0;j--)
	{
		vLCD_sendDATA(str[j]);
	}

}

void vLCD_Clear()
{
	vLCD_sendCOMMAND(0b00000001);
	_delay_ms(2);
}

void vLCD_GO_TO(u8 line ,u8 position )
{
	if(line==1)
	{
		vLCD_sendCOMMAND(0x80+position);
	}
	if(line==2)
	{
		vLCD_sendCOMMAND(0x80+0x40+position);
	}
}



void CLCD_voidSendNumber(s32 cpy_u32Number) //123
{      u32 cpy_u32power=1;
       s32 cpy_u32num=cpy_u32Number;
      if(cpy_u32Number==0)
      {
    	  vLCD_sendDATA('0');
    	  return;
      }
      if(cpy_u32Number<0)
      {

    	  cpy_u32Number=cpy_u32Number*(-1);
    	  vLCD_sendDATA('-');
      }
      while(cpy_u32num)
      {//01234

    	  cpy_u32num=cpy_u32num/10;          //01234  0123  012   01   0 0
    	  cpy_u32power=cpy_u32power*10;      //1000
      }
      cpy_u32power=cpy_u32power/10;
      while(cpy_u32power>0)
      {
    	  cpy_u32num=cpy_u32Number/cpy_u32power;  //01234/1000=0
    	  cpy_u32Number%=cpy_u32power;
    	  cpy_u32power/=10;

    	  vLCD_sendDATA(cpy_u32num+'0');
      }




}


