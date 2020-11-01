/*
 * millis_config.h
 *
 * Created: 13. 8. 2019 13:34:17
 *  Author: Tekl7
 *
 * Register configuration for millis library
 */ 


#ifndef MILLIS_CONFIG_H_
#define MILLIS_CONFIG_H_

#ifndef F_CPU
	#warning "F_CPU set to default value!"
	#define F_CPU 8000000UL
#endif

/**
	Select a number according to the Timer/Counter to be used
	and assign it to the MILLIS_TC_NUM macro.
	Timer/Counter0 -> 0, Timer/Counter1 -> 1
*/
#define MILLIS_TC_NUM 0

#if defined(__AVR_ATtiny84A__)
#if MILLIS_TC_NUM == 0
#define CTC_REG				TCCR0A
#define CTC_BIT_MSK			_BV(WGM01)
#define PRESCALER_REG		TCCR0B
#define PRESCALER_BITS_MSK	_BV(CS00) | _BV(CS01)
#define PRESCALER			64
#define OCREG				OCR0A
#define OCIE_REG			TIMSK0
#define	OCIE_BIT_MSK		_BV(OCIE0A)
#define OCINT_VECT			TIM0_COMPA_vect
#elif MILLIS_TC_NUM == 1
#define CTC_REG				TCCR1B
#define CTC_BIT_MSK			_BV(WGM12)
#define PRESCALER_REG		TCCR1B
#define PRESCALER_BITS_MSK	_BV(CS10)
#define PRESCALER			1
#define OCREG				OCR1A
#define OCIE_REG			TIMSK1
#define	OCIE_BIT_MSK		_BV(OCIE1A)
#define OCINT_VECT			TIM1_COMPA_vect
#endif
#endif

#if defined(__AVR_ATtiny85__)
#if MILLIS_TC_NUM == 0
#define CTC_REG				TCCR0A
#define CTC_BIT_MSK			_BV(WGM01)
#define PRESCALER_REG		TCCR0B
#define PRESCALER_BITS_MSK	_BV(CS00) | _BV(CS01)
#define PRESCALER			64
#define OCREG				OCR0A
#define OCIE_REG			TIMSK
#define	OCIE_BIT_MSK		_BV(OCIE0A)
#define OCINT_VECT			TIMER0_COMPA_vect
#elif MILLIS_TC_NUM == 1
#define CTC_REG				TCCR1
#define CTC_BIT_MSK			_BV(CTC1)
#define PRESCALER_REG		TCCR1
#define PRESCALER_BITS_MSK	_BV(CS10) | _BV(CS11) | _BV(CS12)
#define PRESCALER			64
#define OCREG				OCR1C
#define OCIE_REG			TIMSK
#define	OCIE_BIT_MSK		_BV(OCIE1A)
#define OCINT_VECT			TIMER1_COMPA_vect
#endif
#endif

#if defined(__AVR_ATtiny88__)
#if MILLIS_TC_NUM == 0
#define CTC_REG				TCCR0A
#define CTC_BIT_MSK			_BV(CTC0)
#define PRESCALER_REG		TCCR0A
#define PRESCALER_BITS_MSK	_BV(CS00) | _BV(CS01)
#define PRESCALER			64
#define OCREG				OCR0A
#define OCIE_REG			TIMSK0
#define	OCIE_BIT_MSK		_BV(OCIE0A)
#define OCINT_VECT			TIMER0_COMPA_vect
#elif MILLIS_TC_NUM == 1
#define CTC_REG				TCCR1B
#define CTC_BIT_MSK			_BV(WGM12)
#define PRESCALER_REG		TCCR1B
#define PRESCALER_BITS_MSK	_BV(CS10)
#define PRESCALER			1
#define OCREG				OCR1A
#define OCIE_REG			TIMSK1
#define	OCIE_BIT_MSK		_BV(OCIE1A)
#define OCINT_VECT			TIMER1_COMPA_vect
#endif
#endif

#if defined(__AVR_ATmega328P__)
#if MILLIS_TC_NUM == 0
#define CTC_REG				TCCR0A
#define CTC_BIT_MSK			_BV(WGM01)
#define PRESCALER_REG		TCCR0B
#define PRESCALER_BITS_MSK	_BV(CS00) | _BV(CS01)
#define PRESCALER			64
#define OCREG				OCR0A
#define OCIE_REG			TIMSK0
#define	OCIE_BIT_MSK		_BV(OCIE0A)
#define OCINT_VECT			TIMER0_COMPA_vect
#elif MILLIS_TC_NUM == 1
#define CTC_REG				TCCR1B
#define CTC_BIT_MSK			_BV(WGM12)
#define PRESCALER_REG		TCCR1B
#define PRESCALER_BITS_MSK	_BV(CS10)
#define PRESCALER			1
#define OCREG				OCR1A
#define OCIE_REG			TIMSK1
#define	OCIE_BIT_MSK		_BV(OCIE1A)
#define OCINT_VECT			TIMER1_COMPA_vect
#endif
#endif

#endif /* MILLIS_CONFIG_H_ */
