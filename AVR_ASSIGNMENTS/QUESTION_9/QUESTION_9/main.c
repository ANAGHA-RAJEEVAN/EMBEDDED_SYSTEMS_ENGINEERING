/*
 * QUESTION_9.c
 *
 * Created: 24-05-2026 11:08:49
 * Author : anagha
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define BUTTON PORTD2

uint8_t duty_index = 0;

// PWM duty cycle values: 25%, 50%, 75%, 100%
uint8_t duty_values[4] = {64, 128, 191, 255};

int main(void)
{
	// Configure OC0A (PD6) as PWM output
	DDRD |= (1 << PORTD6);

	// Configure push button input
	DDRD &= ~(1 << BUTTON);

	// Turn on internal pull-up resistor
	PORTD |= (1 << BUTTON);

	// Timer0 Fast PWM configuration
	TCCR0A |= (1 << WGM01) | (1 << WGM00);

	// PWM output in non-inverting mode
	TCCR0A |= (1 << COM0A1);

	// Timer clock prescaler 64
	TCCR0B |= (1 << CS01) | (1 << CS00);

	// Start with 25% duty cycle
	OCR0A = duty_values[duty_index];

	while (1)
	{
		// Check if button is pressed
		if (!(PIND & (1 << BUTTON)))
		{
			_delay_ms(30);

			if (!(PIND & (1 << BUTTON)))
			{
				duty_index++;

				if (duty_index >= 4)
				{
					duty_index = 0;
				}

				// Load the next duty cycle value
				OCR0A = duty_values[duty_index];

				// Wait until the button is released
				while (!(PIND & (1 << BUTTON)));

				_delay_ms(30);
			}
		}
	}
}

