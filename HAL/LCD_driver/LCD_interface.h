/*
 * LCD_interface.h
 *
 *  Created on: Nov 5, 2021
 *      Author: mohamed karem
 */

#ifndef HAL_LCD_DRIVER_LCD_INTERFACE_H_
#define HAL_LCD_DRIVER_LCD_INTERFACE_H_
void LCD_voidsendcommand(u8 copy_u8command);
void LCD_voidsendDATA(u8 copy_u8DATA);
void LCD_voidINST(void);
void LCD_voidsendstring(char* copy_u8string);



#endif /* HAL_LCD_DRIVER_LCD_INTERFACE_H_ */

