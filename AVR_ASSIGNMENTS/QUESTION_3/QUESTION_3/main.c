/*
 * QUESTION_3.c
 *
 * Created: 21-05-2026 14:14:15
 * Author : anagha
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Set all PORTD pins as output
	DDRD = 0xFF;

	while (1)
	{
		// Move from PD0 to PD7
		for (int i = 0; i < 8; i++)
		{
			PORTD = (1 << i);   // Turn ON one LED at a time
			_delay_ms(400);     // Delay 
		}
	}
}

