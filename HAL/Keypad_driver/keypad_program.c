/*

 * keypad_program.c
 *
 *  Created on: Nov 12, 2021
 *      Author: mohamed karem
 */
#include"../../library/STD_types.h"
#include"../../library/bitmath.h"
#include"../../MCAL//DIO_driver/DIO_interface.h"
#include "../Keypad_driver/keypad__private.h"
#include "../Keypad_driver/keypad_config.h"
#include "../Keypad_driver/keypad_interface.h"
#define F_CPU 8000000UL
#include<util/delay.h>
u8 keypad_Array[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'D','0','=','+'}};
void keypad_voidInit(void)
{

// set 4 pins as outputs for columns
	DIO_voidsetpindirection(keypad_PORT,keypad_COLUM1_PIN,DIO_u8PIN_OUTPUT);
	DIO_voidsetpindirection(keypad_PORT,keypad_COLUM2_PIN,DIO_u8PIN_OUTPUT);
	DIO_voidsetpindirection(keypad_PORT,keypad_COLUM3_PIN,DIO_u8PIN_OUTPUT);
	DIO_voidsetpindirection(keypad_PORT,keypad_COLUM4_PIN,DIO_u8PIN_OUTPUT);


	// set 4 pins as inputs for Rows
		DIO_voidsetpindirection(keypad_PORT,keypad_ROW1_PIN,DIO_u8PIN_INPUT);
		DIO_voidsetpindirection(keypad_PORT,keypad_ROW2_PIN,DIO_u8PIN_INPUT);
		DIO_voidsetpindirection(keypad_PORT,keypad_ROW3_PIN,DIO_u8PIN_INPUT);
		DIO_voidsetpindirection(keypad_PORT,keypad_ROW4_PIN,DIO_u8PIN_INPUT);


// set ROWS to be pull up resistor,colmns to 5v
		DIO_voidsetportvalue(keypad_PORT,0xFF);



}
u8 keypad_u8GetPressedkey(void)
{
	u8 local_u8Pressedkey='$';

    for(u8 Col_num=0;Col_num<4;Col_num++)
    {
    	DIO_voidsetpinvalue(keypad_PORT,Col_num, DIO_u8PIN_LOW);


    	for(u8 Row_num=4;Row_num<=7;Row_num++)
    	{


    		if(DIO_u8getpinvalue(keypad_PORT,Row_num)==DIO_u8PIN_LOW)
    		{
    			local_u8Pressedkey= keypad_Array[Row_num-4][Col_num];
    			while(DIO_u8getpinvalue(keypad_PORT,Row_num)==DIO_u8PIN_LOW);
    			_delay_ms(20);
    			break;

    		}

    	}

    	DIO_voidsetpinvalue(keypad_PORT,Col_num, DIO_u8PIN_HIGH);

    }





	return local_u8Pressedkey;

}



