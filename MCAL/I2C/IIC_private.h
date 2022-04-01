/*
 * IIC_private.h
 *
 *  Created on: Feb 11, 2022
 *      Author: mohamed karem
 */

#ifndef IIC_PRIVATE_H_
#define IIC_PRIVATE_H_
#define START_ACK       0x08
#define REP_START_ACK   0x10
#define SLAVE_ADD_AND_WR_ACK  0x18
#define SLAVE_ADD_AND_RD_ACK  0x40
#define MSTR_WR_BYTE_ACK      0x28
#define MSTR_RD_BYTE_WITH_ACK 0x50

#define SLAVE_ADD_RCVD_RD_REQ     0xA8
#define SLAVE_ADD_RCVD_WR_REQ     0x60

#define SLAVE_DATA_RECIEVED       0x80
#define SLAVE_BYTE_TRANSMITTED    0xB8


#endif /* IIC_PRIVATE_H_ */
