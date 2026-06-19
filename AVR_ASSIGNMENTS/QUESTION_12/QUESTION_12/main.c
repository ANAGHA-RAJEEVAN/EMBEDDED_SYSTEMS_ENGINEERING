/*
 * QUESTION_12.c
 *
 * Created: 19-05-2026 15:32:11
 * Author : anagh
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "lcd.h"

// Push button connected to PB0
#define SWITCH_PIN PB0

uint32_t count_value = 0;

/* Display a 9-digit number on the LCD */
void display_counter(uint32_t value)
{
	char lcd_data[10];

	lcd_data[9] = '\0';

	for (int index = 8; index >= 0; index--)
	{
		lcd_data[index] = (value % 10) + '0';
		value /= 10;
	}

	lcd_set_cursor(0, 0);
	lcd_print(lcd_data);
}

/* Detect short press and long press */
uint8_t get_button_status()
{
	uint16_t press_time = 0;

	// Button is active low
	if (PINB & (1 << SWITCH_PIN))
	return 0;

	_delay_ms(20);

	while (!(PINB & (1 << SWITCH_PIN)))
	{
		_delay_ms(10);

		press_time += 10;

		if (press_time >= 2000)
		{
			// Wait until button is released
			while (!(PINB & (1 << SWITCH_PIN)));

			_delay_ms(20);

			return 2; // Long press
		}
	}

	_delay_ms(20);

	return 1; // Short press
}

int main(void)
{
	// Configure button as input and enable pull-up
	DDRB &= ~(1 << SWITCH_PIN);
	PORTB |= (1 << SWITCH_PIN);

	lcd_init();
	lcd_clear();

	lcd_set_cursor(0, 0);
	lcd_print("000000000");

	while (1)
	{
		uint8_t button_state = get_button_status();

		if (button_state == 1)
		{
			count_value++;

			if (count_value > 999999999)
			count_value = 0;

			display_counter(count_value);
		}
		else if (button_state == 2)
		{
			count_value = 0;

			display_counter(count_value);
		}
	}
}