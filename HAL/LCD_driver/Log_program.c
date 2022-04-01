/***************************************************************/
/* Author    : Ahmed Assaf                                     */
/* Version   : V01                                             */
/***************************************************************/

// *
// *  Created on: Nov 5, 2021
// *      Author: mohamed karem
// */
//
#include"../../library/STD_types.h"
#include"../../library/bitmath.h"
#include "LCD_interface.h"
#include "Log_interface.h"


void Log_voidPrintString(u8 Copy_u8ptr[])
{

	while(*Copy_u8ptr != '\0')
	{
		 LCD_voidsendDATA(*Copy_u8ptr);
		Copy_u8ptr++;
	}
}

/***************************************************************/
/* Author    : Ahmed Assaf                                     */
/* Version   : V01                                             */
/***************************************************************/

void Log_voidPrintNumber(u16 Copy_u16Val)
{
	u8 Local_u8Factor;

	if (Copy_u16Val >= (u16)10000)
	{
		Local_u8Factor = (u8)(Copy_u16Val / (u16) 10000);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u16)10000);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 1000);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u16)1000);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 100);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u8)100);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 10);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Local_u8Factor = Copy_u16Val - (u16)(Local_u8Factor * (u8)10);
		 LCD_voidsendDATA(Local_u8Factor+48);

	}

	else if (Copy_u16Val >= (u16) 1000 )
	{
		Local_u8Factor = (u8)(Copy_u16Val / (u16) 1000);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u16)1000);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 100);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u8)100);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 10);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Local_u8Factor = Copy_u16Val - (u16)(Local_u8Factor * (u8)10);
		 LCD_voidsendDATA(Local_u8Factor+48);
	}

	else if (Copy_u16Val >= (u8)100 )
	{
		Local_u8Factor = (u8)(Copy_u16Val / (u16) 100);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Copy_u16Val = Copy_u16Val - (u16)(Local_u8Factor * (u8)100);

		Local_u8Factor = (u8)(Copy_u16Val / (u16) 10);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Local_u8Factor = Copy_u16Val - (u16)(Local_u8Factor * (u8)10);
		 LCD_voidsendDATA(Local_u8Factor+48);
	}

	else if (Copy_u16Val >= (u8) 10 )
	{
		Local_u8Factor = (u8)((u8)Copy_u16Val / (u8) 10);
		 LCD_voidsendDATA(Local_u8Factor+48);
		Local_u8Factor = Copy_u16Val - (u16)(Local_u8Factor * (u8)10);
		 LCD_voidsendDATA(Local_u8Factor+48);
	}

	else
	{
		 LCD_voidsendDATA(Copy_u16Val+48);
	}
}
