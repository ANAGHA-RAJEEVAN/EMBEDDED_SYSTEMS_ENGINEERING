/*
 * QUESTION_5.c
 *
 * Created: 19-05-2026 17:33:47
 * Author : anaghA
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


void delay_10s()
{
	int i;
	int count=610;
	
	
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
		TIFR0|=(1<<TOV0);
		while (!(TIFR0&(1<<TOV0)));
	}
	
}

void delay_3s()
{
	int i;
	int count=183;
	
	
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
		TIFR0|=(1<<TOV0);
		while (!(TIFR0&(1<<TOV0)));
	}
}


int main(void)
{
	// macros for LED pins
	#define Green PORTB5
	#define Orange PORTB4
	#define Red PORTB3
	
	// set LED pins as output
	DDRB|=(1<<DDB5)|(1<<DDB4)|(1<<DDB3);
	
	while (1)
	{
		PORTB|=(1<<Green); //Green
		delay_10s();
		PORTB&=~(1<<Green);
		PORTB|=(1<<Orange); // orange
		delay_3s();
		PORTB&=~(1<<Orange);
		PORTB|=(1<<Red);		// red 
		delay_10s();
		PORTB&=~(1<<Red);
		
	}
}

