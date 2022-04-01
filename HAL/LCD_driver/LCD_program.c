///*

//* LCD_program.c
// *
// *  Created on: Nov 5, 2021
// *      Author: mohamed karem
// */
//
#include"../../library/STD_types.h"
#include"../../library/bitmath.h"
#define F_CPU 8000000UL
#include"../../MCAL//DIO_driver/DIO_interface.h"

#include"LCD_interface.h"
#include"LCD_config.h"
#include"LCD_private.h"

#include<util/delay.h>

	void LCD_voidsendcommand(u8 copy_u8command)
	{
		/*set RS low to enable command*/
		DIO_voidsetpinvalue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8PIN_LOW);
/*set RW low to enable write mode*/
	DIO_voidsetpinvalue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8PIN_LOW);
/*set DATA port to send command*/
	DIO_voidsetportvalue(LCD_DATA_PORT,copy_u8command);
/*enable pulse*/


	DIO_voidsetpinvalue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8PIN_HIGH);

	_delay_ms(2);
	DIO_voidsetpinvalue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8PIN_LOW);
		_delay_ms(2);
	}



	void LCD_voidsendDATA(u8 copy_u8DATA)
	{
	//	/*set RS high to enable command*/
		DIO_voidsetpinvalue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8PIN_HIGH);
		/*set RW low to enable write mode*/
		DIO_voidsetpinvalue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8PIN_LOW);
	//	/*set data port to send DATA*/
		DIO_voidsetportvalue(LCD_DATA_PORT, copy_u8DATA);
	//	/*enable pulse*/


		DIO_voidsetpinvalue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_voidsetpinvalue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8PIN_LOW);

				_delay_ms(2);


	}
	void LCD_voidINST(void)
	{
		DIO_voidsetportdirection(LCD_CONTROL_PORT,DIO_u8PORT_OUTPUT);
		DIO_voidsetportdirection(LCD_DATA_PORT,DIO_u8PORT_OUTPUT);
		/*wait more than 30us*/
		_delay_ms(35);
		/*Initialize LCD configuration to 2 lines, font size 5*8 */
		LCD_voidsendcommand(0b00111000);
		/* display ON/OFF control display enabled, cursor ON, blink enabled */
		LCD_voidsendcommand(0b00001111);
		/*Clear display command */
		LCD_voidsendcommand(0b0000001);
		_delay_ms(2);

	}



	void LCD_voidsendstring(char* copy_u8string)
	{
	u8 local_u8counter = 0;
	while(copy_u8string[local_u8counter] !='\0')
	{
		LCD_voidsendDATA(copy_u8string[local_u8counter]);
		local_u8counter++;
	}
	}

void LCD_voidGoToXY(u8 copy_u8Xpos,u8 copy_u8Ypos)
{
	u8 local_u8position;
	if(copy_u8Ypos==0)
	{
		local_u8position=copy_u8Xpos;

	}
	else if(copy_u8Ypos==1)
	{
		local_u8position=copy_u8Xpos+0x40;
	}
	LCD_voidsendcommand(local_u8position+128);
}





