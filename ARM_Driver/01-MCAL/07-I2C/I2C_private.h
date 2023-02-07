/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : I2C Driver                            */
/***************************************************************/

#ifndef _I2C_PRIVATE_H_
#define _I2C_PRIVATE_H_


/*              Addresses              */

#define I2C1_BASE_ADDRESS      0x40005400
#define I2C2_BASE_ADDRESS      0x40005800

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 OAR1;
	volatile u32 OAR2;
	volatile u32 DR;
	volatile u32 SR1;
	volatile u32 SR2;
	volatile u32 CCR;
	volatile u32 TRISE;
}I2C_MemMap_t;

#define I2C1                   ( ( volatile I2C_MemMap_t* ) I2C1_BASE_ADDRESS )
#define I2C2                   ( ( volatile I2C_MemMap_t* ) I2C2_BASE_ADDRESS )


/*              Pins              */

typedef enum
{
	I2C_CR1_PE,               /* start of CR1 */
	I2C_CR1_SMBUS,
	I2C_CR1_SMBTYPE = 3,
	I2C_CR1_ENARP,
	I2C_CR1_ENPEC,
	I2C_CR1_ENGC,
	I2C_CR1_NOSTRETCH,
	I2C_CR1_START,
	I2C_CR1_STOP,
	I2C_CR1_ACK,
	I2C_CR1_POS,
	I2C_CR1_PEC,
	I2C_CR1_ALERT,
	I2C_CR1_SWRST = 15,        /* end of CR1 */
	I2C_CR2_FREQ = 0,          /* start of CR2 */
	I2C_CR2_ITERREN = 8,
	I2C_CR2_ITEVTEN,
	I2C_CR2_ITBUFEN,
	I2C_CR2_DMAEN,
	I2C_CR2_LAST,              /* end of CR2 */
	I2COAR1_ADD0 = 0,          /* start of OAR1 */
	I2C_OAR1_ADD,
	I2C_OAR1_ADDMODE = 15,     /* end of OAR1 */
	I2C_ORA2_ENDUAL = 0,       /* start of OAR2 */
	I2C_ORA2_ADD2,             /* end of OAR2 */
	I2C_DR = 0,                /* DR */
	I2C_SR1_SB = 0,            /* start of SR1 */
	I2C_SR1_ADDR,
	I2C_SR1_BTF,
	I2C_SR1_ADD10,
	I2C_SR1_STOPF,
	I2C_SR1_RxNE = 6,
	I2C_SR1_TxE,
	I2C_SR1_BERR,
	I2C_SR1_ARLO,
	I2C_SR1_AF,
	I2C_SR1_OVR,
	I2C_SR1_PECERR,
	I2C_SR1_TIMEOUT = 14,
	I2C_SR1_SMBALERT,          /* end of SR1 */
	I2C_SR2_MSL = 0,           /* start of SR2 */
	I2C_SR2_BUSY,
	I2C_SR2_TRA,
	I2C_SR2_GENCALL = 4,
	I2C_SR2_SMBDEGAUL,
	I2C_SR2_SMBHOST,
	I2C_SR2_DUALF,
	I2C_SR2_PEC,               /* end of SR2 */
	I2C_CCR_CCR = 0,           /* start of CCR */
	I2C_CCR_DUTY = 14,
	I2C_CCR_F_S,               /* end of CCR */
	I2C_TRISE = 0,             /* TRISE */
}I2C_Pins_t;


/*              Errors              */
typedef enum
{
	I2C_NO_ERROR,
	I2C_Pointer_Error,
}I2C_Errors_t;


#endif /* _I2C_PRIVATE_H_ */
