/*
 * IIC_program.c
 *
 *  Created on: Feb 11, 2022
 *      Author: mohamed karem
 */
#include "../../library/bitmath.h"
#include "../../library/STD_types.h"
#include"IIC_register.h"
#include"IIC_private.h"
#include"IIC_interface.h"

void TWI_voidMasterINST(u8 copy_u8Slaveaddress){
	/*Set the clock frequency at 400 Kbps*/
	/*from the equation in page 173 in data sheet ,assume TWPS by 0 and get TWBR value
	 * 250 kbps*/
	TWBR=2;
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/*if the master addressed*/
	if(copy_u8Slaveaddress !=0)
	{
		TWAR=copy_u8Slaveaddress;
	}
	/*TWI enable*/
	SET_BIT(TWCR,TWCR_TWEN);
}
void TWI_voidSlaveINST(u8 copy_u8Slaveaddress){
/*set slave address*/
	TWAR=copy_u8Slaveaddress;
	/*TWI enable*/
	SET_BIT(TWCR,TWCR_TWEN);
}



TWI_errorstatus_t TWI_SendStartcondition(void){
TWI_errorstatus_t local_errorstatus=0;
/*send start condition*/
SET_BIT(TWCR,TWCR_TWINT);
SET_BIT(TWCR,TWCR_TWSTA);
CLR_BIT(TWCR,TWCR_TWSTO);
SET_BIT(TWCR,TWCR_TWEN);

while (GET_BIT(TWCR ,TWCR_TWINT)==0)
;


if ((TWSR & 0xF8) !=START_ACK )
	local_errorstatus=(TWSR & 0xF8) ;

return local_errorstatus;
}
TWI_errorstatus_t TWI_SendRepeatedStart(void){
	TWI_errorstatus_t local_errorstatus=0;
	/*send start condition*/
	//CLR_BIT(TWCR,TWCR_TWSTA);
	//CLR_BIT(TWCR,TWCR_TWINT);
	SET_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);

	CLR_BIT(TWCR,TWCR_TWSTO);
	SET_BIT(TWCR,TWCR_TWEN);

	while (GET_BIT(TWCR ,TWCR_TWINT)==0)
	;


	//if ((TWSR & 0xF8) !=REP_START_ACK )
	//	local_errorstatus=(TWSR & 0xF8) ;
	return local_errorstatus;
}

TWI_errorstatus_t TWI_SendSlaveAddressWithWrite(u8 copy_u8SlaveAddress){
	TWI_errorstatus_t local_errorstatus=0;
	/*set the slave address*/
	TWDR=(copy_u8SlaveAddress)&(0b11111110);
	/* send address*/
	SET_BIT(TWCR,TWCR_TWINT);
	CLR_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWEN);

	while (GET_BIT(TWCR ,TWCR_TWINT)==0)
	;


	if ((TWSR & 0xF8) !=SLAVE_ADD_AND_WR_ACK )
		local_errorstatus=(TWSR & 0xF8) ;
	return local_errorstatus;
}
TWI_errorstatus_t TWI_SendSlaveAddressWithRead(u8 copy_u8SlaveAddress){
	TWI_errorstatus_t local_errorstatus=0;
		/*set the slave address*/
		TWDR=(copy_u8SlaveAddress<<1)&(0b111111111);
		/* send address*/
		SET_BIT(TWCR,TWCR_TWINT);
		CLR_BIT(TWCR,TWCR_TWSTA);
		SET_BIT(TWCR,TWCR_TWEN);

		while (GET_BIT(TWCR ,TWCR_TWINT)==0)
		;


		if ((TWSR & 0xF8) !=SLAVE_ADD_AND_RD_ACK )
			local_errorstatus=(TWSR & 0xF8) ;
		return local_errorstatus;
}

TWI_errorstatus_t TWI_MasterSendDataByte(u8 copy_u8DataByte){
	TWI_errorstatus_t local_errorstatus=0;
			/*set the slave address*/
			TWDR=copy_u8DataByte;
			/* send address*/
			SET_BIT(TWCR,TWCR_TWINT);
			SET_BIT(TWCR,TWCR_TWEN);

			while (GET_BIT(TWCR ,TWCR_TWINT)==0)
			;


			if ((TWSR & 0xF8) !=MSTR_WR_BYTE_ACK )
				local_errorstatus=(TWSR & 0xF8) ;
			return local_errorstatus;
}
TWI_errorstatus_t TWI_MasterReceiveDataByte(u8 *copy_u8DataByte)
{
	TWI_errorstatus_t local_errorstatus=0;
				/*set the slave address*/

				/* send address*/
				SET_BIT(TWCR,TWCR_TWINT);
				SET_BIT(TWCR,TWCR_TWEN);

				while (GET_BIT(TWCR ,TWCR_TWINT)==0)
				;

				*copy_u8DataByte=TWDR;
				if ((TWSR & 0xF8) !=MSTR_RD_BYTE_WITH_ACK )
					local_errorstatus=(TWSR & 0xF8) ;

				return local_errorstatus;}
void IIC_voidSendStopcondition(void){
	SET_BIT(TWCR,TWCR_TWINT);
	SET_BIT(TWCR,TWCR_TWSTO);
	SET_BIT(TWCR,TWCR_TWEN);
	CLR_BIT(TWCR,TWCR_TWSTA);
}

