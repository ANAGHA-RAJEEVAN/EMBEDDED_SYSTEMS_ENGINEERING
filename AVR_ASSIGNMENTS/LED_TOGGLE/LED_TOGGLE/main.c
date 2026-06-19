/*
 * LED_TOGGLE.c
 *
 * Created: 19-05-2026 13:57:12
 * Author : Anagha
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void delay_ms(unsigned int ms)
{
	while(ms--)
	{
		_delay_ms(1);
	}
}

int main(void)
{
	// Set PD5 as output
	DDRD |= (1 << PORTD);

	while(1)
	{
		// LED ON
		PORTD |= (1 << PORTD5);

		// 3 second delay
		delay_ms(3000);

		// LED OFF
		PORTD &= ~(1 << PORTD5);

		// 5 second delay
		delay_ms(5000);
	}
}

