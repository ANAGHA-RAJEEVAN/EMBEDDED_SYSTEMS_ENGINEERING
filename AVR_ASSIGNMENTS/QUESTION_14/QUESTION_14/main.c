/*
 * QUESTION_14.c
 *
 * Created: 28-05-2026 20:27:53
 * Author : anagha
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

//Configure ADC
void init_adc()
{
	ADMUX = (1 << REFS0); // Use AVCC as reference

	ADCSRA = (1 << ADEN) |
	(1 << ADPS2) |
	(1 << ADPS1) |
	(1 << ADPS0); // Prescaler = 128
}

//Read analog value
uint16_t read_adc_value(uint8_t ch)
{
	ch &= 0x07;

	ADMUX = (ADMUX & 0xF8) | ch;

	ADCSRA |= (1 << ADSC);

	while (ADCSRA & (1 << ADSC));

	return ADC;
}

//Configure Timer0 for PWM output
void init_pwm()
{
	DDRD |= (1 << PORTD6); // OC0A output pin

	TCCR0A = (1 << COM0A1) |
	(1 << WGM01) |
	(1 << WGM00);

	TCCR0B = (1 << CS01) | (1 << CS00);

	OCR0A = 0;
}

int main(void)
{
	uint16_t sensor_value;
	uint8_t duty_cycle;

	init_adc();
	init_pwm();

	while (1)
	{
		// Read potentiometer value
		sensor_value = read_adc_value(0);

		// Convert 10-bit ADC value into 8-bit PWM value
		duty_cycle = sensor_value / 4;

		// Update LED brightness
		OCR0A = duty_cycle;
	}
}

