/*
 * IIC_interface.h
 *
 *  Created on: Feb 11, 2022
 *      Author: mohamed karem
 */

#ifndef IIC_INTERFACE_H_
#define IIC_INTERFACE_H_
#include"../../library/STD_types.h"
#include"../../library/bitmath.h"
typedef enum
{ err1,

 err2,
 err3,
 err4

}TWI_errorstatus_t;



void TWI_voidMasterINST(u8   );
void TWI_voidSlaveINST(u8 );

TWI_errorstatus_t TWI_SendStartcondition(void);
TWI_errorstatus_t TWI_SendRepeatedStart(void);
TWI_errorstatus_t TWI_SendSlaveAddressWithWrite(u8);
TWI_errorstatus_t TWI_SendSlaveAddressWithRead(u8 );
TWI_errorstatus_t TWI_MasterSendDataByte(u8 );
TWI_errorstatus_t TWI_MasterReceiveDataByte(u8 * arr);

void IIC_voidSendStopcondition(void);


#endif /* IIC_INTERFACE_H_ */
