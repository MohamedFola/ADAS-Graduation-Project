/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : Port Driver                           */
/***************************************************************/

#ifndef _PORT_PRIVATE_H_
#define _PORT_PRIVATE_H_

/* Error Types */
#define PORT_E_PARAM_PIN               0x0A  /* Invalid Port Pin ID requested */
#define PORT_E_DIRECTION_UNCHANGEABLE  0x0B  /* Port Pin not configured as changeable */
#define PORT_E_INIT_FAILED             0x0C  /* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_INVALID_MODE      0x0D  /* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE       0x0E  /* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_UNINIT                  0x0F  /* API service called without module initialization */
#define PORT_E_PARAM_POINTER           0x10  /* APIs called with a Null Pointer */



/* Registers */

#define GPIOA_BASE_ADDRESS     0x40010800
#define GPIOB_BASE_ADDRESS     0x40010C00
#define GPIOC_BASE_ADDRESS     0x40011000
#define AFIO_BASE_ADDRESS      0x40010000

typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
}PORT_GPIOx_MemMap_t;


#define GPIOA ( ( PORT_GPIOx_MemMap_t* ) GPIOA_BASE_ADDRESS )
#define GPIOB ( ( PORT_GPIOx_MemMap_t* ) GPIOB_BASE_ADDRESS )
#define GPIOC ( ( PORT_GPIOx_MemMap_t* ) GPIOC_BASE_ADDRESS )


/* Concatenating Macros */

#define CONC_15_BITS(BIT_15, BIT_14, BIT_13, BIT_12, BIT_11, BIT_10, BIT_9, BIT_8, BIT_7, BIT_6, BIT_5, BIT_4, BIT_3, BIT_2, BIT_1, BIT_0) \
	CONC_15_BITS_HELPER(BIT_15, BIT_14, BIT_13, BIT_12, BIT_11, BIT_10, BIT_9, BIT_8, BIT_7, BIT_6, BIT_5, BIT_4, BIT_3, BIT_2, BIT_1, BIT_0)

#define CONC_15_BITS_HELPER(BIT_15, BIT_14, BIT_13, BIT_12, BIT_11, BIT_10, BIT_9, BIT_8, BIT_7, BIT_6, BIT_5, BIT_4, BIT_3, BIT_2, BIT_1, BIT_0) \
	0b##BIT_15##BIT_14##BIT_13##BIT_12##BIT_11##BIT_10##BIT_9##BIT_8##BIT_7##BIT_6##BIT_5##BIT_4##BIT_3##BIT_2##BIT_1##BIT_0


#define CONC_8_BITS(BIT_7, BIT_6, BIT_5, BIT_4, BIT_3, BIT_2, BIT_1, BIT_0) \
	CONC_8_BITS_HELPER(BIT_7, BIT_6, BIT_5, BIT_4, BIT_3, BIT_2, BIT_1, BIT_0)

#define CONC_8_BITS_HELPER(BIT_7, BIT_6, BIT_5, BIT_4, BIT_3, BIT_2, BIT_1, BIT_0) \
	0b##BIT_7##BIT_6##BIT_5##BIT_4##BIT_3##BIT_2##BIT_1##BIT_0


/* Configurations Macros */

#define PORT_PIN_HIGH                                                 1
#define PORT_PIN_LOW                                                  0
#define PORT_PIN_DEFAULT_VALUE                                        0

#define PORT_INPUT_ANALOG_MODE                                        0000
#define PORT_INPUT_FLOATING_MODE                                      0100
#define PORT_INPUT_PULLING_MODE                                       1000

#define PORT_OUTPUT_GENERAL_PURPOSE_PUSH_PULL_MAX_SPEED_10MHZ         0001
#define PORT_OUTPUT_GENERAL_PURPOSE_OPEN_DRAIN_MAX_SPEED_10MHZ        0101
#define PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_10MHZ      1001
#define PORT_OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_MAX_SPEED_10MHZ     1101

#define PORT_OUTPUT_GENERAL_PURPOSE_PUSH_PULL_MAX_SPEED_2MHZ          0010
#define PORT_OUTPUT_GENERAL_PURPOSE_OPEN_DRAIN_MAX_SPEED_2MHZ         0110
#define PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_2MHZ       1010
#define PORT_OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_MAX_SPEED_2MHZ      1110

#define PORT_OUTPUT_GENERAL_PURPOSE_PUSH_PULL_MAX_SPEED_50MHZ         0011
#define PORT_OUTPUT_GENERAL_PURPOSE_OPEN_DRAIN_MAX_SPEED_50MHZ        0111
#define PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_50MHZ      1011
#define PORT_OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_MAX_SPEED_50MHZ     1111

#define PORT_DEFAULT_MODE                                             0100


