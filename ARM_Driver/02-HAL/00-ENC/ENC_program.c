/*************************** Layer:HAL      ************************************/
/**************************  Driver:ENCODER ************************************/
/*************************  Version: 1.0    ************************************/
/******************************************************************************/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "../../01-MCAL/02-DIO/DIO_interface.h"
#include "../../01-MCAL/03-STK/STK_interface.h"
#include "../../01-MCAL/04-NVIC/NVIC_interface.h"
#include "../../01-MCAL/05-EXTI/EXTI_interface.h"
#include "../../01-MCAL/06-AFIO/AFIO_interface.h"

#include "ENC_private.h"
#include "ENC_interface.h"
#include "ENC_config.h"

volatile  s32 Global_s32Counter1=0;
volatile  s32 Global_s32Counter2=0;
volatile  s32 Global_s32Counter3=0;
volatile  s32 Global_s32Counter4=0;
//u32 Global_flag=0;

void HENC_voidInit(void)
{
	/*Enable the interrupt from NVIC for all external interrupt lines*/

	for(u8 Local_u8Counter=6;Local_u8Counter<=10;Local_u8Counter++)
	{
		MNVIC_u8EnableInterrupt(Local_u8Counter);
	}
	/*Set the call back for each interrupt line*/
	MEXTI_voidSetCallBackFunc(MEXTI_LINE0,ENC1_ISR);
	MEXTI_voidSetCallBackFunc(MEXTI_LINE1,ENC2_ISR);
	MEXTI_voidSetCallBackFunc(MEXTI_LINE3,ENC3_ISR);
	MEXTI_voidSetCallBackFunc(MEXTI_LINE4,ENC4_ISR);
	/*Set rising edge latch for each line*/
	for(u8 Local_u8Counter=0;Local_u8Counter<=4;Local_u8Counter++)
		{

			if(Local_u8Counter!=2)
			{
				MEXTI_u8SetSignalLatch(Local_u8Counter, RISING_EDGE);
			}
		}

	/*Enable all the EXTI lines */
	for(u8 Local_u8Counter=0;Local_u8Counter<=4;Local_u8Counter++)
			{
		if(Local_u8Counter!=2)
				{
					MEXTI_u8EnableEXTI(Local_u8Counter);
				}
			}


	/*Choosing the port pins to be EXTI*/
#if ENC_PORT == ENC_PORTA
	for(u8 Local_u8Counter=0;Local_u8Counter<=4;Local_u8Counter++)
	{
		if(Local_u8Counter!=2)
		{
			MAFIO_voidSetEXTIConfiguration(Local_u8Counter, MAFIO_PORTA);
		}
	}
#elif ENC_PORT == ENC_PORTB
	for(u8 Local_u8Counter=0;Local_u8Counter<=4;Local_u8Counter++)
	{
		if(Local_u8Counter!=2)
		{
			MAFIO_voidSetEXTIConfiguration(Local_u8Counter, MAFIO_PORTB);
		}
	}
#elif ENC_PORT == ENC_PORTC
	for(u8 Local_u8Counter=0;Local_u8Counter<=4;Local_u8Counter++)
	{
		if(Local_u8Counter!=2)
		{
			MAFIO_voidSetEXTIConfiguration(Local_u8Counter, MAFIO_PORTC);
		}
	}
#elif
#error "Wrong Encoder Port"
#endif


}

/*Get counts functions*/

s32 HENC_u8Enc1GetCounts(void)
{
	return Global_s32Counter1;
}
s32 HENC_u8Enc2GetCounts(void)
{
	return Global_s32Counter2;
}
s32 HENC_u8Enc3GetCounts(void)
{
	return Global_s32Counter3;
}
s32 HENC_u8Enc4GetCounts(void)
{
	return Global_s32Counter4;
}

/*Lines ISR*/

void ENC1_ISR(void)
{
	u8  Local_pu8PinStatus0=0;
	u8  Local_pu8PinStatus1=0;
	/*C1:B0 ---- C2:A7*/
	MDIO_u8ReadChannel(ENC_PORT,MDIO_PIN0,&Local_pu8PinStatus0);
	MDIO_u8ReadChannel(MDIO_PORTA,MDIO_PIN7,&Local_pu8PinStatus1);
	if(Local_pu8PinStatus1 == MDIO_PIN_HIGH)
	{
		Global_s32Counter1++;
	}
	else
	{
		Global_s32Counter1--;
	}

}
void ENC2_ISR(void)
{
	u8  Local_pu8PinStatus0=0;
	u8  Local_pu8PinStatus1=0;
	/*C1:B1 ---- C2:B10*/
	MDIO_u8ReadChannel(ENC_PORT,MDIO_PIN1,&Local_pu8PinStatus0);
	MDIO_u8ReadChannel(MDIO_PORTB,MDIO_PIN10,&Local_pu8PinStatus1);
	if(Local_pu8PinStatus1==MDIO_PIN_HIGH)
	{
		Global_s32Counter2++;
	}
	else
	{
		Global_s32Counter2--;
	}

}
void ENC3_ISR(void)
{

	u8  Local_pu8PinStatus0=0;
	u8  Local_pu8PinStatus1=0;
	/*C1:B3 ---- C2:A15*/

	MDIO_u8ReadChannel(ENC_PORT,MDIO_PIN3,&Local_pu8PinStatus0);
	MDIO_u8ReadChannel(MDIO_PORTA,MDIO_PIN15,&Local_pu8PinStatus1);
	if(Local_pu8PinStatus1==MDIO_PIN_HIGH)
	{
		Global_s32Counter3++;
	}
	else
	{
		Global_s32Counter3--;
	}

}
void ENC4_ISR(void)
{
	u8  Local_pu8PinStatus0=0;
	u8  Local_pu8PinStatus1=0;
	/*C1:B4 ---- C2:B5*/
	MDIO_u8ReadChannel(ENC_PORT,MDIO_PIN4,&Local_pu8PinStatus0);
	MDIO_u8ReadChannel(MDIO_PORTB,MDIO_PIN5,&Local_pu8PinStatus1);
	if(Local_pu8PinStatus1==MDIO_PIN_HIGH)
	{
		Global_s32Counter4++;
	}
	else
	{
		Global_s32Counter4--;
	}

}
