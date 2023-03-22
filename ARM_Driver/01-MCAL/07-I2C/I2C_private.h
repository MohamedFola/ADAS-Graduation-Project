/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : I2C Driver                            */
/***************************************************************/

#ifndef _I2C_PRIVATE_H_
#define _I2C_PRIVATE_H_


#define I2C_COUNT              2

/*              Errors                 */
typedef enum
{
	I2C_No_Error     ,
	I2C_Number_Error ,
	I2C_NACK         ,
}I2C_Errors_t;

/* this is calculated as APB frequency is 8MHz */
#define I2C_SM_CRR       0x28

/*              Addresses              */
#define I2C1_BASE_ADDRESS      ( ( volatile I2C_MemMap_t* )( 0x40005400 ) )
#define I2C2_BASE_ADDRESS      ( ( volatile I2C_MemMap_t* )( 0x40005800 ) )

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



/*              Pins              */

typedef enum
{
	I2C_CR1_PE               ,   /* CR1 */
	I2C_CR1_SMBUS            ,
	I2C_CR1_SMBTYPE      = 3 ,
	I2C_CR1_ENARP            ,
	I2C_CR1_ENPEC            ,
	I2C_CR1_ENGC             ,
	I2C_CR1_NOSTRETCH        ,
	I2C_CR1_START            ,
	I2C_CR1_STOP             ,
	I2C_CR1_ACK              ,
	I2C_CR1_POS              ,
	I2C_CR1_PEC              ,
	I2C_CR1_ALERT            ,
	I2C_CR1_SWRST       = 15 ,
	I2C_CR2_FREQ        = 0  ,   /* CR2 */
	I2C_CR2_ITERREN     = 8  ,
	I2C_CR2_ITEVTEN          ,
	I2C_CR2_ITBUFEN          ,
	I2C_CR2_DMAEN            ,
	I2C_CR2_LAST             ,
	I2COAR1_ADD0        = 0  ,   /* OAR1 */
	I2C_OAR1_ADD             ,
	I2C_OAR1_ADDMODE    = 15 ,
	I2C_ORA2_ENDUAL     = 0  ,   /* OAR2 */
	I2C_ORA2_ADD2            ,
	I2C_DR              = 0  ,   /* DR */
	I2C_SR1_SB          = 0  ,   /* SR1 */
	I2C_SR1_ADDR             ,
	I2C_SR1_BTF              ,
	I2C_SR1_ADD10            ,
	I2C_SR1_STOPF            ,
	I2C_SR1_RxNE        = 6  ,
	I2C_SR1_TxE              ,
	I2C_SR1_BERR             ,
	I2C_SR1_ARLO             ,
	I2C_SR1_AF               ,
	I2C_SR1_OVR              ,
	I2C_SR1_PECERR           ,
	I2C_SR1_TIMEOUT     = 14 ,
	I2C_SR1_SMBALERT         ,
	I2C_SR2_MSL         = 0  ,   /* SR2 */
	I2C_SR2_BUSY             ,
	I2C_SR2_TRA              ,
	I2C_SR2_GENCALL     = 4  ,
	I2C_SR2_SMBDEGAUL        ,
	I2C_SR2_SMBHOST          ,
	I2C_SR2_DUALF            ,
	I2C_SR2_PEC              ,
	I2C_CCR_CCR         = 0  ,   /* CCR */
	I2C_CCR_DUTY        = 14 ,
	I2C_CCR_F_S              ,
	I2C_TRISE           = 0  ,   /* TRISE */
}I2C_Pins_t;



#endif /* _I2C_PRIVATE_H_ */