/* Concatenating Configurations Set by the user */

/* Mode Macros */
#define PORTA_LOW_MODE        CONC_8_BITS(PORTA_PIN7_MODE,\
						                  PORTA_PIN6_MODE,\
						                  PORTA_PIN5_MODE,\
						                  PORTA_PIN4_MODE,\
						                  PORTA_PIN3_MODE,\
						                  PORTA_PIN2_MODE,\
						                  PORTA_PIN1_MODE,\
						                  PORTA_PIN0_MODE)

#define PORTA_HIGH_MODE       CONC_8_BITS(PORTA_PIN15_MODE,\
						                  PORTA_PIN14_MODE,\
						                  PORTA_PIN13_MODE,\
						                  PORTA_PIN12_MODE,\
						                  PORTA_PIN11_MODE,\
						                  PORTA_PIN10_MODE,\
						                  PORTA_PIN9_MODE ,\
						                  PORTA_PIN8_MODE)

#define PORTB_LOW_MODE        CONC_8_BITS(PORTB_PIN7_MODE,\
						                  PORTB_PIN6_MODE,\
						                  PORTB_PIN5_MODE,\
						                  PORTB_PIN4_MODE,\
						                  PORTB_PIN3_MODE,\
						                  PORTB_PIN2_MODE,\
						                  PORTB_PIN1_MODE,\
						                  PORTB_PIN0_MODE)

#define PORTB_HIGH_MODE       CONC_8_BITS(PORTB_PIN15_MODE,\
						                  PORTB_PIN14_MODE,\
						                  PORTB_PIN13_MODE,\
						                  PORTB_PIN12_MODE,\
						                  PORTB_PIN11_MODE,\
						                  PORTB_PIN10_MODE,\
						                  PORTB_PIN9_MODE ,\
						                  PORTB_PIN8_MODE)


#define PORTC_HIGH_MODE       CONC_8_BITS(PORTC_PIN15_MODE,\
						                  PORTC_PIN14_MODE,\
						                  PORTC_PIN13_MODE,\
						                  0100,\
						                  0100,\
						                  0100,\
						                  0100,\
						                  0100)


/* Initial Value Macros */
#define PORTA_INITIAL_VALUE   CONC_15_BITS(PORTA_PIN15_INITIAL_VALUE,\
		                                   PORTA_PIN14_INITIAL_VALUE,\
										   PORTA_PIN13_INITIAL_VALUE,\
										   PORTA_PIN12_INITIAL_VALUE,\
										   PORTA_PIN11_INITIAL_VALUE,\
										   PORTA_PIN10_INITIAL_VALUE,\
										   PORTA_PIN9_INITIAL_VALUE ,\
										   PORTA_PIN8_INITIAL_VALUE ,\
										   PORTA_PIN7_INITIAL_VALUE ,\
										   PORTA_PIN6_INITIAL_VALUE ,\
										   PORTA_PIN5_INITIAL_VALUE ,\
										   PORTA_PIN4_INITIAL_VALUE ,\
										   PORTA_PIN3_INITIAL_VALUE ,\
										   PORTA_PIN2_INITIAL_VALUE ,\
										   PORTA_PIN1_INITIAL_VALUE ,\
										   PORTA_PIN0_INITIAL_VALUE)

#define PORTB_INITIAL_VALUE   CONC_15_BITS(PORTB_PIN15_INITIAL_VALUE,\
		                                   PORTB_PIN14_INITIAL_VALUE,\
										   PORTB_PIN13_INITIAL_VALUE,\
										   PORTB_PIN12_INITIAL_VALUE,\
										   PORTB_PIN11_INITIAL_VALUE,\
										   PORTB_PIN10_INITIAL_VALUE,\
										   PORTB_PIN9_INITIAL_VALUE ,\
										   PORTB_PIN8_INITIAL_VALUE ,\
										   PORTB_PIN7_INITIAL_VALUE ,\
										   PORTB_PIN6_INITIAL_VALUE ,\
										   PORTB_PIN5_INITIAL_VALUE ,\
										   PORTB_PIN4_INITIAL_VALUE ,\
										   PORTB_PIN3_INITIAL_VALUE ,\
										   PORTB_PIN2_INITIAL_VALUE ,\
										   PORTB_PIN1_INITIAL_VALUE ,\
										   PORTB_PIN0_INITIAL_VALUE)

#define PORTC_INITIAL_VALUE   CONC_15_BITS(PORTC_PIN15_INITIAL_VALUE,\
		                                   PORTC_PIN14_INITIAL_VALUE,\
							  			   PORTC_PIN13_INITIAL_VALUE,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0                        ,\
							  			   0)

#endif /* _PORT_PRIVATE_H_ */
