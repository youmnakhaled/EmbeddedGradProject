/*
 * EXT_INT.c
 *
 * Created: 21-Apr-21 11:40:42 PM
 *  Author: Kareem
 */ 
#include "EXT_INT.h"


void SET_Global_INT (void)
{
	#if GBL_INT == GLOBAL_INTERRUPT_ENABLE
	
	SET_BIT(SREG, 7);
	
	#elif GBL_INT == GLOBAL_INTERRUPT_DISABLE
	
	CLR_BIT(SREG, 7);
	
	#endif
}

void EXT_INT0_Init (void)
{
	SET_Global_INT(); // enable global interrupts
		
	// select trigger
	#if EXT_INT0_TRIG == RISING_EDGE

	SET_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);

	#elif EXT_INT0_TRIG == FALLING_EDGE
	
	CLR_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);

	#elif EXT_INT0_TRIG == LOW_LEVEL

	CLR_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);

	#elif EXT_INT0_TRIG == ANY_LOGIC_CHANGE
	
	SET_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);

	#endif

	SET_BIT(GICR, 6); // enable peripheral interrupt0
}

void EXT_INT1_Init (void)
{
	SET_Global_INT(); // enable global interrupts
		
	// select trigger
	#if EXT_INT0_TRIG == RISING_EDGE

	SET_BIT(MCUCR, 2);
	SET_BIT(MCUCR, 3);

	#elif EXT_INT0_TRIG == FALLING_EDGE
		
	CLR_BIT(MCUCR, 2);
	SET_BIT(MCUCR, 3);

	#elif EXT_INT0_TRIG == LOW_LEVEL

	CLR_BIT(MCUCR, 2);
	CLR_BIT(MCUCR, 3);

	#elif EXT_INT0_TRIG == ANY_LOGIC_CHANGE
		
	SET_BIT(MCUCR, 2);
	CLR_BIT(MCUCR, 3);

	#endif

	SET_BIT(GICR, 7); // enable peripheral interrupt1
}

void EXT_INT2_Init (void)
{
	SET_Global_INT(); // enable global interrupts
		
	// select trigger
	#if EXT_INT2_TRIG == RISING_EDGE
	
	SET_BIT(MCUCSR, 6);

	#elif EXT_INT2_TRIG == FALLING_EDGE
		
	CLR_BIT(MCUCSR, 6);
	
	#endif
	
	CLR_BIT(GIFR, 5); // clear interrupt 2 flag (INTF2) as recommended by data sheet

	SET_BIT(GICR, 5); // enable peripheral interrupt2
}
