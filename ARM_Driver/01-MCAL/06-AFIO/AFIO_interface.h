#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H


/*Port selection used in configuration of external interrupt*/
#define MAFIO_PORTA			0b0000
#define MAFIO_PORTB			0b0001
#define MAFIO_PORTC			0b0010

/*Lines of Interrupts*/
#define MAFIO_EXTI_LINE0 		0
#define MAFIO_EXTI_LINE1 		1
#define MAFIO_EXTI_LINE2 		2
#define MAFIO_EXTI_LINE3 		3
#define MAFIO_EXTI_LINE4		4
#define MAFIO_EXTI_LINE5 		5
#define MAFIO_EXTI_LINE6 		6
#define MAFIO_EXTI_LINE7 		7
#define MAFIO_EXTI_LINE8 		8
#define MAFIO_EXTI_LINE9 		9
#define MAFIO_EXTI_LINE10 		10
#define MAFIO_EXTI_LINE11		11
#define MAFIO_EXTI_LINE12		12
#define MAFIO_EXTI_LINE13		13
#define MAFIO_EXTI_LINE14		14
#define MAFIO_EXTI_LINE15		15

/*Configure External Interrupt*/
void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line , u8 Copy_u8PortSelection);


#endif
