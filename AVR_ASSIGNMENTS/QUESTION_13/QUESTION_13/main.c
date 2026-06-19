/*
 * QUESTION_13.c
 *
 * Created: 29-05-2026 22:23:43
 * Author : anagha
 */ 
#define F_CPU 16000000UL
#define BAUD 9600

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)

/* ---------------- UART FUNCTIONS ---------------- */

void send_char(char ch)
{
	while (!(UCSR0A & (1 << UDRE0)));

	UDR0 = ch;
}

void send_string(const char *msg)
{
	while (*msg)
	{
		send_char(*msg);
		msg++;
	}
}

char receive_char()
{
	while (!(UCSR0A & (1 << RXC0)));

	return UDR0;
}

void receive_string(char *rx_buffer)
{
	char data;
	int index = 0;

	while (1)
	{
		data = receive_char();

		if (data == '\r' || data == '\n')
		{
			rx_buffer[index] = '\0';
			return;
		}

		rx_buffer[index] = data;
		index++;

		if (index >= 19)
		{
			rx_buffer[index] = '\0';
			return;
		}
	}
}

/* ---------------- PWM FUNCTIONS ---------------- */

void init_pwm()
{
	DDRD |= (1 << PD6);

	TCCR0A = (1 << COM0A1) |
	(1 << WGM01) |
	(1 << WGM00);

	TCCR0B = (1 << CS01) | (1 << CS00);

	OCR0A = 0;
}

void set_led_level(uint8_t level)
{
	OCR0A = (level * 255UL) / 100UL;
}

//MAIN FUNCTION

int main(void)
{
	char rx_data[20];
	char tx_buffer[50];
	int brightness;

	UBRR0H = (UBRR_VALUE >> 8);
	UBRR0L = UBRR_VALUE;

	UCSR0B = (1 << TXEN0) | (1 << RXEN0);

	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

	init_pwm();

	send_string("UART LED Control Ready\r\n");
	send_string("Commands: ON, OFF, 0-100\r\n");

	while (1)
	{
		receive_string(rx_data);

		if (strcmp(rx_data, "ON") == 0)
		{
			set_led_level(100);

			send_string("LED is now ON\r\n");
		}
		else if (strcmp(rx_data, "OFF") == 0)
		{
			set_led_level(0);

			send_string("LED is now OFF\r\n");
		}
		else
		{
			brightness = atoi(rx_data);

			if (brightness >= 0 && brightness <= 100)
			{
				set_led_level(brightness);

				sprintf(tx_buffer,
				"Brightness set to %d%%\r\n",
				brightness);

				send_string(tx_buffer);
			}
			else
			{
				send_string("Invalid Command\r\n");
			}
		}
	}
}

