/*
 * Buzzer.c
 *
 *  Created on: Mar 29, 2022
 *      Author: mohamed karem
 */
#include"Buzzer.h"
#include"../../library/STD_types.h"
#include"../../library/bitmath.h"
#include"../../MCAL//DIO_driver/DIO_interface.h"
#include<util/delay.h>
#define F_CPU 8000000UL
void BuzzerINIT()
{
	Buzzer_port_INIT();
}

void Buzzer_3_sec()
{
	Buzzer_on();
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);
	Buzzer_off();
	_delay_ms(100);

}
void Buzzer_100_ms()
{
	Buzzer_on();
	_delay_ms(100);
	Buzzer_off();
	_delay_ms(10);
}
