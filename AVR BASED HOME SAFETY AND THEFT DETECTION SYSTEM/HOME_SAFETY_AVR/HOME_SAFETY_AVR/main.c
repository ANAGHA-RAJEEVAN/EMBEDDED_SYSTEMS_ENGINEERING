/*
 * HOME_SAFETY_AVR.c
 * Created: 23-01-2026 14:53:51
 * Fire hazard and PIR intrusion detection
 * Author : Anagha R
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "adc.h"
#include "UART.h"

volatile int flag = 0;

void init_gpio(void);
void init_pir(void);
void detect_fire(void);
void detect_motion(void);

//Interrupt service routine
ISR(INT0_vect)
{
	flag = 1;
}

int main()
{
	init_gpio(); //Configure GPIO  
	adc_init();	//Configure ADC		
	UART_init();//Configure UART
	init_pir();	//Configure PIR
	sei();//Enable global interrupt
	
	//PIR takes around 30 seconds to warmup so we should give a delay of 30seconds
	_delay_ms(30000);
	
	//System turns on after warmup
	UART_send_string("SYSTEM ON\n");
	//UART_send_string("debug correct\n");
	
	while(1)
	{
		detect_motion();			//Checking if pir triggered
		detect_fire();	//Checking fire hazard
		_delay_ms(200);				//200ms delay
	}
}

//Setup buzzer and led
void init_gpio(void)
{
	//PB0(BUZZER) and PB1(LED) is set as outut
	DDRB |= (1 << DDB0) | (1 << DDB1);  
	//Initially reset both buzzer and led
	PORTB &= ~(1 << PORTB0); //buzzer
	PORTB &= ~(1 << PORTB1); //led
	
}

//Setup PIR motion sensor
void init_pir(void)
{
	//PD2(MOTION SENSOR) is set as input
	DDRD &= ~(1 << DDD2);
	
	//Interrupt enabling 
	EIMSK |= (1 << INT0); //Enabling interrupt 0.
	EICRA |= (1 << ISC01) | (1 << ISC00); //Rising edge trigger for interrupt
}

//Fire hazard detection
void detect_fire(void)
{
	unsigned int adc_value;
	int tempvalue = 0; //temperature value
	
	adc_value = adc_read(0); //Read anlog value from LM35 that's from channel 0
	tempvalue = (int)(adc_value * 0.488); //Convert analog value to temperature
	
	//Buzzer will on if temp goes beyond 60
	if (tempvalue > 60)
	{
		PORTB |= (1 << PORTB1); //led will be turned ON
		PORTB |= (1 << PORTB0); //Buzzer will be turned ON
		
		//Printing message on uart
		UART_send_string("FIRE ALERT!\n");
		//Keep buzzer on for 1 second
		_delay_ms(1000);
		PORTB &= ~(1 << PORTB0); //buzzer will be turned off
	}
	else
	{
		PORTB &= ~(1 << PORTB1); //Led will be turned off
	}
}

//Motion detection
void detect_motion(void)
{
	if (flag == 1)
	{
		flag = 0;
		_delay_ms(100);
		
		if (PIND & (1 << PIND2))
		{
			//Printing message on uart
			UART_send_string("INTRUSION DETECTED!\n");
			PORTB |= (1 << PORTB1); //led ON
			//buzzer alarm pattern
			PORTB |= (1 << PORTB0); //Buzzer will be turned ON
			_delay_ms(500);
			PORTB &= ~(1 << PORTB0);   //buzzer will be turned off
			_delay_ms(100);
			PORTB |= (1 << PORTB0);//Buzzer will be turned ON
			_delay_ms(500);
			PORTB &= ~(1 << PORTB0);  //buzzer will be turned off
			
			_delay_ms(2000); //delay to prevent continuous alarm
		}
	}
}