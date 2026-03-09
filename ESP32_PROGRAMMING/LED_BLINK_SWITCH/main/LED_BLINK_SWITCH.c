#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED  GPIO_NUM_2    //This is the pin number for onboard led.
#define SWITCH GPIO_NUM_5 //This is the pin number for the externl switch we are using.

void app_main(void)
{
    // LED setup
    gpio_reset_pin(LED);  //Reset the GPIO pin in case it was used before.
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);  //Set the GPIO pin as output
    // Switch setup
    gpio_reset_pin(SWITCH);  //Reset the GPIO pin in case it was used before.
    gpio_set_direction(SWITCH, GPIO_MODE_INPUT);  //Set the pin as input
    gpio_set_pull_mode(SWITCH, GPIO_PULLUP_ONLY);   // Enable internal pullup .

    while (1) 
    {
        if (gpio_get_level(SWITCH) == 0) // Check if the switch is pressed   
            {
                gpio_set_level(LED, 1);        // Turn the LED on
            } 
            else 
            {
                gpio_set_level(LED, 0);        // Turn the LED off
            }
            vTaskDelay(pdMS_TO_TICKS(100));   // Wait for 100 milliseconds 
    }
   
}
