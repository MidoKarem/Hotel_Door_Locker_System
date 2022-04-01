/*
 * Buzzer.h
 *
 *  Created on: Mar 29, 2022
 *      Author: mohamed karem
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include"../../library/STD_types.h"
#include"../../library/bitmath.h"
#include"../../MCAL//DIO_driver/DIO_interface.h"

#define Buzzer_port_INIT()   DIO_voidsetpindirection(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_OUTPUT);
#define Buzzer_on()          DIO_voidsetpinvalue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
#define Buzzer_off()         DIO_voidsetpinvalue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);

void BuzzerINIT();
void Buzzer_3_sec();
void Buzzer_100_ms();




#endif /* BUZZER_H_ */
