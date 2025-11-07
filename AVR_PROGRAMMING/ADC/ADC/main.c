/*
 * ADC.c
 *
 * Created: 13-10-2025 20:53:43
 * Author : anagh
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "adc.h"


int main(void)
{
	uint16_t adc_value;
	lcd_init();
    adc_init();
	
    while (1) 
    {
		lcd_clear();                // clear lcd
		lcd_set_cursor(0,0);        //Bring cursor to first row
		lcd_print("ADC VALUE =>");
		adc_value = adc_read(0);     //Read ADC value
		lcd_set_cursor(1,0);         //Bring cursor to second row
		lcd_print_uint16(adc_value); //print ADC value in integer format
		_delay_ms(500);
    }
}

