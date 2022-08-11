/*
 * GPIO.c
 *
 *  Created on: May 13, 2022
 *      Author: lamis
 */
//#include "stm32f4xx.h"
//#include "GPIO.h"
//
//void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin)
//{
//	RCC->AHB1ENR |= (1u<<enable_pin);
//	if(dir)
//	{
//		GPIOx->MODER  |= (1u<<(2*pin));
//		GPIOx->MODER  &=~(1u<<(2*pin+1));
//		GPIOx->OTYPER &=~ (1u<<pin);
//
//	}
//	else
//	{
//		GPIOx->MODER &=~(1u<<(2*pin));
//		GPIOx->MODER &=~(1u<<(2*pin+1));
//		GPIOx->PUPDR |= (1u<<(2*pin));
//		GPIOx->PUPDR &=~(1u<<(2*pin+1));
//	}
//}
//
//char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state)
//{
//	if ((GPIOx->MODER & (1u<<(2*pin))) && !(GPIOx->MODER & (1u<<(2*pin+1))))
//	{
//		if(state)
//			{
//				GPIOx->ODR |=(1u<<pin);
//			}
//			else
//			{
//				GPIOx->ODR &=~(1u<<pin);
//			}
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//char GPIO_Read(GPIO_TypeDef * GPIOx,char pin){
//	 if (! ((GPIOx->MODER & (1u<<(2*pin))) && (GPIOx->MODER & (1u<<(2*pin+1)))))
//	 {
//	  int data = (GPIOx->IDR & (1 << pin)) ;
//	  return data;
//	 }
//	 else
//	 {
//	 	return 0;
//	 }
//}
//
//
//
//
