#ifndef _INIT_H_
#define _INIT_H_

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


void init_hardware ( void );

#endif /* _INIT_H_ */
