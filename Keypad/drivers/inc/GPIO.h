/*
 * GPIO.h
 *
 *  Created on: May 13, 2022
 *      Author: lamis
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin);
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);
char GPIO_Read(GPIO_TypeDef * GPIOx,char pin);

void KeyPad_INIT(void);
void KeyPad_MANAGE(void);
void KeypadCallouts_KeyPressNotificaton(void);
char KeyPad_GET_VALUE(void);

#endif /* INC_GPIO_H_ */
