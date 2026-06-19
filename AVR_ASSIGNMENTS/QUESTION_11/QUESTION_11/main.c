/*
 * QUESTION_11.c
 *
 * Created: 24-05-2026 15:26:43
 * Author : anagha
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//Configure ADC to read analog input
void init_adc()
{
	ADMUX = (1 << REFS0); // AVCC as reference voltage

	// Enable ADC with prescaler 128
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// Read ADC
uint16_t read_adc_value()
{
	ADCSRA |= (1 << ADSC); 

	while (ADCSRA & (1 << ADSC));

	return ADC;
}

//Configure Timer1 for servo PWM generation
void init_servo_pwm()
{
	DDRB |= (1 << PORTB1); // set OC1A pin as output

	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << CS11); // Prescaler 8

	ICR1 = 20000; // PWM period for 50 Hz
	OCR1A = 1500; // Starting from center
}

int main(void)
{
	uint16_t adc_result;
	uint16_t servo_pulse;

	init_adc();
	init_servo_pwm();

	while (1)
	{
		// Read potentiometer position
		adc_result = read_adc_value();

		// Convert ADC value into servo pulse width
		servo_pulse = 1000 + ((uint32_t)adc_result * 1000) / 1023;

		// Move servo to the required position
		OCR1A = servo_pulse;

		_delay_ms(10);
	}
}

