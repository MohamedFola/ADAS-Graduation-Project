#include "../../00-LIB/STD_TYPES.h"

#include "../../01-MCAL/00-RCC/RCC_interface.h"
#include "../../01-MCAL/02-DIO/DIO_interface.h"
#include "../../01-MCAL/04-NVIC/NVIC_interface.h"
#include "../../01-MCAL/03-STK/STK_interface.h"
#include "../../01-MCAL/08-TIM/TIM_interface.h"
#include "../../01-MCAL/10-PWM/PWM_interface.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_private.h"
#include "ULTRASONIC_interface.h"

void HULTRASONIC_voidInit(Ultrasonic_t* Copy_Sensor)
{
	/*ICU Configurations*/
	switch(Copy_Sensor->Echo_ICU_TIM)
	{
	case TIM2:	MTIM2_voidConfigICU(); break;
	case TIM3:	MTIM3_voidConfigICU(); break;
	case TIM4:	MTIM4_voidConfigICU(); break;
	}
}

void HULTRASONIC_voidGetDistance(Ultrasonic_t* Copy_Sensor,u32* Copy_u8SensorDistance)
{
	/*Local variables to recieve On ticks and Period Ticks*/
	f32 Local_u32Time_ms=0;
	u16 Local_u16OnTicks = 0;
	u16 Local_u16PeriodTicks = 0;

	/**************************************************************************/
	/***********************Generating Pulse on Trig Pin***********************/
	/**************************************************************************/

	/*Generate Low signal for 2 microseconds*/
	MDIO_u8WriteChannel(Copy_Sensor->TrigPort, Copy_Sensor->TrigPin, MDIO_PIN_LOW);
	MSTK_voidSetBusyWait((2)US);
	/*Generate High signal for 2 microseconds*/
	MDIO_u8WriteChannel(Copy_Sensor->TrigPort, Copy_Sensor->TrigPin, MDIO_PIN_HIGH);
	MSTK_voidSetBusyWait((10)US);
	/*Clear bit again*/
	MDIO_u8WriteChannel(Copy_Sensor->TrigPort, Copy_Sensor->TrigPin, MDIO_PIN_LOW);


	/**************************************************************************/
	/********************Capture the echo signal with ICU**********************/
	/**************************************************************************/

	switch(Copy_Sensor->Echo_ICU_TIM)
	{
	case TIM2:	MTIM2_u8ICU(&Local_u16PeriodTicks, &Local_u16OnTicks); break;
	case TIM3:	MTIM3_u8ICU(&Local_u16PeriodTicks, &Local_u16OnTicks); break;
	case TIM4:	MTIM4_u8ICU(&Local_u16PeriodTicks, &Local_u16OnTicks); break;
	}

	/**************************************************************************/
	/*******************Calculating the distance from ICU**********************/
	/**************************************************************************/


	// Speed of sound = 343 mm/ms

	Local_u32Time_ms=Local_u16OnTicks*10;
	*Copy_u8SensorDistance =((((Local_u32Time_ms*0.000343)/2)*10)+20);


}
