#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"


int main(void)
{

	MRCC_voidInitSysClock();

	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOA_EN );
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOB_EN );
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOC_EN );

	return 0;
}
