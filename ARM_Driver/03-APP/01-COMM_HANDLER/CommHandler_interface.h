

#ifndef COMMHANDLER_INTERFACE_H_
#define COMMHANDLER_INTERFACE_H_

#define DISTANCE 	1
#define SPEED	 	2
#define STEERING 	3


void CommHandlerInit(void);

void CommHandlerSend(u32 Copy_u8data , u8 Copy_u8Type);

u32 CommHandlerRxIndication(void);

#endif /* COMMHANDLER_INTERFACE_H_ */
