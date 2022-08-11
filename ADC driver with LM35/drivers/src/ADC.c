/*
 * ADC.c
 *
 *  Created on: Jun 4, 2022
 *      Author: lamis
 */
#include <stdio.h>
#include "stm32f4xx.h"
#include "ADC.h"

unsigned short int data;
unsigned char ConversionState;
unsigned char ChannelNum;

//struct ADCConfigType *ptr;
void ADC_Init(ADCConfigType* ptr){

	RCC->AHB1ENR |=(1u<<0);
	// pin 1 to analog mode
	GPIOA->MODER |= (1u<<0);
	GPIOA->MODER |= (1u<<1);
	// Enable clock access to ADC1
	RCC->APB2ENR |= (1u<<8);
	// Enable the ADC
	ADC1->CR2 |= (1u<<0);
	if(ptr->res){
		if(ptr->res == Res8){
			ADC1 -> CR1 &=~ (1u<<24);
			ADC1 -> CR1 |= (1u<<25);
		}
		else if(ptr->res == Res12){
			ADC1 -> CR1 &=~ (1u<<24);
			ADC1 -> CR1 &=~ (1u<<25);
		}
		else if(ptr->res == Res10){
			ADC1 -> CR1 |= (1u<<24);
			ADC1 -> CR1 &=~ (1u<<25);
		}
		else if(ptr->res == Res6){
			ADC1 -> CR1 |= (1u<<24);
			ADC1 -> CR1 |= (1u<<25);
		}
	}
	if(ptr->conv){
		if(ptr->conv==single){
			ADC1->CR2 &=~ (1u<<1);
		}
		else if(ptr->conv==cont){
			ADC1->CR2 |= (1u<<1);
		}
	}
}

void ADC_StartConv(unsigned char ChannelNum){

	ADC1->SQR1 &=~ (1u<<20);
	ADC1->SQR1 &=~ (1u<<21);
	ADC1->SQR1 &=~ (1u<<22);
	ADC1->SQR1 &=~ (1u<<23);

	if (ChannelNum==0){
		ADC1->CR2 &=~ (1u<<1);
		ADC1->CR2 |= (1u<<30);
	}
	else if(ChannelNum==1){
		ADC1->CR2 |= (1u<<1);
		ADC1->CR2 |= (1u<<30);
		ADC1->SQR3 = (1u<<0);
	}
}

#if USE_POLLING == 1
void ADC_GetConversionState(unsigned char* ConversionStatePtr){
	if (!(ADC1->SR & (1u<<1))){
		*ConversionStatePtr = 1;
	}
	else{
		*ConversionStatePtr = 0;
	}
}
#endif

unsigned char ADC_ReadData(unsigned short int* DataPtr){
	if(data){
		*DataPtr = data;
		*DataPtr = ADC1->DR;
		return 0;
	}
	else{
		return 1;
	}
}


#if USE_POLLING == 0
void ADC_IRQHandler(void){
	ISR(data);
}
#endif








