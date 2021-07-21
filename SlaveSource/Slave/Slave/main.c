

#include "SPI.h"
#include "LED.h"
#include "LCD.h"

#include "EXT_INT.h"
#include "avr/interrupt.h"

#define F_CPU  16000000


int main(void)
{
	// Two Buttons : labeled in the simulation
	LED0_INIT();				
	LED1_INIT();
	LCD_Init();
	EXT_INT0_Init();			// interrupt on PD2 : Reset Button 

	
    uint8 tx_data = 2;			// Tx in my case is a dummy data as we dont need to transmit anything to the Master
	uint8 rx_data = 0;
	uint8 error = 0;			// if Data send is not 1 or 2 as we only have two leds
	
	SPI_Slave_Init();
	

	
    while (1) 
    {
		rx_data = SPI_TranSiver(tx_data);
		
		if(rx_data)
		{
			LCD_Clear();

			switch (rx_data)
			{
				case '1':
				
				LED0_TOGGLE();
				uint8 message[] = " Toggling Led  1 ";
				LCD_WriteString(message);
			
				break;
				
				case '2':
				
				LED1_TOGGLE();
				uint8 message1[] = " Toggling Led  2 ";
				LCD_WriteString(message1);

				break;
				
				default:
				// In case we don't choose led 1 or 2 than thats an invalid Peripheral Number
				error = 1;
				break;
			}
			
			if(error){
				uint8 message2[] = " Invalid Led Number ";
				LCD_WriteString(message2);
			}
			
			rx_data = 0;
		}
		
    }
}

ISR(INT0_vect)
{
	// This is a reset button 
	// If pressed , I clear the LCD and switch off the two LEDs at the slave side
	LED0_OFF();
	LED1_OFF();
	LCD_Clear();

	uint8 resetMsg[] = "Resetting !! ";
	LCD_WriteString(resetMsg);
};