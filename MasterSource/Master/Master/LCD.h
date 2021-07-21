/*
 * LCD.h
 *
 * Created: 4/19/2021 11:43:57 PM
 *  Author: Ali
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD_CFG.h"


void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_WriteChar(uint8 chr);

void LCD_WriteString(uint8* str);

void LCD_GoTo(uint8 Col, uint8 Row);

void LCD_Clear(void);






#endif /* LCD_H_ */