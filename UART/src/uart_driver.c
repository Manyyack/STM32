/*
 * uart_driver.c
 *
 *  Created on: Jan 6, 2019
 *      Author: ShreelPC
 */

#include "uart_driver.h"
#include "stm32f10x.h"

int _write(int file, char *ptr, int len)
{
int DataIdx;
   for (DataIdx = 0; DataIdx < len; DataIdx++)
   {
	   Putc_USART1((*ptr++));
   }
   return len;
}

/*
 * UART initialization
 */
void uart_init(unsigned int baud,unsigned int clock)
{

	float value = (float)clock/(baud*16);
	int value2 = (int)((float)(value-(int)value)*16);
	int value3 = (int )value;

	/*
		 * Selects the PA9 as the USART1 RX
		 * Selects the PA10 as the USART1 TX
		 */
	GPIOA->CRH = (GPIOA->CRH & 0xFFFFF00F) | 0x000004B0;

	/*
	 * Enable the clock for the USART1
	 */
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

	/*
	 * Adjusts the USART1 bit rate to
	 * 38400 bps (for an 24MHz input clock)
	 */
	USART1->BRR = value3 << 4 | value2;

	/*
	 * Enable the USART1 Transmitter and
	 * Receiver
	 */
	USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
}

/*
 * Receive a character from serial port
 */
char Getc_USART1()
{
	while(!(USART1->SR & USART_SR_RXNE));
	return USART1->DR;
}

/*
 * Write a character through the serial port
 */
void Putc_USART1(char CharSend)
{
	while(!(USART1->SR & USART_SR_TXE));
	USART1->DR = CharSend;
}

/*
 * Write a string through the serial port
 */
void Puts_USART1(const char * StringSend)
{
	uint32_t StrCount = 0;
	while (StringSend[StrCount])
	{
		Putc_USART1(StringSend[StrCount]);
		StrCount ++;
	}
}
