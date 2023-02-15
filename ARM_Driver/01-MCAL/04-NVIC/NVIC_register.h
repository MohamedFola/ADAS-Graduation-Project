#ifndef NVIC_REGISTER_H
#define NVIC_REGISTER_H

/*NVIC Registers*/
#define NVIC_BASE_ADDRESS		0xE000E100

#define NVIC_ISER0				*((volatile u32*)(NVIC_BASE_ADDRESS+0x000))          /*Enable External Interrupts from 0 to 31*/
#define NVIC_ISER1				*((volatile u32*)(NVIC_BASE_ADDRESS+0x004))          /*Enable External Interrupts from 32 to 63*/
#define NVIC_ISER2				*((volatile u32*)(NVIC_BASE_ADDRESS+0x008))

#define NVIC_ICER0				*((volatile u32*)(NVIC_BASE_ADDRESS+0x080))          /*Disable External Interrupts from 0 to 31*/
#define NVIC_ICER1				*((volatile u32*)(NVIC_BASE_ADDRESS+0x084))          /*Disable External Interrupts from 32 to 63*/
#define NVIC_ICER2				*((volatile u32*)(NVIC_BASE_ADDRESS+0x088))

#define NVIC_ISPR0				*((volatile u32*)(NVIC_BASE_ADDRESS+0x100))          /*Enable Pending flags of Interrupts from 0 to 31*/
#define NVIC_ISPR1				*((volatile u32*)(NVIC_BASE_ADDRESS+0x104))          /*Enable Pending flags of Interrupts from 32 to 63*/
#define NVIC_ISPR2				*((volatile u32*)(NVIC_BASE_ADDRESS+0x108))

#define NVIC_ICPR0				*((volatile u32*)(NVIC_BASE_ADDRESS+0x180))          /*Disable Pending flags of Interrupts from 0 to 31*/
#define NVIC_ICPR1				*((volatile u32*)(NVIC_BASE_ADDRESS+0x184))          /*Disable Pending flags of Interrupts from 32 to 63*/
#define NVIC_ICPR2				*((volatile u32*)(NVIC_BASE_ADDRESS+0x188))

#define NVIC_IABR0				*((volatile u32*)(NVIC_BASE_ADDRESS+0x200))          /*Read Active flags of Interrupts from 0 to 31*/
#define NVIC_IABR1				*((volatile u32*)(NVIC_BASE_ADDRESS+0x204))          /*Read Active flags of Interrupts from 32 to 63*/
#define NVIC_IABR2				*((volatile u32*)(NVIC_BASE_ADDRESS+0x208))

#define NVIC_IPR				((volatile u8*)(NVIC_BASE_ADDRESS+0X300))

#define NVIC_STIR 				*((volatile u32*)(NVIC_BASE_ADDRESS+0xE00))


#endif
