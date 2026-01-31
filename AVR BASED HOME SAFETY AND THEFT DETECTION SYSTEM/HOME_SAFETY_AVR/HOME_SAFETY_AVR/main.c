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



//Pin Configuration

#define BUZZER_PORT PORTB
#define BUZZER_PIN  PORTB0
#define BUZZER_DDR  DDRB
#define BUZZER_REG  DDB0

#define LED_PORT    PORTB
#define LED_PIN     PORTB1
#define LED_DDR     DDRB
#define LED_REG     DDB1


#define PIR_DDR     DDRD
#define PIR_REG     DDD2
#define PIR_PINREG  PIND
#define PIR_PIN     PIND2      // INT0 input


volatile uint8_t intrusion_flag = 0;

//Function prototype
void GPIO_init(void);  
void PIR_init(void);
void fire_detection(void);
void intrusion_detection(void);

//ISR function called when interrupt is triggered
ISR(INT0_vect)
{
    intrusion_flag = 1;
}

int main(void)
{
    GPIO_init();	//Initialize GPIO
    adc_init();		//Initialize ADC
    UART_init();	//Initialize UART
    PIR_init();		//Initialize PIR
    sei();			//Enable Interrupt

    // PIR warm-up time
    _delay_ms(30000);

	//System on after warm up time
    UART_send_string("SYSTEM ON\n");

    while (1)
    {
        intrusion_detection();  //Intrusion detection function
		fire_detection();		//Fire detection function
        _delay_ms(200);
    }
}


//GPIO Initialization
void GPIO_init(void)
{
    BUZZER_DDR |= (1 << BUZZER_REG);
    LED_DDR    |= (1 << LED_REG);

    BUZZER_PORT &= ~(1 << BUZZER_PIN);
    LED_PORT    &= ~(1 << LED_PIN);
}


//PIR Initialization
void PIR_init(void)
{
    PIR_DDR &= ~(1 << PIR_REG);    // PD2 as input
    PORTD &= ~(1 << PIR_PIN);      // no pull-up

    // INT0 Rising Edge Trigger
    EICRA |= (1 << ISC01) | (1 << ISC00);
    EIMSK |= (1 << INT0);
}



//Fire detection
void fire_detection(void)
{
    unsigned int adc_value;
    int temp;
	//Read adc value
    adc_value = adc_read(0);   
	//Converting adc value to Temperature          
    temp = (int)(adc_value * 0.488);      
	
	//If temp > 60, fire hazard is detected
    if (temp > 60)
    {
        // Warning light ON
        LED_PORT |= (1 << LED_PIN);
		//Buzzer ON
        BUZZER_PORT |= (1 << BUZZER_PIN);

        UART_send_string("FIRE ALERT!\n");
        _delay_ms(1000);

        BUZZER_PORT &= ~(1 << BUZZER_PIN);
    }
    else
    {
        LED_PORT &= ~(1 << LED_PIN);
    }
}


//Intrusion detection
void intrusion_detection(void)
{
    if (intrusion_flag)
    {
        intrusion_flag = 0;

        _delay_ms(50);
		
		//If PIR_PIN is high,Intrusion detected
        if (PIR_PINREG & (1 << PIR_PIN))
        {
            UART_send_string("INTRUSION DETECTED!\n");
			
			//Warning light ON
			LED_PORT |= (1 << LED_PIN);
			
            // Alarm pattern
            BUZZER_PORT |= (1 << BUZZER_PIN);
            _delay_ms(500);
            BUZZER_PORT &= ~(1 << BUZZER_PIN);
            _delay_ms(200);
            BUZZER_PORT |= (1 << BUZZER_PIN);
            _delay_ms(500);
            BUZZER_PORT &= ~(1 << BUZZER_PIN);
			
            _delay_ms(2000);
        }
    }
}
