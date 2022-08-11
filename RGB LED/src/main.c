/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

//#include "stm32f4xx.h"
#include <stdio.h>
#include "gpio1.h"
#include "lcd.h"
#include "ADC.h"

unsigned short int data;
unsigned short int* DataPtr = &data;
unsigned char ConversionState;
unsigned char* ConversionStatePtr = &ConversionState;
unsigned char ChannelNum;

int main(void)
{

	LCD_Init();
	ADCConfigType configuration = {Res8,cont,1.5};
	ADC_Init(&configuration);
	ADC_StartConv(0);


	while(1)
	{

		ADC_GetConversionState(ConversionStatePtr);
		if(ConversionState)
		{
		    ADC_ReadData(DataPtr);
			LCD_IntToStr(data);
			for(int i=0;i<10000000; i++){}
			LCD_ClearScreen();
		}

}
}


