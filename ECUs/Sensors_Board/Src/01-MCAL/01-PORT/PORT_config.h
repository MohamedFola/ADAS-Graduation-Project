/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : Port Driver                           */
/***************************************************************/

#ifndef _PORT_CONFIG_H_
#define _PORT_CONFIG_H_


/****************************************************************************/
/* Options:                                                                 */
/* 		1)  PORT_INPUT_ANALOG_MODE                                          */
/*      2)  PORT_INPUT_FLOATING_MODE                                        */
/*      3)  PORT_INPUT_PULLING_MODE                                         */
/*      4)  PORT_OUTPUT_GENERAL_PURPOSE_PUSH_PULL_MAX_SPEED_10MHZ           */
/*      5)  PORT_OUTPUT_GENERAL_PURPOSE_OPEN_DRAIN_MAX_SPEED_10MHZ          */
/*      6)  PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_10MHZ        */
/*      7)  PORT_OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_MAX_SPEED_10MHZ       */
/*      8)  PORT_OUTPUT_GENERAL_PURPOSE_PUSH_PULL_MAX_SPEED_2MHZ            */
/*      9)  PORT_OUTPUT_GENERAL_PURPOSE_OPEN_DRAIN_MAX_SPEED_2MHZ           */
/*      10) PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_2MHZ         */
/*      11) PORT_OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_MAX_SPEED_2MHZ        */
/*      12) PORT_OUTPUT_GENERAL_PURPOSE_PUSH_PULL_MAX_SPEED_50MHZ           */
/*      13) PORT_OUTPUT_GENERAL_PURPOSE_OPEN_DRAIN_MAX_SPEED_50MHZ          */
/*      14) PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_50MHZ        */
/*      15) PORT_OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_MAX_SPEED_50MHZ       */
/*      16) PORT_DEFAULT_MODE --> PORT_INPUT_FLOATING_MODE                  */
/****************************************************************************/

/* PortA */
#define PORTA_PIN0_MODE                    PORT_DEFAULT_MODE
#define PORTA_PIN1_MODE                    PORT_OUTPUT_GENERAL_PURPOSE_PUSH_PULL_MAX_SPEED_10MHZ
#define PORTA_PIN2_MODE                    PORT_DEFAULT_MODE
#define PORTA_PIN3_MODE                    PORT_DEFAULT_MODE
#define PORTA_PIN4_MODE                    PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_50MHZ
#define PORTA_PIN5_MODE                    PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_50MHZ
#define PORTA_PIN6_MODE                    PORT_INPUT_FLOATING_MODE
#define PORTA_PIN7_MODE                    PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_50MHZ
#define PORTA_PIN8_MODE                    PORT_DEFAULT_MODE
#define PORTA_PIN9_MODE                    PORT_OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_MAX_SPEED_50MHZ
#define PORTA_PIN10_MODE                   PORT_INPUT_FLOATING_MODE
#define PORTA_PIN11_MODE                   PORT_DEFAULT_MODE
#define PORTA_PIN12_MODE                   PORT_DEFAULT_MODE
#define PORTA_PIN13_MODE                   PORT_DEFAULT_MODE
#define PORTA_PIN14_MODE                   PORT_DEFAULT_MODE
#define PORTA_PIN15_MODE                   PORT_DEFAULT_MODE

/* PortB */
#define PORTB_PIN0_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN1_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN2_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN3_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN4_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN5_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN6_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN7_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN8_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN9_MODE                    PORT_DEFAULT_MODE
#define PORTB_PIN10_MODE                   PORT_DEFAULT_MODE
#define PORTB_PIN11_MODE                   PORT_DEFAULT_MODE
#define PORTB_PIN12_MODE                   PORT_DEFAULT_MODE
#define PORTB_PIN13_MODE                   PORT_DEFAULT_MODE
#define PORTB_PIN14_MODE                   PORT_DEFAULT_MODE
#define PORTB_PIN15_MODE                   PORT_DEFAULT_MODE

/* PortC */
#define PORTC_PIN13_MODE                   PORT_DEFAULT_MODE
#define PORTC_PIN14_MODE                   PORT_DEFAULT_MODE
#define PORTC_PIN15_MODE                   PORT_DEFAULT_MODE


/****************************************************************************/
/* Options:                                                                 */
/* 		1) PORT_PIN_HIGH                                                    */
/*      2) PORT_PIN_LOW                                                     */
/*      3) PORT_PIN_DEFAULT_VALUE --> PORT_PIN_LOW                          */
/****************************************************************************/

/* PortA */
#define PORTA_PIN0_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN1_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN2_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN3_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN4_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN5_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN6_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN7_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN8_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN9_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN10_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN11_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN12_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN13_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN14_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTA_PIN15_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE

/* PortB */
#define PORTB_PIN0_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN1_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN2_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN3_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN4_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN5_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN6_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN7_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN8_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN9_INITIAL_VALUE           PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN10_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN11_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN12_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN13_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN14_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTB_PIN15_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE

/* PortC */
#define PORTC_PIN13_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTC_PIN14_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE
#define PORTC_PIN15_INITIAL_VALUE          PORT_PIN_DEFAULT_VALUE



#endif /* _PORT_CONFIG_H_ */
