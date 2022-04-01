/*
 * locker.h
 *
 *  Created on: Mar 30, 2022
 *      Author: mohamed karem
 */

#ifndef APP_LOCKER_H_
#define APP_LOCKER_H_

#include "../HAL/Buzzer_driver/Buzzer.h"
#include "../HAL/Keypad_driver/keypad_interface.h"
#include "../HAL/LCD_driver/LCD_interface.h"
#include "../HAL/EXT_EEPROM/EXT_EEPROM_interface.h"

/* LED PA1 */
#define LED_INIT()		DIO_voidsetpindirection(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_OUTPUT);
#define LED_ON()		DIO_voidsetpinvalue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);
#define LED_OFF()		DIO_voidsetpinvalue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);


/*
 * Function: Initialize system modules
 * Parameter: no input
 * Output: no return
 */
void System_init();

/*
 * Function: Set initial password to certain EEPROM addresses valid only if this is first time to use
 * Parameter: no input
 * Output: no return
 */
void checkMemory();

/*
 * Function: Change password of locker
 * Parameter: no input
 * Output: no return
 */
void changePassword();

/*
 * Function: Enter password to open the locker
 * Parameter: no input
 * Output: [uint8_t] password correct or not
 */
u8 enterPassword();

/*
 * Function: Take actions on locker when it's open like changing
 *			 password & activate buzzer if pressing wrong keys.
 * Parameter: no input
 * Output: [uint8_t] locker status. 0: Open		1: Closed
 */
u8 takeOpenLockerActions();


#endif /* APP_LOCKER_H_ */
