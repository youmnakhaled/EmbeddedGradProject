/*
 * MCU.h
 *
 * Created: 4/7/2021 10:53:20 PM
 *  Author: Ali
 */ 


#ifndef MCU_H_
#define MCU_H_

#include "STD.h"

#define    PORTA    *((volatile uint8*) 0x3B)
#define    DDRA     *((volatile uint8*) 0x3A)
#define    PINA     *((volatile uint8*) 0x39)

#define    PORTB    *((volatile uint8*) 0x38)
#define    DDRB     *((volatile uint8*) 0x37)
#define    PINB     *((volatile uint8*) 0x36)

#define    PORTC    *((volatile uint8*) 0x35)
#define    DDRC     *((volatile uint8*) 0x34)
#define    PINC     *((volatile uint8*) 0x33)

#define    PORTD    *((volatile uint8*) 0x32)
#define    DDRD     *((volatile uint8*) 0x31)
#define    PIND     *((volatile uint8*) 0x30)

/****************************************  Ext INT ************************************/
#define SREG   (*(volatile uint8*)(0x5F))

#define GICR   (*(volatile uint8*)(0x5B))

#define GIFR   (*(volatile uint8*)(0x5A))

#define MCUCR  (*(volatile uint8*)(0x55))

#define MCUCSR (*(volatile uint8*)(0x54))

/****************************************  ADC ************************************/


#define ADMUX           (*(volatile uint8 *)(0x27))
#define ADCSRA          (*(volatile uint8 *)(0x26))
#define ADCH            (*(volatile uint8 *)(0x25))
#define ADCL            (*(volatile uint8 *)(0x24))
#define ADC_ADJUST      (*(volatile uint16 *)(0x24))
#define SFIOR           (*(volatile uint8 *)(0x50))

/****************************************  Timer0 ************************************/
#define TCNT0  (*(volatile uint8*)(0x52))
#define TCCR0  (*(volatile uint8*)(0x53))
#define OCR0   (*(volatile uint8*)(0x5C))
#define TIMSK  (*(volatile uint8*)(0x59))

/****************************************  Timer 1 **********************************/
#define TCCR1A (*(volatile uint8* )(0x4F))
#define TCCR1B (*(volatile uint8* )(0x4E))
#define OCR1A  (*(volatile uint16*)(0x4A))

/**************************************     WDT    *********************************/
#define WDTCR (*(volatile uint8* )(0x41))

/*************************************      UART   ***********************************/
#define UBRRH   (*((volatile uint8*)0x40))
#define UBRRL   (*((volatile uint8*)0x29))
#define UCSRA   (*((volatile uint8*)0x2B))
#define UCSRB   (*((volatile uint8*)0x2A))
#define UCSRC   (*((volatile uint8*)0x40))
#define UDR     (*((volatile uint8*)0x2C))

/*************************************  SPI  **************************************/
#define SPCR  (*(volatile uint16*)(0x2D))
#define SPSR  (*(volatile uint16*)(0x2E))
#define SPDR  (*(volatile uint16*)(0x2F))


#endif /* MCU_H_ */