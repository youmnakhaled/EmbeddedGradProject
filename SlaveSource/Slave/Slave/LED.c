/*
 * LED.c
 *
 * Created: 4/12/2021 8:36:18 PM
 *  Author: Ahmed
 */ 

#include "LED.h"

void LED0_ON(void)
{
	SET_BIT(PORTC , 2);
}
void LED0_OFF(void)
{
	CLR_BIT(PORTC , 2);
}
void LED0_TOGGLE(void)
{
	Toggle_BIT(PORTC , 2);
}
void LED0_INIT(void)
{
	SET_BIT(DDRC , 2);
}

void LED1_ON(void)
{
	SET_BIT(PORTC , 0);
}
void LED1_OFF(void)
{
	CLR_BIT(PORTC , 0);
}
void LED1_TOGGLE(void)
{
	Toggle_BIT(PORTC , 0);
}
void LED1_INIT(void)
{
	SET_BIT(DDRC , 0);
}

