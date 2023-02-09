#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*Lines of Interrupts*/
#define LINE0 		0
#define LINE1 		1
#define LINE2 		2
#define LINE3 		3
#define LINE4		4
#define LINE5 		5
#define LINE6 		6
#define LINE7 		7
#define LINE8 		8
#define LINE9 		9
#define LINE10 		10
#define LINE11		11
#define LINE12		12
#define LINE13		13
#define LINE14		14
#define LINE15		15

/*External modes of interrupts*/
#define RISING_EDGE		0
#define FALLING_EDGE	1
#define ON_CHANGE		2


/*Initialization External Interrupt*/
void MEXTI_voidInit();

/*Enable or Disable External Interrupts by passing the line of the interrupt*/
u8 MEXTI_u8EnableEXTI(u8 Copy_u8Line);
u8 MEXTI_u8DisableEXTI(u8 Copy_u8Line);

/*Function to set Software trigger to the interrupt*/
u8 MEXTI_u8SwTrigger(u8 Copy_u8Line);

/*Function to change the mode of the interrupt during runtime */
u8 EXTI_u8SetSignalLatch(u8 Copy_u8Line, u8 Copu_u8Mode);

#endif
