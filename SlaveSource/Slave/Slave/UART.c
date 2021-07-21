/*
 * UART.c
 *
 * Created: 5/24/2021 10:17:36 PM
 *  Author: Ali
 */ 

#include "UART.h"


void UART_Init(void)
{
	uint32 UBRR_Val = 0;
	
	/*TX Pin as output*/
	SET_BIT(DDRD , 1);
	/*RX Pin as input*/
	CLR_BIT(DDRD , 0);
	
	
	/*enable Tx*/
	SET_BIT(UCSRB , 3);
	/*enable Rx*/
	SET_BIT(UCSRB , 4);
	
	/*1 stop bit, no parity, 8 bit data*/
	UCSRC = 0X86 ;
	
	UBRR_Val = ((160000) / (16 * 96)) -1 ;
	
	UBRRL =  UBRR_Val;
	
}

void UART_Tx(uint8 chr)
{
	UDR = chr ;
	
	while(GET_BIT(UCSRA,5) == 0);
	
}

void UART_TxString(uint8* str)
{
	uint8 i =0;
	
	while(str[i] != '\0')
	{
		UART_Tx(str[i]);
		i++;
	}
}

uint8 UART_Rx(void)
{
	/*if data received*/
	while(GET_BIT(UCSRA,7) == 0);
	
	return UDR ;
}