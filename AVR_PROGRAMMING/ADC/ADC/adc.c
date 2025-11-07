/*
 * adc.c
 *
 * Created: 13-10-2025 20:55:15
 *  Author: anagh
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void adc_init(void)
{
	ADMUX |= (1 << REFS0); //Reference = AVcc =5V 
	ADMUX &= ~(1 << REFS1);
	ADCSRA |= (1 << ADEN);  //ADC ENABLE
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); //PRESCALAR 128 means 125khz frequency
}

uint16_t adc_read(uint8_t channel)
{
	channel &= 0x07;
	ADMUX = (ADMUX & 0XF8) | channel;
	ADCSRA |= (1 << ADSC);  //Start conversion
	while (ADCSRA & (1 << ADSC)); //Wait for conversion to complete
	return (ADCL | (ADCH << 8));  //Return result
	
}