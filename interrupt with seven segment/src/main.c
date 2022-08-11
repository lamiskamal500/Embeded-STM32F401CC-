/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "GPIO.h"
#include "interrupt.h"


int main(void)
{
	INTERRUPT_Init(0,'B');
	INTERRUPT_Init(1,'B');

	GPIO_Init(GPIOB,0,0,1);
	GPIO_Init(GPIOB,1,0,1);
	GPIO_Init(GPIOA,0,1,0);
	GPIO_Init(GPIOA,1,1,0);
	GPIO_Init(GPIOA,2,1,0);
	GPIO_Init(GPIOA,3,1,0);
}


void ISR_OF_EXTI0(void)
{

	char a = GPIO_Read(GPIOB,0);
	char c = GPIO_Read(GPIOA,0);
	char d = GPIO_Read(GPIOA,1);
	char e = GPIO_Read(GPIOA,2);
	char f = GPIO_Read(GPIOA,3);
	int i;
	if(a==0){
	if(!(f) && !(e) && !(d) && (c)){
		GPIO_Write(GPIOA,3,0);
		GPIO_Write(GPIOA,2,0);
		GPIO_Write(GPIOA,1,0);
		GPIO_Write(GPIOA,0,0);
		for(i=0 ; i<500000; i++){}
	}
	else if(!(f) && !(e) && (d) && !(c)){
		GPIO_Write(GPIOA,3,0);
		GPIO_Write(GPIOA,2,0);
		GPIO_Write(GPIOA,1,0);
		GPIO_Write(GPIOA,0,1);
		for(i=0 ; i<500000; i++){}
		}
	else if(!(f) && !(e) && (d) && (c)){
		GPIO_Write(GPIOA,3,0);
		GPIO_Write(GPIOA,2,0);
		GPIO_Write(GPIOA,1,1);
		GPIO_Write(GPIOA,0,0);
		for(i=0 ; i<500000; i++){}
		}
	else if(!(f) && (e) && !(d) && !(c)){
		GPIO_Write(GPIOA,3,0);
		GPIO_Write(GPIOA,2,0);
		GPIO_Write(GPIOA,1,1);
		GPIO_Write(GPIOA,0,1);
		for(i=0 ; i<500000; i++){}
		}
	else if(!(f) && (e) && !(d) && (c)){
		GPIO_Write(GPIOA,3,0);
		GPIO_Write(GPIOA,2,1);
		GPIO_Write(GPIOA,1,0);
		GPIO_Write(GPIOA,0,0);
		for(i=0 ; i<500000; i++){}
		}
	else if(!(f) && (e) && (d) && !(c)){
		GPIO_Write(GPIOA,3,0);
		GPIO_Write(GPIOA,2,1);
		GPIO_Write(GPIOA,1,0);
		GPIO_Write(GPIOA,0,1);
		for(i=0 ; i<500000; i++){}
		}
	else if(!(f) && (e) && (d) && (c)){
		GPIO_Write(GPIOA,3,0);
		GPIO_Write(GPIOA,2,1);
		GPIO_Write(GPIOA,1,1);
		GPIO_Write(GPIOA,0,0);
		for(i=0 ; i<500000; i++){}
		}
	else if((f) && !(e) && !(d) && !(c)){
		GPIO_Write(GPIOA,3,0);
		GPIO_Write(GPIOA,2,1);
		GPIO_Write(GPIOA,1,1);
		GPIO_Write(GPIOA,0,1);
		for(i=0 ; i<500000; i++){}
		}
	else if((f) && !(e) && !(d) && (c)){
		GPIO_Write(GPIOA,3,1);
		GPIO_Write(GPIOA,2,0);
		GPIO_Write(GPIOA,1,0);
		GPIO_Write(GPIOA,0,0);
		for(i=0 ; i<500000; i++){}
		}

	}
}
void ISR_OF_EXTI1(void){
		char b = GPIO_Read(GPIOB,1);
		char c = GPIO_Read(GPIOA,0);
		char d = GPIO_Read(GPIOA,1);
		char e = GPIO_Read(GPIOA,2);
		char f = GPIO_Read(GPIOA,3);
			int i;
	   if(b==0){
		if(!(f) && !(e) && !(d) && !(c)){
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,0,1);
			for(i=0 ; i<500000; i++){}
		}
		else if(!(f) && !(e) && !(d) && (c)){
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,0,0);
			for(i=0 ; i<500000; i++){}
			}
		else if(!(f) && !(e) && (d) && !(c)){
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,0,1);
			for(i=0 ; i<500000; i++){}
			}
		else if(!(f) && !(e) && (d) && (c)){
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,0,0);
			for(i=0 ; i<500000; i++){}
			}
		else if(!(f) && (e) && !(d) && !(c)){
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,0,1);
			for(i=0 ; i<500000; i++){}
			}
		else if(!(f) && (e) && !(d) && (c)){
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,0,0);
			for(i=0 ; i<500000; i++){}
			}
		else if(!(f) && (e) && (d) && !(c)){
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,0,1);
			for(i=0 ; i<500000; i++){}
			}
		else if(!(f) && (e) && (d) && (c)){
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,0,0);
			for(i=0 ; i<500000; i++){}
			}
		else if((f) && !(e) && !(d) && !(c)){
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,0,1);
			for(i=0 ; i<500000; i++){}
			}
		else if(!(f) && !(e) && !(d) && !(c)){
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,0,1);
			for(i=0 ; i<500000; i++){}
			}
		}
}


void EXTI0_IRQHandler(void){
ISR_OF_EXTI0();

}
void EXTI1_IRQHandler(void){
ISR_OF_EXTI1();
}

