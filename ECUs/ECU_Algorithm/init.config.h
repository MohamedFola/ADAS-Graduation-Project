
#ifndef INIT_CONFIG_H_
#define INIT_CONFIG_H_


#define MOD_ENA     1
#define MOD_DIS     2

/*
 * Options:
 * 1) MOD_ENA
 * 2) MOS_DIS
 */


#define SPI_ENABLE                MOD_ENA
#define I2C_ENABLE                MOD_ENA
#define TIM2_ENABLE               MOD_ENA
#define TIM3_ENABLE               MOD_ENA
#define TIM4_ENABLE               MOD_ENA
#define PWM2_ENABLE               MOD_DIS
#define PWM3_ENABLE               MOD_DIS
#define PWM4_ENABLE               MOD_DIS
#define STK_ENABLE                MOD_ENA
#define EXT_ENABLE                MOD_ENA
#define MOTOR_ENABLE              MOD_ENA
#define ENC_ENABLE                MOD_ENA
#define ULTRASONIC_ENABLE         MOD_ENA


#endif /* INIT_CONFIG_H_ */
