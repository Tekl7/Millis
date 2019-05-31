/*
 * millis.h
 *
 * Created: 11. 4. 2019 15:19:32
 *  Author: Vojta
 *
 * This project uses a Timer/Counter to implement millis() function.
 * millis() function returns time in ms from the program start.
 *
 * Hardware support:
 * ATtiny85: 8-bit Timer/Counter1
 * ATtiny88: 16-bit Timer/Counter1
 * CPU clock is 8 MHz.
 *
 * Execute millis_init() function to set registers and interrupts.
 * Then just call millis() function to get time in ms.
 * You can call resetMillis() to reset 32-bit millis counter to prevent variable overflow.
 * Make sure to execute sei() function to enable global interrupts.
 */ 


#ifndef MILLIS_H_
#define MILLIS_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
#include <util/atomic.h>

void millis_init();
uint32_t millis();
void resetMillis();

#endif /* MILLIS_H_ */