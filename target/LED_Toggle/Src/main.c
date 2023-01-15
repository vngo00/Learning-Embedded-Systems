/*
 * toggle user LED by manipulating the addresses
 *
 * Step 1:
 * 		locating the pin the the LED is connected to
 * 		Port: A
 * 		Pin : 5
 *
 * Step 2:
 * 		Locating various addresses related to the port A and their offsets:
 * 		peripheral address, bus address, general purpose address(in this case A)
 * 		RCC -> help enable clock for bus
 *
 */


#define PERIPH_BASE				(0x40000000UL) //base address of peripheral mem
#define AHB1PERIPH_OFFSET		(0X00020000UL) // offset from base address
#define ABH1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET			(0x0000U)

#define GPIOA_BASE			(ABH1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(ABH1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET			(0x30UL)
#define RCC_AHB1EN_R			(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))	// mode register for port A


#define OD_R_OFFSET				(0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))




#define GPIOAEN					(1U<<0)

#define PIN5					(1U<<5)
#define LED_PIN					PIN5

int main(void)
{
	// 1. enable clock access to GPIOA
	RCC_AHB1EN_R |=	GPIOAEN;

	// 2. set output mode to MODER
	GPIOA_MODE_R	|= (1U<<10); // bit 10th to 1
	GPIOA_MODE_R	&=~(1U<<11); // bit 11th to 0

	while(1)
	{
		// 3. set PA5 on
		GPIOA_OD_R |= LED_PIN;
	}


}

