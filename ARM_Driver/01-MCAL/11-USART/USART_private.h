/*********************************************************************************************************/
/************************************    Author:Mohab Ahmed    	      ************************************/
/************************************		Layer:MCAL            ************************************/
/************************************   	SWC:USART             ************************************/
/************************************		Version:1.00          ************************************/
/*********************************************************************************************************/
#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define USART1_BASE_ADDRESS		0x40013800
#define USART2_BASE_ADDRESS    		0x40004400
#define USART3_BASE_ADDRESS		0x40004800

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_t;


#define USART_1 	((volatile USART_t*)(USART1_BASE_ADDRESS))
#define USART_2 	((volatile USART_t*)(USART2_BASE_ADDRESS))
#define USART_3 	((volatile USART_t*)(USART3_BASE_ADDRESS))

/****************SR*************/
#define  USART_TXE 		7
#define  USART_TC 		6
#define  USART_RXNE 		5
#define  USART_IDLE 		4
#define  USART_ORE 		3
#define  USART_NE 		2
#define  USART_FE 		1
#define  USART_PE 		0
/****************CR1*************/
#define USART_UE		13
#define USART_M			12
#define USART_WAKE		11
#define USART_PCE		10
#define USART_PS		9
#define USART_PEIE		8
#define USART_TXEIE		7
#define USART_TCIE		6
#define USART_RXNEIE		5
#define USART_IDLEIE		4
#define USART_TE		3
#define USART_RE		2
#define USART_RWU		1
#define USART_SBK		0
/****************CR2*************/
#define USART_STOP1		13
#define USART_STOP0		12
#define USART_CLKEN		11
#define USART_CPOL		10
#define USART_CPHA		9

#define CLOCK_FREQ		8000000UL
#endif /* USART_PRIVATE_H_ */
