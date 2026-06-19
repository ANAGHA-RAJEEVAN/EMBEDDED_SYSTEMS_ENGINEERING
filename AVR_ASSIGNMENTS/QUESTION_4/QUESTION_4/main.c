/*
 * QUESTION_4.c
 *
 * Created: 21-05-2026 14:26:08
 * Author : anagha
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void updateBinary(uint8_t counter)
{
	PORTB&=0x00;// clears all LEDs on PORTB
	PORTB|=counter&(0x0F);	// the LEDs corresponding to 1s position will become ON
	
}

int main(void)
{
	// set pb0, pb1, pb2, pb3 as output
	DDRB|=(1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3);
	
	DDRD&=~(1<<DDD2);		// set pind2 as input
	PORTD|=(1<<PORTD2);		// set internal pullup
	
	uint8_t counter=0;
	
	while (1)
	{
		
		if (!(PIND&(1<<PIND2)))
		{
			while(!(PIND&(1<<PIND2)));
			_delay_ms(20);
			
			updateBinary(counter);
			counter++;
			
			if (counter>15)
			{
				counter=0;
			}
			
			
		}
	}
}

