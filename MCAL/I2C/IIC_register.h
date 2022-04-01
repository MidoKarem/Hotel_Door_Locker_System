/*
 * IIC_register.h
 *
 *  Created on: Feb 11, 2022
 *      Author: mohamed karem
 */

#ifndef IIC_REGISTER_H_
#define IIC_REGISTER_H_

#define TWDR  *((volatile u8*)0x23)
#define TWAR  *((volatile u8*)0x22)
#define TWAR_TWGCE

#define TWSR  *((volatile u8*)0x21)
#define TWSR_TWPS1  1
#define TWSR_TWPS0  0

#define TWBR  *((volatile u8*)0x20)

#define TWCR  *((volatile u8*)0x56)
#define TWCR_TWINT  7    //interrupt flag
#define TWCR_TWEA   6    //
#define TWCR_TWSTA  5
#define TWCR_TWSTO  4
#define TWCR_TWWC   3
#define TWCR_TWEN   2    //
#define TWCR_TWIE   0    //interrupt enable
#endif /* IIC_REGISTER_H_ */
