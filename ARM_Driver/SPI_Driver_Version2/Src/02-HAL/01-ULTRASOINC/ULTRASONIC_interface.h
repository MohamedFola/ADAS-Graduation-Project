#ifndef ULTRASONIC_INTERFACE_H
#define ULTRASONIC_INTERFACE_H


/*Choose Timer for ICU*/
#define TIM2			1
#define TIM3			2
#define TIM4			3

typedef struct{
	u8 TrigPort;
	u8 TrigPin;
	u8 Echo_ICU_TIM; //Choose the channel 1 based on timer you chose (TIM2 -> A0 , TIM3-> A6 , TIM4 -> B6)
}Ultrasonic_t;

/*Initialization Ultrasonic*/
void HULTRASONIC_voidInit(Ultrasonic_t* Copy_Sensor);

/*Get Reading from the Ultrasonic*/
void HULTRASONIC_voidGetDistance(Ultrasonic_t* Copy_Sensor,u32* Copy_u8SensorDistance);

#endif
