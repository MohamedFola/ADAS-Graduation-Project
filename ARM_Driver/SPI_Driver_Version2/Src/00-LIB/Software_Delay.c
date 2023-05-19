#include "STD_TYPES.h"
#include "Software_Delay.h"


void _delay_ms(u32 Copy_u32Time)
{
	for( u32 i = 0; i < 1000 * Copy_u32Time; i++ )
	{
		asm( "NOP" );
	}
}
