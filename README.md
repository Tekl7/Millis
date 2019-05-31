# Millis

This library allows you to use millis function like with Arduino. Millis function returns time in ms from the program start.

## Implementation
  1. Import header file "millis.h" to your project
  2. Add "libMillis-t85.a" or "libMillis-t88.a" library (located inside the "Release" folder) to your project
  3. Meet following instructions:

Timer/Counter is used to implement millis function.

**Hardware support:**

ATtiny85: 8-bit Timer/Counter1

ATtiny88: 16-bit Timer/Counter1

CPU clock is 8 MHz.

## How to use

- Execute millis_init() function to set registers and interrupts.

- Then just call millis() function to get time in ms.

- You can call resetMillis() to reset 32-bit millis counter to prevent variable overflow.

- Make sure to execute sei() function to enable global interrupts.
