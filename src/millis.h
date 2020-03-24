/*
 * millis.h
 *
 * Created: 11. 4. 2019 15:19:32
 *  Author: Tekl7
 *
 * This project uses a Timer/Counter (0 or 1) to implement millis() function.
 * millis() function returns time in ms from the program start.
 *
 * Hardware support:
 * ATtiny84A, ATtiny85, ATtiny88
 * It is possible to add another AVR MCUs, just add another conditional
 * directives (#if defined(__AVR_YOUR_DEVICE__)), assign the right registers
 * and set the right OCREG_VALUE in millis_config.h file.
 *
 * CPU clock is 8 MHz, but it is possible to implement different CPU clock,
 * just set the right OCREG_VALUE and prescaler in millis_config.h file.
 *
 * When running at 8 MHz, following settings are highly recommended:
 * 8-bit Timer/Counter - OCREG_VALUE = 124, prescaler = 64
 * 16-bit Timer/Counter - OCREG_VALUE = 7999, prescaler = 1
 *
 * How to use
 * Execute millis_init() function to initialize registers and interrupts.
 * Then just call millis() function to get time in ms.
 * You can call resetMillis() to reset 32-bit millis counter to prevent variable overflow.
 * Make sure to execute sei() function to enable global interrupts.
 */ 


#ifndef MILLIS_H_
#define MILLIS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <avr/io.h>

void millis_init();
uint32_t millis();
void resetMillis();

#ifdef __cplusplus
}
#endif

#endif /* MILLIS_H_ */