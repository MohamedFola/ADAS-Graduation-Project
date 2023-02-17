" If you add any thing to the repo just add it to the txt file here and add comment to know the changes you have made "

****************************************************************************************************************************
" First Commit for ARM drivers "
" Driver names for relative path "
" Use this to know the relative path for #include "

00-LIB
	STD_TYPES.h
	BIT_MATH.h
	Software_Delay.h
	Software_Delay.c

01-MCAL
	00-RCC
	01-PORT
	02-DIO
	03-STK
	04-NVIC
	05-EXTI
	06-AFIO
	07-I2C
	08-TIM
	09-SPI

****************************************************************************************************************************

Note: there is a picture at SPI folder --> use it to know the pins configuration for any mode of the spi
Note: I implemented the Full-duplex mode only