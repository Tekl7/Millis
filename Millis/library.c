/*
 * Millis.c
 *
 * Created: 11. 4. 2019 12:45:29
 * Author : Vojta
 */ 

#include "millis.h"

// Choose a number and assign it to DEVICE macro to select the demanded device.
// ATtiny85 -> 0
// ATtiny88 -> 1
#define DEVICE 0

static volatile uint32_t timer_millis;

void millis_init()
{
	#if DEVICE == 0
	// CTC mode, prescaler 32
	TCCR1 |= _BV(CTC1) | _BV(CS12) | _BV(CS11);
	
	// Set the registers (OCR1A and OCR1C) value, a match with the counter (TCNT1) value generates an output compare interrupt
	OCR1A = 250;
	OCR1C = 250;

	// Output compare interrupt for OCR1A enabled
	TIMSK |= _BV(OCIE1A);
	
	#elif DEVICE == 1
	// CTC mode, no prescaling
	TCCR1B |= _BV(WGM12) | _BV(CS10);
	
	// Set the register (OCR1A) value, a match with the counter (TCNT1) value generates an output compare interrupt
	OCR1A = 8000;
	
	// Output compare interrupt for OCR1A enabled
	TIMSK1 |= _BV(OCIE1A);
	
	#endif
}

uint32_t millis()
{
	uint32_t millis_return;

	// Ensure this cannot be disrupted
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
ISR(TIMER1_COMPA_vect)
{
	// Add ms
	timer_millis++;
}