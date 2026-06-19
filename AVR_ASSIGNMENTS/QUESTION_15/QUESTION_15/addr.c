/*
 * addr.c
 *
 * Created: 19-06-2026 22:38:09
 *  Author: anagh
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "addr.h"

uint8_t OLED_ADDR   = 0x78;
uint8_t BMP280_ADDR = 0x76;