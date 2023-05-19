#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_MATH.h"
#include "00-LIB/Software_Delay.h"

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

#include "02-HAL/00-ENC/ENC_interface.h"
#include "02-HAL/01-ULTRASOINC/ULTRASONIC_interface.h"
#include "02-HAL/02-MOTOR/MOTOR_interface.h"

#define Spi_data_counter   4


int main ( void )
{
	SPI_t spi =
	{
			.SPI_Mode      = SPI_Master,
			.SPI_Number    = SPI1,
			.SPI_Phase     = SPI_ClkPhase_LeadingEdge,
			.SPI_Polartity = SPI_ClkPol_IdleLow,
			.SPI_ClkRate   = SPI_ClkRateDiv2,
			.SPI_DataOrder = SPI_LSBFirst,
	};

	RCC_voidInitSysClock();
	RCC_voidEnableClock( RCC_GPIOA, RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOB, RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOC, RCC_APB2 );

	RCC_voidEnableClock( RCC_I2C1, RCC_APB1 );
	RCC_voidEnableClock( RCC_I2C2, RCC_APB1 );

	RCC_voidEnableClock( RCC_SPI1, RCC_APB2 );

	PORT_voidInit();


	u8 data[Spi_data_counter] =
	{
		0xab,
		0xba,
		0xcf,
		0x55
	};

	u8 a[Spi_data_counter];

//	I2C_Init( I2C1 );
	SPI_Init( &spi );

	while ( 1 )
	{
//		I2C_Start( I2C1 );
//		I2C_SendAddress( I2C1, 0x4E );
//		I2C_SendData( I2C1, &(t), 1 );
//		I2C_Stop( I2C1 );

		SPI_State(SPI1, SPI_Enable);
		SPI_u8SynchTransceive( SPI1, data, a, Spi_data_counter);
		SPI_State(SPI1, SPI_Disable);
	}
}
