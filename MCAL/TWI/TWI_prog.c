/*
 * TWI_prog.c
 *
 *  Created on: May 31, 2024
 *      Author: Mahmoud
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "TWI_init.h"
#include "TWI_praivet.h"

void vMASTER_init                 (void)
{
	/* set pre-scaler -> 0 */
	/* TWPS1, TWPS0 @ TWSR -> 0, 0 (default) */
	CLEAR_BIT(TWSR,TWSR_TWPS0);
	CLEAR_BIT(TWSR,TWSR_TWPS1);

	/* select bit rate */
	/* TWBR	-> 12 */
	/* FTWI = 400KHZ*/

	TWBR=12;
	/* enable acknowledge  */
	/* TWEA @ TWCR -> 1 */
	SET_BIT(TWCR,TWCR_TWEA);


	/* enable TWI */
	/* TWEN @ TWCR -> 1 */
	SET_BIT(TWCR,TWCR_TWEN);

}
void vMASTER_START_condition      (void)
{
	//SET START BIT CONDITION
	SET_BIT(TWCR,TWCR_TWSTA);

	//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
	SET_BIT(TWCR,TWCR_TWINT);
	//BUSY W8 OF FLAG
	while(!GET_BIT(TWCR,TWCR_TWINT));
	//check in status code
	//while(STATUSE_CODE != START_condition_transmitted);


}
void vMASTER_REP_START_condition  (void)
{
	//SET START BIT CONDITION
	SET_BIT(TWCR,TWCR_TWSTA);

	//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
	SET_BIT(TWCR,TWCR_TWINT);
	//BUSY W8 OF FLAG
	while(!GET_BIT(TWCR,TWCR_TWINT));
	//check in status code
	//while(STATUSE_CODE != repSTART_condition_transmitted);
}

void vMASTER_STOP_condition       (void)
{
	/* stop condition */
	/* TWSTO @ TWCR -> 1 */
	SET_BIT(TWCR, TWCR_TWSTO);

	//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
	/* TWINT @ TWCR -> 1 */
	SET_BIT(TWCR, TWCR_TWINT);
}

void MASTER_SEND_ADDRESS_WRITE    (u8 adress)
{

	if(adress<128)
	{
		//WRITE ADDRESS IN REG TWAR
		TWDR=adress<<1;
		// CLEAR BIT 0 TO WTITE
		CLEAR_BIT(TWDR,0);
		// CLEAR START BIT
		CLEAR_BIT(TWCR,TWCR_TWSTA);
		//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
		SET_BIT(TWCR,TWCR_TWINT);
		//BUSY W8 OF FLAG
		while(!GET_BIT(TWCR,TWCR_TWINT));
		//check in status code
		//while(STATUSE_CODE != ADDRESS_W_transmitted);


	}
}
void MASTER_SEND_ADDRESS_READ     (u8 adress)
{

	if(adress<128)
	{
		//WRITE ADDRESS IN REG TWAR
		TWDR=adress<<1;
		// SET BIT 0 TO READ  -> SALVE TRASMIT
		SET_BIT(TWDR,TWAR_TWGCE);
		// CLEAR START BIT
		CLEAR_BIT(TWCR,TWCR_TWSTA);

		//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
		SET_BIT(TWCR,TWCR_TWINT);
		//BUSY W8 OF FLAG
		while(!GET_BIT(TWCR,TWCR_TWINT));
		//check in status code
		//while(STATUSE_CODE != ADDRESS_R_RECIVE);
	}
}

void MASTER_SEND_DATA             (u8 data)
{
	TWDR=data;

	//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
	SET_BIT(TWCR,TWCR_TWINT);

	//BUSY W8 OF FLAG
	while(!GET_BIT(TWCR,TWCR_TWINT));
	//check in status code
	//while(STATUSE_CODE != DATA_TRASMIT_WITH_ACK);

}
u8 MASTER_RECIVE_DATA             (void)
{
	SET_BIT(TWCR, TWCR_TWEA);
	//CLEAR FLAG  The TWINT Flag must be cleared by software by writing a logic one
	SET_BIT(TWCR,TWCR_TWINT);

	//BUSY W8 OF FLAG
	while(!GET_BIT(TWCR,TWCR_TWINT));
	//check in status code
	//while(STATUSE_CODE != DATA_RECIVE_WITH_ACK);


	return TWDR;
}




void I2C_reciveByte(u8 *byte , u8 ACK)
{
     if(ACK==ACK1)
     {
    	TWCR= (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWEA);
     }
     else if (ACK==NOT_ACK)
     {
    	 TWCR= (1<<TWCR_TWINT)|(1<<TWCR_TWEN);
    			 CLEAR_BIT(TWCR,TWCR_TWEA);

     }

     while (!(TWCR & (1<<TWCR_TWINT)));
     *byte=TWDR;

}
