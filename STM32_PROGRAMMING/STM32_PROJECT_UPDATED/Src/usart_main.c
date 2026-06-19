#include <stdint.h>
#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_usart_driver.h"
#include "main.h"
#if USART_APP
int main(void)
{
	/*---------------- GPIO CONFIGURATION FOR USART2 ----------------*/

	gpio_handle_t gpio_tx;

	gpio_tx.port = GPIO_PORTA;
	gpio_tx.config.pinNumber = PIN_2;
	gpio_tx.config.pinMode = PIN_MODE_ALTFN;
	gpio_tx.config.pinAltFun = 7;
	gpio_tx.config.pinSpeed = PIN_SPEED_FAST;
	gpio_tx.config.pinType = OUTPUT_PUSH_PULL;
	gpio_tx.config.pinPull = PULL_UP;

	gpio_clock_control(GPIO_PORTA, ENABLE_FLAG);
	gpio_init(&gpio_tx);

	gpio_handle_t gpio_rx;

	gpio_rx.port = GPIO_PORTA;
	gpio_rx.config.pinNumber = PIN_3;
	gpio_rx.config.pinMode = PIN_MODE_ALTFN;
	gpio_rx.config.pinAltFun = 7;
	gpio_rx.config.pinSpeed = PIN_SPEED_FAST;
	gpio_rx.config.pinType = OUTPUT_PUSH_PULL;
	gpio_rx.config.pinPull = PULL_UP;

	gpio_init(&gpio_rx);

	/*---------------- USART2 CONFIGURATION ----------------*/

	usart_handle_t uart2;

	uart2.usart = USART2;
	uart2.config.baudRate = 9600;
	uart2.config.wordLength = USART_WORDLEN_8BITS;
	uart2.config.parityControl = USART_PARITY_DISABLE;
	uart2.config.stopBits = USART_STOPBITS_1;
	uart2.config.mode = USART_MODE_TXRX;

	usart_clock_control(USART2, ENABLE_FLAG);

	usart_init(&uart2);

	/*---------------- ECHO APPLICATION ----------------*/

	uint8_t rx_data;

	while(1)
	{
		usart_receive_data(USART2,&rx_data,1);

		usart_send_data(USART2,&rx_data,1);
	}
}
#endif
