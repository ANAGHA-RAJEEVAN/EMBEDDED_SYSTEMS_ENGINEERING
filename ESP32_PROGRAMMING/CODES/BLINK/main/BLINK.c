#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN  GPIO_NUM_2

void app_main(void)
{
    gpio_reset_pin(LED_PIN);  //Reset the GPIO pin
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);  //Set the GPIO pin as output

    while (1) 
    {
        gpio_set_level(LED_PIN, 1);        // Turn the LED on
        vTaskDelay(pdMS_TO_TICKS(500));   // Wait for 1 second
        gpio_set_level(LED_PIN, 0);        // Turn the LED off
        vTaskDelay(pdMS_TO_TICKS(500));   // Wait for 1 second
    }
   
}