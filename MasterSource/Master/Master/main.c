/*
 * C43_SPI_DRIVER.c
 *
 * Created: 5/26/2021 9:58:59 PM
 * Author : Ali
 */ 

#include "SPI.h"
#include "UART.h"
#include "LED.h"

#define F_CPU  16000000
#include <util/delay.h>


int main(void)
{

 	LED1_INIT();

	uint8 rx_data = 0;		// we dont care what we recieve, so I just keep it in a variable as it as the return value of the function
	
	SPI_Master_Init();
	
	SPI_Master_InitTrans();
	
	_delay_ms(1000);		// Time just to make sure that the slave(s) are up
	
	UART_Init();

	uint8 data = 0;


	while (1)
	{
		// Data is passed from the bluetooth device to the Master using UART protocol 
		data = UART_Rx();
		
		if (data)
		{
			// I just added this led to show a sign when the Master receives anything from the Bluetooth UART Module
			 LED1_TOGGLE();
			// Data From Bluetooth is then passed to the slave(s)
			rx_data = SPI_TranSiver(data);
			data = 0;
	
		}	
    }
}

