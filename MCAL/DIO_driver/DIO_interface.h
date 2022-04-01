#ifndef DIO_interface_h_
#define DIO_interface_h_

void DIO_voidsetportdirection(u8 copy_u8port,u8 copy_u8direction);
void DIO_voidsetpindirection(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8direction);
void DIO_voidsetportvalue(u8 copy_u8port,u8 copy_u8value);
void DIO_voidsetpinvalue(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8value);
u8 DIO_u8getpinvalue(u8 copy_u8port,u8 copy_u8pin);


#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7

#define DIO_u8PIN_INPUT 0
#define DIO_u8PIN_OUTPUT 1

#define DIO_u8PORT_INPUT 0x00
#define DIO_u8PORT_OUTPUT 0xff

#define DIO_u8PIN_HIGH 1
#define DIO_u8PIN_LOW 0

#define DIO_u8PORT_HIGH 0xff
#define DIO_u8PORT_LOW 0x00



#endif





