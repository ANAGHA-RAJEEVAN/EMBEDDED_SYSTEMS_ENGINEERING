/*
	To print temperature using LM35 sensor and ADC.
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "adc.h"


int main(void)
{
	uint8_t adc_value;
	lcd_init();
    adc_init();
	
    while (1) 
    {
		float temp;
		lcd_clear();                // clear lcd
		lcd_set_cursor(0,0);        //Bring cursor to first row
		lcd_print("TEMPERATURE =>");
		adc_value = adc_read(0);     //Read ADC value
		temp = adc_value*.488;
		lcd_set_cursor(1,0);         //Bring cursor to second row
		lcd_print_float(temp,3); //print ADC value in integer format
		lcd_data(0xDF);
		lcd_print("C");
		_delay_ms(500);
    }
}

