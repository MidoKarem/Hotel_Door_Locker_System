#include "../../library/bitmath.h"
#include "../../library/STD_types.h"
#include "DIO_interface.h"
#include "DIO_register.h"




void DIO_voidsetportdirection(u8 copy_u8port,u8  copy_u8portdirection)
{
	switch(copy_u8port)
	{
	case DIO_u8PORTA: DDRA = copy_u8portdirection;break;
	case DIO_u8PORTB: DDRB =copy_u8portdirection;break;
	case DIO_u8PORTC: DDRC = copy_u8portdirection;break;
	case DIO_u8PORTD: DDRD = copy_u8portdirection;break;
	default:  break;
	}
}
void DIO_voidsetpindirection(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8direction)
{
	if(copy_u8pin <= DIO_u8PIN7)
	{
		if(copy_u8direction==DIO_u8PIN_INPUT)
		{
			switch(copy_u8port)
			{
			case DIO_u8PORTA: CLR_BIT(DDRA, copy_u8pin);break;
			case DIO_u8PORTB: CLR_BIT(DDRB, copy_u8pin);break;
			case DIO_u8PORTC: CLR_BIT(DDRC, copy_u8pin);break;
			case DIO_u8PORTD: CLR_BIT(DDRD, copy_u8pin);break;
			default: break;
			}

		}
		else if(copy_u8direction==DIO_u8PIN_OUTPUT)
		{
			switch(copy_u8port)
			{
			case DIO_u8PORTA: SET_BIT(DDRA, copy_u8pin);break;
			case DIO_u8PORTB: SET_BIT(DDRB, copy_u8pin);break;
			case DIO_u8PORTC: SET_BIT(DDRC, copy_u8pin);break;
			case DIO_u8PORTD: SET_BIT(DDRD, copy_u8pin);break;
			default:  break;

			}
		}
		else
		{
			/*u8 Local_Errorstate=1;*/
	}

}
	else
	{
		/*u8 Local_Errorstate=1;*/

	}
}
void DIO_voidsetportvalue(u8 copy_u8port,u8 copy_u8value)
{
	/*u8 Local_Errorstate=0;*/
	switch(copy_u8port)
	{
	case DIO_u8PORTA: PORTA= copy_u8value;break;
	case DIO_u8PORTB: PORTB= copy_u8value;break;
	case DIO_u8PORTC: PORTC= copy_u8value;break;
	case DIO_u8PORTD: PORTD= copy_u8value;break;
	default:  break; /*u8 Local_Errorstate=1;*/    //when using error checking
	}
/*u8 return Local_u8Errorstate;*/
}
void DIO_voidsetpinvalue(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8value)
{
if(copy_u8pin <= DIO_u8PIN7)
{
	if(copy_u8value==DIO_u8PIN_LOW)
	{
		switch(copy_u8port)
		{
		case DIO_u8PORTA: CLR_BIT(PORTA, copy_u8pin);break;
		case DIO_u8PORTB: CLR_BIT(PORTB, copy_u8pin);break;
		case DIO_u8PORTC: CLR_BIT(PORTC, copy_u8pin);break;
		case DIO_u8PORTD: CLR_BIT(PORTD, copy_u8pin);break;
		default:  break;
		}
	}
	else if(copy_u8value==DIO_u8PIN_HIGH)
	{
		switch(copy_u8port)
		{
		case DIO_u8PORTA: SET_BIT(PORTA, copy_u8pin);break;
		case DIO_u8PORTB: SET_BIT(PORTB, copy_u8pin);break;
		case DIO_u8PORTC: SET_BIT(PORTC, copy_u8pin);break;
		case DIO_u8PORTD: SET_BIT(PORTD, copy_u8pin);break;
		default:  break;

		}
	}
	else
	{
		/*u8 Local_Errorstate=1;*/   //when using error checking

	}
}
else
{
	/*u8 Local_Errorstate=1;*/     //when using error checking
}
/*return Local_u8Errorstate;*/     //when using error checking
}
u8 DIO_u8getpinvalue(u8 copy_u8port,u8 copy_u8pin)
{
	u8 Local_u8pinvalue= Null;
	switch(copy_u8port)
	{
	case DIO_u8PORTA: Local_u8pinvalue= GET_BIT(PINA, copy_u8pin);break;
	case DIO_u8PORTB: Local_u8pinvalue= GET_BIT(PINB, copy_u8pin);break;
	case DIO_u8PORTC: Local_u8pinvalue= GET_BIT(PINC, copy_u8pin);break;
	case DIO_u8PORTD: Local_u8pinvalue= GET_BIT(PIND, copy_u8pin);break;
	}
	return Local_u8pinvalue;


}



