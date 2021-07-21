/*
 * SPI.c
 *
 * Created: 5/26/2021 10:00:21 PM
 *  Author: Ali
 */ 

#include "SPI.h"


void  SPI_Master_Init(void)
{
	  /*SS Pin*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	/*MOSI Pin*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	/*MISO Pin*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	/*CLK Pin*/
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	
	SPCR = 0x53;
	
}

void  SPI_Slave_Init(void)
{
	 /*SS Pin*/
	 DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
	 /*MOSI Pin*/
	 DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	 /*MISO Pin*/
	 DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	 /*CLK Pin*/
	 DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);
	 
	 SPCR = 0x40;
}

void  SPI_Master_InitTrans(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);
}

void  SPI_Master_EndTrans(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
}

uint8 SPI_TranSiver(uint8 data)
{
	SPDR = data;
	
	while(GET_BIT( SPSR , 7 ) == 0);
	
	return SPDR ;
}


