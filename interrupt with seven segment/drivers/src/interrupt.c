/*
 * interrupt.c

 *
 *  Created on: May 28, 2022
 *      Author: lamis
 */

#include "stm32f4xx.h"
#include "GPIO.h"
#include "interrupt.h"


void INTERRUPT_Init (char pin, char port)
{
	//Enable clock of interrupt
	RCC->APB2ENR|=(1u<<14);
	//enable mask register
	EXTI->IMR |=(1u<<pin);
	//falling edge
	EXTI->FTSR |=(1u<<pin);
	//enable nvic
	NVIC->ISER[0]|=(1u<<(6+pin));

	char x;
	char y;
	if(pin>=0 && pin<=3)
	{
		x = pin;
		y = 0;
	}
	else if (pin>=4 && pin<=7){
		x = pin-4;
		y = 1;
	}
	switch(port){
	case 'A':
		SYSCFG->EXTICR[y] &=~(1u<<4*x);
		SYSCFG->EXTICR[y] &=~(1u<<4*x+1);
		SYSCFG->EXTICR[y] &=~(1u<<4*x+2);
		SYSCFG->EXTICR[y] &=~(1u<<4*x+3);
		break;
	case 'B':
     	SYSCFG->EXTICR[y] |= (1u<<4*x);
	    SYSCFG->EXTICR[y] &=~(1u<<4*x+1);
    	SYSCFG->EXTICR[y] &=~(1u<<4*x+2);
    	SYSCFG->EXTICR[y] &=~(1u<<4*x+3);
    	break;
	}
}
