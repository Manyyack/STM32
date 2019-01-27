/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 9.0.0   2019-01-06

The MIT License (MIT)
Copyright (c) 2018 STMicroelectronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************************
*/

/* Includes */
#include <stddef.h>
#include "stm32f10x.h"
#include "uart_driver.h"
#include <stdio.h>


int main()
{
	/*
	 * Enable all Ports(A,B,C,D and E) and Alternate Function clocks
	 */
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN |
	    RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPDEN | RCC_APB2ENR_AFIOEN;

	/*
	 * Disable JTAG and SWO (Free PB3, PB4 and PA15)
	 */
	AFIO->MAPR = AFIO_MAPR_SWJ_CFG_JTAGDISABLE;

	/*
	 * Enable the PA1 as a digital output
	 */
	GPIOA->CRL = 0x00000020;

	/*
	 * Enable the high speed external
	 * oscillator
	 */
	RCC->CR |= RCC_CR_HSEON;

	/*
	 * Waits until the external oscillator
	 * is ready
	 */
	while((RCC->CR & RCC_CR_HSERDY) == 0);

	/*
	 * PLL Source: HSE
	 * PLL Multiply Factor: 9 , Hence the PLLOUT will be 72Mhz
	 * USB Prescaler: 0
	 * AHB Prescaler: 1 , Hence AHB out will be 72 Mhz
	 * APB1 Prescaler: 2, Hence the APB1 out will be 36 Mhz
	 * APB2 Prescaler: 1, Hence APB2 out will be 72Mhzz
	 * ADC Prescaler: 6 , Hence ADC Out will be 12Mhz
	 */
	RCC->CFGR = RCC_CFGR_PLLMULL9 | RCC_CFGR_PPRE2_DIV1 |
		RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_ADCPRE_DIV6 |
		RCC_CFGR_PLLSRC | RCC_CFGR_HPRE_DIV1 ;

	/*
	 * Enable the PLL
	 */
	RCC->CR |= RCC_CR_PLLON;

	/*
	 * Waits until the PLL is ready
	 */
	while((RCC->CR & RCC_CR_PLLRDY) == 0);

	/*
	 * Switch the System clock to the PLL
	 */
	RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW_PLL) | RCC_CFGR_SW_PLL;

	/*
	 * Updates the   SystemCoreClock variable
	 * Now the CPU clock is 3*HSE (24MHz for
	 * an 8MHz oscillator)
	 */
	SystemCoreClockUpdate();

	uart_init(115200,72000000);


	/*
	 * Turn off the LED
	 */
	GPIOA->BSRR = GPIO_BSRR_BS1;

	while(1)
	{
		/*
		 * Waits until a character is received
		 */
		switch (Getc_USART1())
		{
		case '0':
			GPIOA->BSRR = GPIO_BSRR_BS1; //PA1 = 1 (Led OFF)
			printf("LED OFF\r\n");
			break;

		default :
			GPIOA->BSRR = GPIO_BSRR_BR1; //PA1 = 0 (Led ON)
			printf("LED ON\r\n");
			break;
		}
	}
}

