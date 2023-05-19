/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : LIB                                   */
/*             Version : 1                                     */
/*             SWC     : Standard Types                        */
/***************************************************************/

#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

typedef unsigned char             u8;
typedef signed   char             s8;

typedef unsigned short int        u16;  
typedef signed   short int        s16;  	    

typedef unsigned long  int        u32;
typedef unsigned long long  int   u64; 
typedef signed   long  int        s32;

typedef float                     f32;

typedef double                    f64;


#define NULL                      ((void*)0)

#define OK                        1
#define NOK   				      2
#define NULL_POINTER              3

#endif  /* _STD_TYPES_H_ */