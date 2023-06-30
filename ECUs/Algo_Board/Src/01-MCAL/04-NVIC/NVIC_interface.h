#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*Interrupt IDs to pass in interrupt number*/
#define NVIC_WATCH_DOG				0
#define NVIC_PVD					1
#define NVIC_TAMPER					2
#define NVIC_RTC					3
#define NVIC_FLASH					4
#define NVIC_RCC					5
#define NVIC_EXTI0					6
#define NVIC_EXTI1					7
#define NVIC_EXTI2					8
#define NVIC_EXTI3					9
#define NVIC_EXTI4					10
#define NVIC_ADC					18
#define NVIC_CANRX1					21
#define NVIC_CANSCE					22
#define NVIC_EXTI9_5				23
#define NVIC_TIM1_BRK				24
#define NVIC_TIM1_UP				25
#define NVIC_TIM1_TRG_COM			26
#define NVIC_TIM1_CC				27
#define NVIC_TIM2					28
#define NVIC_TIM3					29
#define NVIC_TIM4					30
#define NVIC_I2C1_EV				31
#define NVIC_I2C1_ER				32
#define NVIC_I2C2_EV				33
#define NVIC_I2C2_ER				34
#define NVIC_SPI1					35
#define NVIC_SPI2					36
#define NVIC_USART1					37
#define NVIC_USART2					38
#define NVIC_USART3					39


/**/

/*Functions to Enable or Disable NVIC Interrupt*/
u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber);

u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber);

/*Function for testing and debugging by Writing or Clearing pending flag of peripherals*/
u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8ClrPendingFlag(u8 Copy_u8IntNumber);

/*Function to get active flag bit of interrupts*/
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber, u8* Copy_u8ActiveFlagReading);

/*Function to set the priority of the interrupt*/
u8 MNVIC_u8SetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubGroupPriority);


#endif
