/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 9.0.0   2018-08-11

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

/**
**===========================================================================
**
**  Function Declarations
**
**===========================================================================
*/
void setPin13asOP();
void setPin14asOP();
void setPin15asOP();

void setPin13High();
void setPin14High();
void setPin15High();

void setPin13Low();
void setPin14Low();
void setPin15Low();

void setPin13asIpFloating();
void setPin14asIpFloating();
void setPin15asIpFloating();



/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
	//RCC->APB2RSTR |= (1<<4);		//RESET the port C;
	//RCC->APB2RSTR &= ~(1<<4);		//RESET the port C;
	RCC->APB2ENR |= (1<<4);		//Enable the clock for port C;

	while(1)
	{
		setPin13asIpFloating();
		setPin15asOP();
		setPin14asOP();

		setPin15High();
		setPin14Low();
		setPin15Low();

		setPin13asIpFloating();
		setPin15asOP();
		setPin14asOP();

		setPin14High();
		setPin15Low();
		setPin14Low();

		setPin15asIpFloating();
		setPin13asOP();
		setPin14asOP();

		setPin13High();
		setPin14Low();
		setPin13Low();

		setPin15asIpFloating();
		setPin13asOP();
		setPin14asOP();

		setPin14High();
		setPin13Low();
		setPin14Low();

		setPin14asIpFloating();
		setPin13asOP();
		setPin15asOP();

		setPin13High();
		setPin15Low();
		setPin13Low();

		setPin14asIpFloating();
		setPin13asOP();
		setPin15asOP();

		setPin15High();
		setPin13Low();
		setPin15Low();
	}
}

void setPin13asOP()
{
	GPIOC->CRH &= ~((1<<21)|(1<<22)|(1<<23));
	GPIOC->CRH |= (1<<20);		//pin 13 as op and push pull
}

void setPin14asOP()
{
	GPIOC->CRH &= ~((1<<25)|(1<<26)|(1<<27));
	GPIOC->CRH |= (1<<24);		//pin 14 as op and push pull
}

void setPin15asOP()
{
	GPIOC->CRH &= ~((1<<29)|(1<<30)|(1<<31));
	GPIOC->CRH |= (1<<28);		//pin 15 as op and push pull
}

void setPin13High()
{
	GPIOC->BSRR |= (1<<13);		//pin 13 as op and push pull
}

void setPin14High()
{
	GPIOC->BSRR |= (1<<14);		//pin 14 as op and push pull
}

void setPin15High()
{
	GPIOC->BSRR |= (1<<15);		//pin 15 as op and push pull
}

void setPin13Low()
{
	GPIOC->BRR |= (1<<13);		//pin 13 as op and push pull
}

void setPin14Low()
{
	GPIOC->BRR |= (1<<14);		//pin 14 as op and push pull
}

void setPin15Low()
{
	GPIOC->BRR |= (1<<15);		//pin 15 as op and push pull
}

void setPin13asIpFloating()
{
	GPIOC->CRH &= ~((1<<20)|(1<<21)|(1<<23));
	GPIOC->CRH |= (1<<22);
}

void setPin14asIpFloating()
{
	GPIOC->CRH &= ~((1<<24)|(1<<25)|(1<<27));
	GPIOC->CRH |= (1<<26);
}

void setPin15asIpFloating()
{
	GPIOC->CRH &= ~((1<<28)|(1<<29)|(1<<31));
	GPIOC->CRH |= (1<<30);
}
