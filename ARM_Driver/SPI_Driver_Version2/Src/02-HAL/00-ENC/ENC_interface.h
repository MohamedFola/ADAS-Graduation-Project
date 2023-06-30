/*************************** Layer:HAL      ************************************/
/**************************  Driver:ENCODER ************************************/
/*************************  Version: 1.0    ************************************/
/******************************************************************************/

#ifndef ENC_INTERFACE_H_
#define ENC_INTERFACE_H_


void HENC_voidInit(void);
s32 HENC_u8Enc1GetCounts(void);
s32 HENC_u8Enc2GetCounts(void);
s32 HENC_u8Enc3GetCounts(void);
s32 HENC_u8Enc4GetCounts(void);

void ENC1_ISR(void);
void ENC2_ISR(void);
void ENC3_ISR(void);
void ENC4_ISR(void);

#endif /* ENC_INTERFACE_H_ */
