/*
 * keypad.c
 *
 *  Created on: May 17, 2022
 *      Author: lamis
 */
#include "stm32f4xx.h"
#include "GPIO.h"

const int no_raws = 4;
const int no_cols = 3;
char rows[4]={1,2,3,4}; //fill the array
char cols[3]={5,6,7}; //fill the array

char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array

char currentvalue;

void KeyPad_INIT(void)
{

		for(int i = 0; i < no_cols; i++){
			GPIO_Init(GPIOA ,cols[i], 1, 0);
		}

		for(int j = 0; j < no_raws; j++){
			GPIO_Init(GPIOA, rows[j], 0, 0);
		}
	}


void KeyPad_MANAGE(void)
{
			//looping till enter the key
		for(int b = 0 ; b < no_cols ; b++)
			{
				for(int a = 0; a < no_cols; a++)
				{
					GPIO_Write(GPIOA,cols[a],(a==b)?0:1);
				}
				//test the column that equal 0 in it and reading rows
				for(int c = 0 ; c < no_raws ; c++)
				{
							char x = GPIO_Read(GPIOA, rows[c]);
							//while(x==0)
							if(x == 0){

							while(GPIO_Read(GPIOA,rows[c])==0);
                            currentvalue = lookupTable[c][b];
							KeypadCallouts_KeyPressNotificaton();
							}
		}
		  }
			 }


char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
	int i;
	char value = KeyPad_GET_VALUE();
	switch(value){
	case 0:
		GPIO_Write(GPIOA,8,0);
		GPIO_Write(GPIOA,9,0);
		GPIO_Write(GPIOA,10,0);
		GPIO_Write(GPIOA,11,0);
		for(i=0 ; i<500000; i++){}
		break;
	case 1:
		 GPIO_Write(GPIOA,8,0);
		 GPIO_Write(GPIOA,9,0);
		 GPIO_Write(GPIOA,10,0);
		 GPIO_Write(GPIOA,11,1);
		for(i=0 ; i<500000; i++){}
		break;
	case 2:
	    GPIO_Write(GPIOA,8,0);
		GPIO_Write(GPIOA,9,0);
		GPIO_Write(GPIOA,10,1);
		GPIO_Write(GPIOA,11,0);
		for(i=0 ; i<500000; i++){}
		break;
	case 3:
		 GPIO_Write(GPIOA,8,0);
	     GPIO_Write(GPIOA,9,0);
		 GPIO_Write(GPIOA,10,1);
		 GPIO_Write(GPIOA,11,1);
		 for(i=0 ; i<500000; i++){}
		 break;
	case 4 :
		 GPIO_Write(GPIOA,8,0);
		 GPIO_Write(GPIOA,9,1);
		 GPIO_Write(GPIOA,10,0);
		 GPIO_Write(GPIOA,11,0);
		 for(i=0 ; i<500000; i++){}
		 break;
	case 5:
		 GPIO_Write(GPIOA,8,0);
		 GPIO_Write(GPIOA,9,1);
		 GPIO_Write(GPIOA,10,0);
		 GPIO_Write(GPIOA,11,1);
		 for(i=0 ; i<500000; i++){}
		 break;
	case 6:
		 GPIO_Write(GPIOA,8,0);
		 GPIO_Write(GPIOA,9,1);
		 GPIO_Write(GPIOA,10,1);
		 GPIO_Write(GPIOA,11,0);
		 for(i=0 ; i<500000; i++){}
		 break;
	case 7:
		 GPIO_Write(GPIOA,8,0);
		 GPIO_Write(GPIOA,9,1);
		 GPIO_Write(GPIOA,10,1);
		 GPIO_Write(GPIOA,11,1);
		 for(i=0 ; i<500000; i++){}
		 break;
	case 8:
		 GPIO_Write(GPIOA,8,1);
		 GPIO_Write(GPIOA,9,0);
		 GPIO_Write(GPIOA,10,0);
		 GPIO_Write(GPIOA,11,0);
		 for(i=0 ; i<500000; i++){}
		 break;
	case 9:
		 GPIO_Write(GPIOA,8,1);
		 GPIO_Write(GPIOA,9,0);
		 GPIO_Write(GPIOA,10,0);
		 GPIO_Write(GPIOA,11,1);
		 for(i=0 ; i<500000; i++){}
		 break;
	}
}



