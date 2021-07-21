/*
 * SPI.h
 *
 * Created: 5/26/2021 10:00:37 PM
 *  Author: Ali
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"


void  SPI_Master_Init(void);

void  SPI_Slave_Init(void);

void  SPI_Master_InitTrans(void);

void  SPI_Master_EndTrans(void);

uint8 SPI_TranSiver(uint8 data);

#endif /* SPI_H_ */