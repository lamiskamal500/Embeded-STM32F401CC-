/*
 * ADC.h
 *
 *  Created on: Jun 4, 2022
 *      Author: lamis
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_
#define USE_POLLING 1


#include <stdio.h>
#include "stm32f4xx.h"

typedef enum {Res12, Res10, Res8, Res6} Resolution;
typedef enum {single, cont} ConversionMode;
typedef struct
	{
	Resolution res;
	ConversionMode conv;
	int RefVoltage;
	} ADCConfigType;

void ADC_Init(ADCConfigType* ptr);
void ADC_StartConv(unsigned char ChannelNum);
unsigned char ADC_ReadData(unsigned short int* DataPtr);
void ADC_GetConversionState(unsigned char* ConversionStatePtr);
void ADC_IRQHandler(void);

#endif /* INC_ADC_H_ */
