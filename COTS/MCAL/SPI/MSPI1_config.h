#ifndef _MSPI1_CONFIG_H
#define _MSPI1_CONFIG_H


#define MSPI1_SLAVE_SELECT_PIN               MGPIO_PORTA,MGPIO_PIN0

/*
	Options :- 
	
		1- Enable 
		2- Disable

*/

#define MSPI1_STATUS                          MSPI1_ENABLE

/*
	Options:-
		
		1- MSPI1_CLOCK_LOW
		2- MSPI1_CLOCK_HIGH

*/


#define  MSPI1_CPOL                           MSPI1_CLOCK_HIGH


/*
	Options:-
		
		1- MSPI1_READ_WRITE
		2- MSPI1_WRITE_READ

*/


#define  MSPI1_CPHA                           MSPI1_WRITE_READ


/*

	Options:-
	
		1- MSPI1_MASTER
		2- MSPI1_SLAVE

*/


#define MSPI1_MODE                            MSPI1_MASTER


/*

	Options:-
		
		1- MSPI1_FPCLK_2  
		2- MSPI1_FPCLK_4  
		3- MSPI1_FPCLK_8  
		4- MSPI1_FPCLK_16 
		5- MSPI1_FPCLK_32 
		6- MSPI1_FPCLK_64 
		7- MSPI1_FPCLK_128
		8- MSPI1_FPCLK_256
		
*/

#if     MSPI1_MODE  ==  MSPI1_MASTER

	#define MSPI1_PRESCALLER     MSPI1_FPCLK_16

#endif

/*

	Options:-
	
	1- MSPI1_MSB
	2- MSPI1_LSB
	
*/

#define MSPI1_DATA_ORDER             MSPI1_MSB

/*
	Options:-
		
		1- MSPI1_HW
        2- MSPI1_SW
*/


#define MSPI1_NSS_MANAGE             MSPI1_SW


/*
	Options:-
		
		1- MSPI1_8BIT_DATA
        2- MSPI1_16BIT_DATA
*/

#define MSPI1_DATA_SIZE             MSPI1_8BIT_DATA   


/*
	Options:-
		
		1- MSPI1_INT_DISABLE
        2- MSPI1_INT_TXENE  
		3- MSPI1_INT_RXENE  
		
*/          


#define MSPI1_INT_SATATUS        MSPI1_INT_DISABLE



#endif
