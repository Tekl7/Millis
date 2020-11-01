/*
 * millis.c
 *
 * Created: 11. 4. 2019 12:45:29
 * Author : Tekl7
 */ 

#include <avr/interrupt.h>
#include <util/atomic.h>

#include "millis.h"
#include "millis_config.h"

static volatile uint32_t timer_millis;

void millis_init()
{
	// Set CTC mode
	CTC_REG |= CTC_BIT_MSK;
	
	// Set prescaler
	PRESCALER_REG |= PRESCALER_BITS_MSK;
	
	// Set OCRnx value
	OCREG = ((F_CPU / PRESCALER) / 1000) - 1;
	
	// Enable output compare interrupt
	OCIE_REG |= OCIE_BIT_MSK;
}

uint32_t millis()
{
	uint32_t millis_return;

	// Ensures this cannot be disrupted
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		millis_return = timer_millis;
	}
	
	return millis_return;
}

void resetMillis()
{
	timer_millis = 0;
}

// Output compare interrupt
ISR(OCINT_VECT)
{
	// Add ms
	timer_millis++;
}
