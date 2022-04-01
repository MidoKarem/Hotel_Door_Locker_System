/*
 * main.c
 *
 *  Created on: Mar 29, 2022
 *      Author: mohamed karem
 */


#include "app/locker.h"
#include<util/delay.h>
#define F_CPU 8000000UL

int main(void)
{
	System_init();							// Initialize system modules
	LCD_voidsendstring("Welcome");
	_delay_ms(1000);
	LCD_voidsendcommand(0x01);
	u8 locker_closed = 1;					// Variable holds the state of the locker whether open or closed
	checkMemory();							// Set initial password valid only if this is first time to use
	LCD_voidsendstring("Enter init code");
		_delay_ms(1000);
		LCD_voidsendcommand(0x01);

	u8 errorStatus = enterPassword();				// Enter password to open the locker
	while (errorStatus)						// Locker remains closed until user enters correct password
	{
		Buzzer_3_sec();						// Activate buzzer for 3 seconds
		errorStatus = enterPassword();				// Enter password to open the locker
	}
	locker_closed = 0;						// locker is now open

	while(1)
    {
		if(!locker_closed)
		{   LED_ON();
			LCD_voidsendstring("Door is open");
		     _delay_ms(1000);
		   LCD_voidsendcommand(0x01);
								// LED ON indicates open locker
			LCD_voidsendstring("to change code *");
			 LCD_voidGoToXY(0,1);
			 LCD_voidsendstring("to close door D");
			 _delay_ms(1000);
			LCD_voidsendcommand(0x01);
			locker_closed = takeOpenLockerActions();	// Change password & activate buzzer if pressing wrong keys
		}

		else
		{
			LED_OFF();
			 LCD_voidsendcommand(0x01);
			LCD_voidsendstring("Door is closed");
			 _delay_ms(1000);
			 LCD_voidsendcommand(0x01);
								// LED OFF indicates closed locker
			_delay_ms(100);
			LCD_voidsendstring("Enter password");
			 LCD_voidGoToXY(0,1);

			errorStatus = enterPassword();			// Enter password to open the locker
			while (errorStatus) 				// Locker remains closed until user enters correct password
			{
				Buzzer_3_sec();				// Activate buzzer for 3 seconds
				errorStatus = enterPassword();		// Enter password to open the locker
			}
			locker_closed = 0; 				// locker is now open
		}
	}
}
