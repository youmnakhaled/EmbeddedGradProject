/*
 * LCD.c
 *
 * Created: 4/19/2021 11:43:01 PM
 *  Author: Ali
 */ 

#include "LCD.h"
#define F_CPU  16000000
#include <util/delay.h>


void LCD_Init(void)
{
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , E_PIN ,  DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , D4_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , D5_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , D6_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , D7_PIN , DIO_PIN_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0X32);
	LCD_WriteCommand(0X28);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);
	
}

void LCD_WriteCommand(uint8 cmd)
{
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , RS_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , RW_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd & 0xf0) | (PORTA & 0x0f);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd << 4) | (PORTA & 0x0f);
		
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteChar(uint8 chr)
{
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , RS_PIN , DIO_PIN_HIGH);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , RW_PIN , DIO_PIN_LOW);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_LOW);
		
		PORTA = (chr & 0xf0) | (PORTA & 0x0f);
		
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_LOW);
		
		PORTA = (chr << 4) | (PORTA & 0x0f);
		
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , E_PIN , DIO_PIN_LOW);
		
		_delay_ms(5);
}

void LCD_WriteString(uint8* str)
{
	uint8 i = 0;
	
	while(str[i] != '\0')
	{
		LCD_WriteChar(str[i]);
		i++;
	}
}

void LCD_GoTo(uint8 Col, uint8 Row)
{
	uint8 arr[2] = {0x80 , 0xc0};
	
	LCD_WriteCommand(arr[Row]+Col);
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}