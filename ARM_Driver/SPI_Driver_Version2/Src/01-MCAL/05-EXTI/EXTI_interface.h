#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*Lines of Interrupts*/
#define MEXTI_LINE0 		0
#define MEXTI_LINE1 		1
#define MEXTI_LINE2 		2
#define MEXTI_LINE3 		3
#define MEXTI_LINE4			4
#define MEXTI_LINE5 		5
#define MEXTI_LINE6 		6
#define MEXTI_LINE7 		7
#define MEXTI_LINE8 		8
#define MEXTI_LINE9 		9
#define MEXTI_LINE10 		10
#define MEXTI_LINE11		11
#define MEXTI_LINE12		12
#define MEXTI_LINE13		13
#define MEXTI_LINE14		14
#define MEXTI_LINE15		15

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
u8 MEXTI_u8SetSignalLatch(u8 Copy_u8Line, u8 Copu_u8Mode);

/*Setting Call back function will be called in ISR*/
u8 MEXTI_voidSetCallBackFunc(u8 Copy_u8Line, void (*Copy_pvNotificationFunc)(void));

#endif
