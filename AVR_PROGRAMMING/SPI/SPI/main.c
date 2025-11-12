/*
 * SPI.c
 * To measure temperature using BMP280 with SPI protocol.
 * Created: 29-10-2025 20:44:49
 * Author : Anagha
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main ()
{
	uint16_t chip_id, dig_T1, dig_T2;
	uint32_t raw_temp,MSB,LSB,XLSB;
	int16_t dig_T3;
	float var1,var2, temp,temp_final;
	
	
	 UART_Init(); //Initialize UART
	
	// Set MOSI, SCK, and SS as output. Set PB0 as output for LED.
	DDRB |= (1 << DDB3) | (1 << DDB5) | (1 << DDB2) | (1 << DDB0);
	// Set MISO as input
	DDRB &= ~ (1 << DDB4);
	// Enable SPI and Master mode. Set clock rate fosc / 16
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	//Select SPI mode to MODE 0.
	SPCR &= ~ ((1 << CPOL) | (1 << CPHA));
	
	// Pull SS low to select slave
	PORTB &= ~ (1 << PORTB2);
	// For read operation, MSB=1, hence OR register address with 0X80
	SPDR = 0XD0 | 0X80;
	// Wait until transmission is complete
	while (! (SPSR & (1 << SPIF)));
	//To reset SPIF bit, read the SPDR data (copy data to a variable)
	(void)SPDR; //Here we get random value stored in slave
	
	//For reading the chip id, send 0X00 so that data from slave comes to master.
	SPDR = 0X00;
	// Wait until transmission is complete
	while (! (SPSR & (1 << SPIF)));
	// Read chip id which is now in SPDR
	chip_id = SPDR; // Here the original data (CHIP ID) is obtained
	// Pull SS high to deselect slave
	PORTB |= (1 << PORTB2);
	
	// Enable CTRL_MEAS = 0x27
	PORTB &= ~(1 << PORTB2);          // SS LOW TO SELECT SLAVE
	SPDR = 0xF4 & 0x7F;               // For write operation, MSB=0, hence AND register address with 0X7F
	while (!(SPSR & (1 << SPIF)));
	(void)SPDR;

	SPDR = 0x27;               // Value to disable sleep mode
	while (!(SPSR & (1 << SPIF)));
	(void)SPDR;

	PORTB |= (1 << PORTB2);       // SS HIGH TO DESELECT SLAVE
	_delay_ms(100);
	
	//Read Temperature compensation values dig_T1,dig_T2,dig_T3.
	//Read dig_T1
	PORTB &= ~ (1 << PORTB2);
	SPDR = 0X88 | 0X80;
	while (! (SPSR & (1 << SPIF)));
	(void)SPDR;
	// LSB (0x88)
	SPDR = 0x00;
	while (! (SPSR & (1 << SPIF)));
	LSB = SPDR;
	//MSB(0x89)
	SPDR = 0X00;
	while (! (SPSR & (1 << SPIF)));
	MSB = SPDR;
	// Pull SS high to deselect slave
	PORTB |= (1 << PORTB2);
	
	dig_T1 = ((uint16_t)MSB << 8) | ((uint16_t)LSB); //dig_T1 value
	
	//Read dig_T2
	PORTB &= ~ (1 << PORTB2);
	SPDR = 0X8A | 0X80;
	while (! (SPSR & (1 << SPIF)));
	(void)SPDR;	
	// LSB (0x8A)
	SPDR = 0x00;
	while (! (SPSR & (1 << SPIF)));
	LSB = SPDR;
	//MSB(0x8B)
	SPDR = 0X00;
	while (! (SPSR & (1 << SPIF)));
	MSB = SPDR;	
	// Pull SS high to deselect slave
	PORTB |= (1 << PORTB2);
	
	dig_T2 = ((uint16_t)MSB << 8) | ((uint16_t)LSB); //dig_T2 value
	
	//Read dig_T3
	PORTB &= ~ (1 << PORTB2);
	SPDR = 0X8C | 0X80;
	while (! (SPSR & (1 << SPIF)));
	(void)SPDR;	
	// LSB (0x8C)
	SPDR = 0x00;
	while (! (SPSR & (1 << SPIF)));
	LSB = SPDR;
	//MSB(0x8D)
	SPDR = 0X00;
	while (! (SPSR & (1 << SPIF)));
	MSB = SPDR;	
	// Pull SS high to deselect slave
	PORTB |= (1 << PORTB2);
	
	dig_T3 = ((int16_t)MSB << 8) | ((int16_t)LSB); //dig_T3 value
	
	
	while (1)
	{
		//To read temperature from BMP280
		
		PORTB &= ~ (1 << PORTB2);  // Pull SS low to select slave
		// For read operation, MSB=1, hence OR register address with 0X80
		SPDR = 0XFA | 0X80;
		// Wait until transmission is complete
		while (! (SPSR & (1 << SPIF)));
		//To reset SPIF bit, read the SPDR data (copy data to a variable)
		(void)SPDR; //Here we get random value stored in slave
		
		//MSB(0xFA)
		SPDR = 0X00; //For reading the MSB, send 0X00 so that data from slave comes to master.
		// Wait until transmission is complete
		while (! (SPSR & (1 << SPIF)));
		// Read MSB which is now in SPDR
		MSB = SPDR; 
		
		// LSB (0xFB)
		SPDR = 0x00;
		while (! (SPSR & (1 << SPIF)));
		LSB = SPDR;

		// XLSB (0xFC)
		SPDR = 0x00;
		while (! (SPSR & (1 << SPIF)));
		XLSB = SPDR;
		
		// Pull SS high to deselect slave
		PORTB |= (1 << PORTB2);
		
		// COMBINE TO GET 20 BIT TEMP VALUE
		raw_temp = ((uint32_t)MSB << 12) | ((uint32_t)LSB << 4) | ((uint32_t)XLSB >> 4);
		
		/*//Read temp through uart
		UART_TxString("dig_T1 = "); 
		UART_TxNumber(dig_T1); 
		UART_TxString("\r\n");
		UART_TxString("dig_T2 = "); 
		UART_TxNumber(dig_T2); 
		UART_TxString("\r\n");
		UART_TxString("dig_T3 = "); 
		UART_TxNumber(dig_T3); 
		UART_TxString("\r\n");
		
		UART_TxString("RAW TEMP = ");
		UART_TxNumber(raw_temp);
		UART_TxString("\r\n");*/
		
		var1 = (((raw_temp / 16384.0) - (dig_T1 / 1024.0)) * dig_T2);
		var2 = ((((raw_temp / 131072.0) - (dig_T1 / 8192.0))) * dig_T3);
		temp_final = var1 + var2;
		temp = temp_final / 5120.0;
		
		UART_TxString("TEMP = ");
		int temp_int = (int)temp;
		int temp_frac = ((temp - temp_int) * 100);
		UART_TxNumber(temp_int);
		UART_TxChar('.');
		UART_TxNumber(temp_frac);
		UART_TxString(" C\r\n");
		
        //Turn LED ON if chip id is 0x58
		if (chip_id == 0x58)
		{
			// Turn LED ON
			PORTB |= (1 << PORTB0);
		}
		else
		{
			// Turn LED OFF
			PORTB &= ~ (1 << PORTB0);
		}
		
		_delay_ms(1000);
	}
	
}
