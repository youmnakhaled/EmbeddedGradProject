/*
 * DIO.h
 *
 * Created: 3/20/2021 11:00:05 AM
 *  Author: Ali
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BIT_Math.h"
#include "STD.h"
#include "MCU.h"

#define  DIO_PORTA    0
#define  DIO_PORTB    1
#define  DIO_PORTC    2
#define  DIO_PORTD    3

#define  DIO_PIN0     0
#define  DIO_PIN1     1
#define  DIO_PIN2     2
#define  DIO_PIN3     3
#define  DIO_PIN4     4
#define  DIO_PIN5     5
#define  DIO_PIN6     6
#define  DIO_PIN7     7


#define  DIO_PORT_OUTPUT     0XFF
#define  DIO_PORT_INPUT      0X00

#define  DIO_PIN_OUTPUT      1
#define  DIO_PIN_INPUT       0


#define  DIO_PORT_HIGH     0XFF
#define  DIO_PORT_LOW      0X00

#define  DIO_PIN_HIGH       1
#define  DIO_PIN_LOW        0





void DIO_SetPortDir(uint8 Port, uint8 Dir);
void DIO_SetPinDir(uint8 Port , uint8 Pin , uint8 Dir);

void DIO_SetPortValue(uint8 Port, uint8 Vlaue);
void DIO_SetPinValue(uint8 Port , uint8 Pin , uint8 Value);

uint8 DIO_GetPortValue(uint8 Port);
uint8 DIO_GetPinValue(uint8 Port, uint8 Pin );


void DIO_TogglePort(uint8 Port);

void DIO_TogglePin(uint8 Port, uint8 Pin);




#endif /* DIO_H_ */