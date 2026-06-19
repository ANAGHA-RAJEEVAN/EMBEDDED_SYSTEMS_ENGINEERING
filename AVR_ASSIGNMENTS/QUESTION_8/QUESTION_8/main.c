/*
 * QUESTION_8.c
 *
 * Created: 22-05-2026 15:00:11
 * Author : anagha
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BUTTON   PD2   // Push button connected to PD2
#define LED_PIN  PD6   // PWM output pin (OC0A)

volatile uint8_t dutyLevel = 0; // 0 = 25%, 1 = 50%, 2 = 75%, 3 = OFF

// Update the PWM dutycycle
void updatePWM(uint8_t level)
{
	switch(level)
	{
		case 0: OCR0A = 64;  break;   // 25% dutycycle
		case 1: OCR0A = 128; break;   // 50% duty ccle
		case 2: OCR0A = 192; break;   // 75% duty cycle
		case 3: OCR0A = 0;   break;   // LED OFF
	}
}

ISR(INT0_vect)
{
	// Change tonext brightness level whenever the button is pressed
	dutyLevel = (dutyLevel + 1) & 0x03;

	updatePWM(dutyLevel);
}

int main(void)
{
	// Configure PWM pin as output
	DDRD |= (1 << LED_PIN);

	// Configure button pin as input and enable internal pull-up
	DDRD &= ~(1 << BUTTON);
	PORTD |= (1 << BUTTON);

	//Timer0 Fast PWM Configuration
	TCCR0A |= (1 << WGM00) | (1 << WGM01);   // Fast PWM mode
	TCCR0A |= (1 << COM0A1);                 // Non inverting PWM output
	TCCR0B |= (1 << CS01) | (1 << CS00);     // Prescaler setto 64

	OCR0A = 64;  // Start with 25% brightness

	//External Interrupt Configuration
	EICRA |= (1 << ISC01);   // Falling edge trigger
	EIMSK |= (1 << INT0);    // Enable INT0

	sei(); // Enable global interrupts

	while (1)
	{
		// PWM generation and brightness control
	}
}

