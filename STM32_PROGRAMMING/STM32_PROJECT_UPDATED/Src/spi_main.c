#include <stdint.h>
#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_spi_driver.h"
#include "main.h"

/*void delay_ms(uint32_t delay)
{
	for(uint32_t i = 0 ; i < (delay * 5000) ; i++);
}*/
#if SPI_APP
int main(void)
{
	/*---------------- SPI GPIO CONFIGURATION ----------------*/

	gpio_handle_t spi_gpio;

	spi_gpio.port = GPIO_PORTA;
	spi_gpio.config.pinMode = PIN_MODE_ALTFN;
	spi_gpio.config.pinAltFun = 5;
	spi_gpio.config.pinSpeed = PIN_SPEED_FAST;
	spi_gpio.config.pinType = OUTPUT_PUSH_PULL;
	spi_gpio.config.pinPull = NO_PULL;

	gpio_clock_control(GPIO_PORTA,ENABLE_FLAG);

	/* PA5 -> SCK */

	spi_gpio.config.pinNumber = PIN_5;
	gpio_init(&spi_gpio);

	/* PA6 -> MISO */

	spi_gpio.config.pinNumber = PIN_6;
	gpio_init(&spi_gpio);

	/* PA7 -> MOSI */

	spi_gpio.config.pinNumber = PIN_7;
	gpio_init(&spi_gpio);

	/*---------------- SPI CONFIGURATION ----------------*/

	spi_handle_t spi1_handle;

	spi1_handle.spi = SPI1;

	spi1_handle.config.deviceMode = SPI_DEVICE_MODE_MASTER;

	spi1_handle.config.busConfig = SPI_BUS_FULL_DUPLEX;

	spi1_handle.config.sclkSpeed = SPI_SCLK_DIV8;

	spi1_handle.config.dff = SPI_DFF_8BITS;

	spi1_handle.config.cpol = SPI_CPOL_LOW;

	spi1_handle.config.cpha = SPI_CPHA_LOW;

	spi1_handle.config.ssm = SPI_SSM_ENABLE;

	spi_clock_control(SPI1,ENABLE_FLAG);

	spi_init(&spi1_handle);

	spi_peripheral_control(SPI1,ENABLE_FLAG);

	/* SSI = 1 */

	SPI1->CR1 |= (1 << 8);

	uint8_t message[] = "HELLO STM32\r\n";

	while(1)
	{
		spi_send_data(SPI1,message,sizeof(message)-1);

		delay_ms(1000);
	}
}
#endif
