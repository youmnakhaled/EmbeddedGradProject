/*
 * EXT_INT.h
 *
 * Created: 21-Apr-21 11:40:55 PM
 *  Author: Kareem
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "MCU.h"
#include "STD.h"
#include "BIT_Math.h"
#include "EXT_INT_config.h"

#define GLOBAL_INTERRUPT_ENABLE 0
#define GLOBAL_INTERRUPT_DISABLE 1

#define RISING_EDGE 0
#define FALLING_EDGE 1
#define ANY_LOGIC_CHANGE 2
#define LOW_LEVEL 3

void SET_Global_INT (void);
void EXT_INT0_Init (void);
void EXT_INT1_Init (void);
void EXT_INT2_Init (void);

#endif /* EXT_INT_H_ */