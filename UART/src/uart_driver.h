/*
 * uart_driver.h
 *
 *  Created on: Jan 6, 2019
 *      Author: ShreelPC
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

/*
 * UART initialization
 */
void uart_init(unsigned int baud,unsigned int clock);

/*
 * Receive a character from serial port
 */
char Getc_USART1();

/*
 * Write a character through the serial port
 */

void Putc_USART1(char CharSend);
/*
 * Write a string through the serial port
 */
void Puts_USART1(const char * StringSend);

#endif /* UART_DRIVER_H_ */
