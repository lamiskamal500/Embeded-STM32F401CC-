/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include<stdint.h>
#include "stm32f4xx.h"
#include "GPIO.h"

int main(void)
{

	GPIO_Init(GPIOA,8,1,0);
	GPIO_Init(GPIOA,9,1,0);
	GPIO_Init(GPIOA,10,1,0);
	GPIO_Init(GPIOA,11,1,0);

	KeyPad_INIT();

	while(1)
	{
	 KeyPad_MANAGE();
	}
}
