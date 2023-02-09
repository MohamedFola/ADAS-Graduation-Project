#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*Interrupt IDs to pass in interrupt number*/
#define WATCH_DOG				0
#define PVD						1
#define TAMPER					2
#define RTC						3
#define FLASH					4
#define RCC						5
#define EXTI0					6
#define EXTI1					7
#define EXTI2					8
#define EXTI3					9
#define EXTI4					10
#define ADC						18
#define CANRX1					21
#define CANSCE					22
#define EXTI9_5					23
#define TIM1_BRK				24
#define TIM1_UP					25
#define TIM1_TRG_COM			26
#define TIM1_CC					27
#define TIM2					28
#define TIM3					29
#define TIM4					30
#define I2C1_EV					31
#define I2C1_ER					32
#define I2C2_EV					33
#define I2C2_ER					34
#define SPI1					35
#define SPI2					36
#define USART1					37
#define USART2					38
#define USART3					39


/*Functions to Enable or Disable NVIC Interrupt*/
u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber);

u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber);

/*Function for testing and debugging by Writing or Clearing pending flag of peripherals*/
u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8ClrPendingFlag(u8 Copy_u8IntNumber);

/*Function to get active flag bit of interrupts*/
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber, u8* Copy_u8ActiveFlagReading);


/*Options to be passed in SetPriority Function to decide how many groups and subgroups*/
#define FIRST_GROUP			0x05FA0300		/*You can access 4 bits to make groups only*/
#define SECOND_GROUP 		0x05FA0400		/*You can access 3 bits to make groups and 1 bit to subgroup*/
#define THIRD_GROUP			0x05FA0500		/*You can access 2 bits to make groups and 2 bits to subgroup*/
#define FOURTH_GROUP		0x05FA0600		/*You can access 1 bits to make groups and 3 bits to subgroup*/
#define FIFTH_GROUP			0x05FA0700		/*You can access 4 bits to make subgroups only*/

/*Function to set the priority of the interrupt*/
u8 MNVIC_u8SetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubGroupPriority, u32 Copy_u32PriorityMode);


#endif
