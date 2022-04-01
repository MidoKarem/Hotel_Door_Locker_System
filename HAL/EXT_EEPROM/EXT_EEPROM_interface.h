/*
 * EXT_EEPROM_interface.h
 *
 *  Created on: Feb 19, 2022
 *      Author: mohamed karem
 */

#ifndef EXT_EEPROM_INTERFACE_H_
#define EXT_EEPROM_INTERFACE_H_



void EEPROM_Init(void);

void EEPROM_WriteData(u8 loc, u8 data);
void EEPROM_ReadData(u8 loc, u8* data);


#endif /* EXT_EEPROM_INTERFACE_H_ */
