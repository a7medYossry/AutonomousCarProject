/*
 * DIO_Interface.h
 *
 *  Created on: Apr 19, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
//********************* PORT ID***************************
#define PORT_A        0
#define PORT_B        1
#define PORT_C        2
#define PORT_D        3
//******************** PIN ID*************************
#define PIN_0         0
#define PIN_1         1
#define PIN_2         2
#define PIN_3         3
#define PIN_4         4
#define PIN_5         5
#define PIN_6         6
#define PIN_7         7
//*******************DIRECTION****************************
#define OUTPUT        1
#define INPUT         0
//****************PIN OUTPUT STATUSE**************
#define HIGH          1
#define LOW           0







//***************PROTOTYPE FUNCTION*************************
void vSet_Pin_Direction   (u8 PORT_ID , u8 PIN_ID , u8 Direction);
void vSet_Pin_OUTPUTvalue (u8 PORT_ID , u8 PIN_ID , u8 Value);
void vTOGGLE_Pin          (u8 PORT_ID , u8 PIN_ID);
u8 vGIT_PIN          (u8 PORT_ID , u8 PIN_ID);



void vSet_Port_Direction   (u8 PORT_ID , u8 Direction);
void vSet_Port_OUTPUTvalue (u8 PORT_ID , u8 Value);
void vTOGGLE_port          (u8 PORT_ID );



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
