Goal: configure registers to enable LED pin in order to turn it on and off.

Steps:
	1. Locating which pin, the user LED is located (PA5 datasheet)
	2. define addresses and their offset for various registers, RCC_R(enabling clock ergister), AHB1 register(bus address) (since GPIOA is connecte to this), GPIOA-MODER/ODR
	3. configure bits from addressed locating in order to manipulate LED.
	
