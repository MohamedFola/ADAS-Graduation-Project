#ifndef NVIC_REGISTER_H
#define NVIC_REGISTER_H

#define NVIC_BASE_ADDRESS		0xE000E100

typedef struct
{
	u32 ISER0;		/*Enable External Interrupts from 0 to 31*/
	u32 ISER1;		/*Enable External Interrupts from 32 to 63*/
	u32 ISER2;
	u32 ICER0;		/*Disable External Interrupts from 0 to 31*/
	u32 ICER1;		/*Disable External Interrupts from 32 to 63*/
	u32 ICER2;
	u32 ISPR0;		/*Enable Pending flags of Interrupts from 0 to 31*/
	u32 ISPR1;		/*Enable Pending flags of Interrupts from 32 to 63*/
	u32 ISPR2;
	u32 ICPR0;      /*Disable Pending flags of Interrupts from 0 to 31*/
	u32 ICPR1;      /*Disable Pending flags of Interrupts from 32 to 63*/
	u32 ICPR2;
	u32 IABR0;		/*Read Active flags of Interrupts from 0 to 31*/
	u32 IABR1;		/*Read Active flags of Interrupts from 32 to 63*/
	u32 IABR2;
}NVIC_MemMap_t;

#define NVIC					((volatile NVIC_MemMap_t*)(NVIC_BASE_ADDRESS))

#define NVIC_IPR				((volatile u8*)(NVIC_BASE_ADDRESS+0X300))
#define NVIC_STIR 				*((volatile u32*)(NVIC_BASE_ADDRESS+0xE00))


/*System Control Block Registers*/
#define SCB_BASE_ADDRESS		0xE000ED00

#define SCB_ACTLR				*((volatile u32*)(SCB_BASE_ADDRESS))

typedef struct
{
	u32 CPUID;
	u32 ICSR;
	u32 VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3;
	u32 SHCRS;
	u32 CFSR;
	u32 HFSR;
	u32 MMAR;
	u32 BFAR;
}SCB_MemMap_t;

#define SCB						((volatile SCB_MemMap_t*)(SCB_BASE_ADDRESS))

#endif
