# Millis

This library allows you to use millis function like with Arduino. Millis function returns time in ms from the program start.

## Implementation
  - Adding the already created static library
  1. Import header file "millis.h" to your project
  2. Add a static library ("libMillis-*YOUR_DEVICE*-TC*TIMER/COUNTER_NUMBER_TO_BE_USED*.a" file located inside the "Release" folder) according to your device to your project.
  
       **or**
  
  - Adding the library files
  1. Add "millis.h", "millis_config.h" and "millis.c" files to your project
  2. Select Timer/Couter which you want to be used by millis library and assign the right number to the MILLIS_TC_NUM macro located in the "millis_config.h" file.
      - Timer/Counter0 -> 0, Timer/Counter1 -> 1

**Hardware support:**

ATtiny84A, ATtiny85, ATtiny88
- It is possible to add another AVR MCUs, just add another conditional directives (#if defined(\_\_AVR\_*YOUR_DEVICE*\_\_)), assign the right registers and set the right OCREG_VALUE in millis_config.h file.

- CPU clock is 8 MHz, but it is possible to implement different CPU clock, just set the right OCREG_VALUE and prescaler in millis_config.h file.

- When running at 8 MHz, following settings are highly recommended:
  - 8-bit Timer/Counter: OCREG_VALUE = 124, prescaler = 64
  - 16-bit Timer/Counter: OCREG_VALUE = 7999, prescaler = 1
  
- If you are going to modify this library (adding MCUs or changing CPU clock) and use the first method of implementation (adding static library), you have to build it on your own to get the right ".a" file.

## How to use

- Execute millis_init() function to set registers and interrupts.

- Then just call millis() function to get time in ms.

- You can call resetMillis() to reset 32-bit millis counter to prevent variable overflow.

- Make sure to execute sei() function to enable global interrupts.
