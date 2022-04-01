/*
 * locker.c
 *
 *  Created on: Mar 29, 2022
 *      Author: mohamed karem
 */


#include "locker.h"
#include<util/delay.h>
#define F_CPU 8000000UL

void System_init()
{
	keypad_voidInit();
	BuzzerINIT();
	EEPROM_Init();
	LCD_voidINST();
	LED_INIT();
}

void checkMemory()
{
	/* Read memory locations that hold the password */
	u8 data[4];
	EEPROM_ReadData(10,&data[0]);

	EEPROM_ReadData(11,&data[1]);

	EEPROM_ReadData(12,&data[2]);

	EEPROM_ReadData(13,&data[3]);

	/* First time to use EEPROM default values are 255. Make initial password to be 0000 */
	//if ((data[0] == 255) && (data[1] == 255) && (data[2] == 255) && (data[3] == 255))
	{
		EEPROM_WriteData(10, '0');
		EEPROM_WriteData(11, '0');
		EEPROM_WriteData(12, '0');
		EEPROM_WriteData(13,'0');
	}
}

u8 enterPassword ()
{
	u8 passwordEntered [4], passwordSaved [4];

	/* Get the 4 chars of the password from keypad */
	for(u8 t = 0; t < 4; t++)
	{
		u8 key = '$';

		l1:key=keypad_u8GetPressedkey();
		if(key == '$') { goto l1;}

		passwordEntered[t] = key;
		_delay_ms(100);
		LCD_voidsendDATA('*');
	}

	_delay_ms(1000);
	LCD_voidsendcommand(0x01);

	/* Read memory locations that hold the saved password */
	 EEPROM_ReadData(10,&passwordSaved [0]);
	 EEPROM_ReadData(11,&passwordSaved [1]);
	 EEPROM_ReadData(12,&passwordSaved [2]);
	 EEPROM_ReadData(13,&passwordSaved [3]);

	/* Password entered is the same as the password saved before */
	if ((passwordSaved [0] == passwordEntered [0]) && (passwordSaved [1] == passwordEntered [1]) &&
		(passwordSaved [2] == passwordEntered [2]) && (passwordSaved [3] == passwordEntered [3]))
	{
		/* There is NO error! */
		return 0;
	}
	/* There IS error! */
	return 1;
}

void changePassword ()
{
	u8 newPassword [4];

	/* Get the new 4 chars of the password from keypad */
	for(u8 t = 0; t < 4; t++)
	{
		u8 key = '$';
		while (key == '$')	{key = keypad_u8GetPressedkey();}
		newPassword[t] = key;
		LCD_voidsendDATA('*');
		_delay_ms(100);
	}
	_delay_ms(1000);
	LCD_voidsendcommand(0x01);

	/* Write new password to memory locations holding password */
	EEPROM_WriteData(10,newPassword[0]);
	EEPROM_WriteData(11,newPassword[1]);
	EEPROM_WriteData(12,newPassword[2]);
	EEPROM_WriteData(13,newPassword[3]);
}

u8 takeOpenLockerActions()
{
	/* Get key pressed on keypad to select action accordingly */
	u8 key = '$';
	while (key == '$')	key =keypad_u8GetPressedkey();

	/* '*' Sign on keypad maps to "Change Password" */
	if (key == '*')
	{
		Buzzer_3_sec();
		changePassword();
		LCD_voidsendstring("to confirm pwd *");
		_delay_ms(1000);
			LCD_voidsendcommand(0x01);
		key = '$';
		/* Press '*' again to confirm inserting password */
		while (key != '*')	key = keypad_u8GetPressedkey();

		key = '$';
		LCD_voidsendstring("to close door D ");
		_delay_ms(1000);
			LCD_voidsendcommand(0x01);
		/* Press 'D' to close locker */
		while (key !='D')	key = keypad_u8GetPressedkey();
		/* Locker is now closed */
		return 1;
	}

	/* Any other key pressed, activates the buzzer */
	else
	{

		{ if (key == 'D')	/* Locker is now closed */
				return 1;}
		Buzzer_100_ms();
		/* Locker is now open */
		return 0;
	}
}
