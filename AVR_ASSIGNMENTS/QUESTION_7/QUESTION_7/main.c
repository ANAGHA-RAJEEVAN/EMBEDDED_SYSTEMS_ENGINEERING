/*
 * QUESTION_7.c
 *
 * Created: 22-05-2026 10:55:59
 * Author : anagh
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

/*
PORTB1 -> Status LED
PORTB2 -> Heartbeat LED
*/

// Timer1 interrupttoggles status LED every 2 seconds 
ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PORTB1);
}

//Timer2 interrupt generates a 2 ms tick
ISR(TIMER2_COMPA_vect)
{
	static uint16_t count = 0;

	count++;

	if (count >= 250)   // 250 x 2 ms = 500 ms
	{
		PORTB ^= (1 << PORTB2);
		count = 0;
	}
}

int main(void)
{
	DDRB |= (1 << PORTB1) | (1 << PORTB2);

	PORTB = 0;

	//Timer1 in CTC mode
	TCCR1B |= (1 << WGM12);

	OCR1A = 31249;      // Compare value for 2sec delay

	TIMSK1 |= (1 << OCIE1A);

	TCCR1B |= (1 << CS12) | (1 << CS10);   // Prescaler 1024

	//Timer2 in CTC mode
	TCCR2A |= (1 << WGM21);

	OCR2A = 249;        // Compare value for 2 ms delay

	TIMSK2 |= (1 << OCIE2A);

	TCCR2B |= (1 << CS22) | (1 << CS20);   // Prescaler 128

	sei(); //GLOBAL INterrupts

	while (1)
	{
		//  With interruptsLEDs are controlled
	}
}

