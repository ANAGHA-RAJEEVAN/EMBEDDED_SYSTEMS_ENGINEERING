/*
 * QUESTION_10.c
 *
 * Created: 24-05-2026 15:15:53
 * Author : anagha
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t motor_state = 0;   // Stores whether the motor is ON or OFF

// Initialize ADC with AVCC as reference voltage
void init_adc()
{
	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// Read analog value from ADC channel
uint16_t read_adc_channel(uint8_t ch)
{
	ADMUX = (ADMUX & 0xF0) | ch;

	ADCSRA |= (1 << ADSC);  // Start ADC conversion

	while (ADCSRA & (1 << ADSC));

	return ADC;
}

// Configure Timer0 for Fast PWM generation
void init_pwm()
{
	DDRD |= (1 << PORTD6);     // PD6 (OC0A)as output

	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
	TCCR0B = (1 << CS01) | (1 << CS00);

	OCR0A = 0;
}

// Reading temperature
float get_temperature()
{
	uint16_t adc_result;
	float sensor_voltage;
	float temp_value;

	adc_result = read_adc_channel(0);

	sensor_voltage = (adc_result * 5.0) / 1023.0;

	temp_value = sensor_voltage * 100.0;

	return temp_value;
}

// Deciding motor speed based on temperature
uint8_t get_motor_speed(float temp_value)
{
	if (temp_value < 30)
	{
		return 80;    // Low speed
	}
	else if (temp_value >= 30 && temp_value < 40)
	{
		return 160;   // Medium speed
	}
	else
	{
		return 255;   // Max speed
	}
}

// Update PWM duty cycle to control motor speed
void set_pwm_speed(uint8_t pwm_value)
{
	OCR0A = pwm_value;
}

int main(void)
{
	float current_temp;
	uint8_t pwm_speed;

	init_adc();
	init_pwm();

	DDRD &= ~(1 << PORTD2);   // Push button as input
	PORTD |= (1 << PORTD2);   // Enable internal pullup resistor

	while (1)
	{
		// Check for button press to toggle motor state
		if (!(PIND & (1 << PORTD2)))
		{
			_delay_ms(50);

			if (!(PIND & (1 << PORTD2)))
			{
				motor_state ^= 1;

				while (!(PIND & (1 << PORTD2)));
			}
		}

		if (motor_state)
		{
			// Read temperature and adjust motor speed
			current_temp = get_temperature();

			pwm_speed = get_motor_speed(current_temp);

			set_pwm_speed(pwm_speed);
		}
		else
		{
			// Stop the motor when system is OFF
			set_pwm_speed(0);
		}

		_delay_ms(200);
	}
}