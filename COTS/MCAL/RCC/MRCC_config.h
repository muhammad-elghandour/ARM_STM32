

#ifndef _MRCC_CONFIG_
#define _MRCC_CONFIG_

/*

		01-MRCC_HSE_CRYSTAL 
		02-MRCC_HSE_RC		 
		03-MRCC_HSI         
		04-MRCC_PLL		 

*/

#define MRCC_CLOCK_TYPE     MRCC_HSE_CRYSTAL


/*

		01-MRCC_PLL_IN_HSI_2  
		02-MRCC_PLL_IN_HSE_2  
		03-MRCC_PLL_IN_HSE    
*/

#if MRCC_CLOCK_TYPE == MRCC_PLL

#define MRCC_PLL_INPUT    MRCC_PLL_IN_HSE

#endif

/*

	01- MRCC_PLL_MUL_BY_2   
	02- MRCC_PLL_MUL_BY_3    
	03- MRCC_PLL_MUL_BY_4    
	04- MRCC_PLL_MUL_BY_5    
	05- MRCC_PLL_MUL_BY_6    
	06- MRCC_PLL_MUL_BY_7    
	07- MRCC_PLL_MUL_BY_8    
	08- MRCC_PLL_MUL_BY_9    
	09- MRCC_PLL_MUL_BY_10   
	10- MRCC_PLL_MUL_BY_11   
	11- MRCC_PLL_MUL_BY_12    
	12- MRCC_PLL_MUL_BY_13   
	13- MRCC_PLL_MUL_BY_14   
	14- MRCC_PLL_MUL_BY_15   
	15- MRCC_PLL_MUL_BY_16      
*/

#if MRCC_CLOCK_TYPE == MRCC_PLL

#define MRCC_PLL_MUL_VAL    MRCC_PLL_MUL_BY_2

#endif

/*

		01-MRCC_ENABLE_CS     
		02-MRCC_DISABLE_CS    

*/

#define MRCC_CS_SYS   MRCC_DISABLE_CS
  
#endif