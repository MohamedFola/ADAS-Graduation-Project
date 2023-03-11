/**************************** Libraries ****************************/
#include "00-LIB/STD_TYPES.h"

/*************************** MCAL Drivers ***************************/
#include "01-MCAL/00-RCC/RCC_interface.h"
#include "01-MCAL/01-PORT/PORT_interface.h"
#include "01-MCAL/02-DIO/DIO_interface.h"
#include "01-MCAL/03-STK/STK_interface.h"
#include "01-MCAL/04-NVIC/NVIC_interface.h"
#include "01-MCAL/05-EXTI/EXTI_interface.h"
#include "01-MCAL/06-AFIO/AFIO_interface.h"
#include "01-MCAL/07-I2C/I2C_interface.h"
#include "01-MCAL/08-TIM/TIM_interface.h"
#include "01-MCAL/09-SPI/SPI_interface.h"
#include "01-MCAL/10-PWM/PWM_interface.h"

/*************************** HAL Drivers ***************************/
#include "02-HAL/00-ENC/ENC_interface.h"
#include "02-HAL/01-ULTRASOINC/ULTRASONIC_interface.h"

/*************************** Function Prototypes ***************************/
void InitPrg(void);
void ConfigPrg(void);


int main(void)
{
	/*Program Initialization*/
	InitPrg();
	/*Program Configuration*/
	ConfigPrg();

	while(1)
	{

	}
}

/*Function initialize all the peripherals needed in the program*/
void InitPrg(void)
{
	/**************************************************************************/
	/*************************** RCC Initialization ***************************/
	/**************************************************************************/
	RCC_voidInitSysClock();
	/*Enabling AFIO and GPIOs Clocks*/
	RCC_voidEnableClock(RCC_AFIO,  RCC_APB2);
	RCC_voidEnableClock(RCC_GPIOA, RCC_APB2);
	RCC_voidEnableClock(RCC_GPIOB, RCC_APB2);
	RCC_voidEnableClock(RCC_GPIOC, RCC_APB2);
	/*Enabling Timers Clocks*/
	RCC_voidEnableClock(RCC_TIM2,  RCC_APB1);
	RCC_voidEnableClock(RCC_TIM3,  RCC_APB1);
	RCC_voidEnableClock(RCC_TIM4,  RCC_APB1);
	/*Enabling SPI Clock*/
	RCC_voidEnableClock(RCC_SPI1,  RCC_APB2);
	/*Enabling I2C Clock*/
	RCC_voidEnableClock(RCC_I2C1,  RCC_APB1);

	/**************************************************************************/
	/*************************** Port Initialization **************************/
	/**************************************************************************/
	PORT_voidInit();

	/**************************************************************************/
	/************************ Systick Initialization **************************/
	/**************************************************************************/
	MSTK_voidClkSrcInit();

	/**************************************************************************/
	/*************************** I2C Initialization ***************************/
	/**************************************************************************/
	I2C_u8Init(I2C_1, I2C_SM);

	/**************************************************************************/
	/*************************** SPI Initialization ***************************/
	/**************************************************************************/
	SPI_u8MasterInit(Copy_u8SPI, Copy_u8DataOrder, Copy_u8ClockPolatrity, Copy_u8ClockPhase, Copy_u8ClockRate);
	SPI_u8SlaveInit(Copy_u8SPI, Copy_u8DataOrder, Copy_u8ClockPolatrity, Copy_u8ClockPhase);

	/**************************************************************************/
	/********************* TIM and PWM Initialization *************************/
	/**************************************************************************/
	/*Initialize Timers*/
	MTIM2_voidInit();
	MTIM3_voidInit();
	MTIM4_voidInit();
	/*Initialize PWMs*/
	MPWM2_voidInit();
	MPWM3_voidInit();
	MPWM4_voidInit();
}

/*Function configure all the peripherals needed in the program*/
void ConfigPrg(void)
{
	/**************************************************************************/
	/*************************** NVIC Configuration ***************************/
	/**************************************************************************/
	MNVIC_u8EnableInterrupt(NVIC_EXTI0);
	MNVIC_u8EnableInterrupt(NVIC_EXTI1);
	MNVIC_u8EnableInterrupt(NVIC_EXTI2);
	MNVIC_u8EnableInterrupt(NVIC_EXTI3);

}
