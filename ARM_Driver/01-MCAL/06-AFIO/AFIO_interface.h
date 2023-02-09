#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H


/*Port selection used in configuration of external interrupt*/
#define PORTA			0b0000
#define PORTB			0b0001
#define PORTC			0b0010

/*Configure External Interrupt*/
void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line , u8 Copy_u8PortSelection);


#endif
