#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"

void EXTI0_IRQHandler(void){

	MGPIO_voidSetPinValue      ( MGPIO_PORTA , MGPIO_PIN0 , MGPIO_HIGH );
	MGPIO_voidSetPinValue      ( MGPIO_PORTA , MGPIO_PIN0 , MGPIO_LOW );

}

int main(void)
{

	MRCC_voidInitSysClock();//Initialization System Clock Speed 8Mhz Crystel
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOA_EN );//Enable GPIOA Peripheral Clock

	MGPIO_voidSetPinDirection( MGPIO_PORTA , MGPIO_PIN0 , MGPIO_OUTPUT_2MHZ_PP );
	MGPIO_voidSetPinValue    ( MGPIO_PORTA , MGPIO_PIN0 , MGPIO_LOW );

	MNVIC_voidEnablePeri ( 6 );
	MNVIC_voidSetPending ( 6 );

	while(1){

	}

	return 0;
}



