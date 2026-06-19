/*
 * QUESTION_6.c
 *
 * Created: 22-05-2026 13:45:38
 * Author : anagha
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*
Green LED --> PB5
Orange LED --> PB4
Red LED --> PB3
Emergency LED --> PB2

Button --> PD2
*/

volatile uint8_t emergency_flag=0;

void delay_10s()
{
	int i;
	int count=610;
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar set to 1024
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
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalr set to 1024
		TIFR0|=(1<<TOV0);
		while (!(TIFR0&(1<<TOV0)));
	}
}

//ISR function
ISR(INT0_vect)
{
	emergency_flag=1;
}

void green_emergency()
{
	emergency_flag=0;
	
	PORTB|=(1<<PORTB2);
	PORTB|=(1<<PORTB5);
	
	delay_3s();
	
	PORTB&=~(1<<PORTB2);
	PORTB&=~(1<<PORTB5);
}

int main(void)
{
    #define Green PORTB5
    #define Orange PORTB4
    #define Red PORTB3
	#define button PORTD2
		
	DDRB|=(1<<Green)|(1<<Orange)|(1<<Red)|(1<<DDB2);	// set LED as output
	DDRD&=~(1<<button);	// button pin as input,int0 pin
	PORTD|=(1<<button);						// enabled internalpullup
		
	EIMSK|=(1<<INT0);	//enabled int0  
	// interrupt on falling edge 
	EICRA|=(1<<ISC01);
	EICRA&=~(1<<ISC00);
	sei(); // enable global interrupts 
		
    while (1) 
    {
		PORTB|=(1<<Green); //Green
		delay_10s();
		
		PORTB&=~(1<<Green);
		if (emergency_flag)
		{
			green_emergency();
		}
		
		PORTB|=(1<<Orange); // orange
		delay_3s();
		PORTB&=~(1<<Orange);
		
		if (emergency_flag)
		{
			green_emergency();
		}
		
		PORTB|=(1<<Red);		// red LED
		delay_10s();
		PORTB&=~(1<<Red);
		
		if (emergency_flag)
		{
			green_emergency();
		}
	}
}

