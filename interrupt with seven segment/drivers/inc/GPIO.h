/*
 * GPIO.h
 *
 *  Created on: May 31, 2022
 *      Author: lamis
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_


void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin);
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);
char GPIO_Read(GPIO_TypeDef * GPIOx,char pin);

#endif /* INC_GPIO_H_ */
