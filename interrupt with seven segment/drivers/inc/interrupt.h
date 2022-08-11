/*
 * interrupt.h
 *
 *  Created on: May 28, 2022
 *      Author: lamis
 */

#ifndef INC_INTERRUPT_H_
#define INC_INTERRUPT_H_

void INTERRUPT_Init (char pin, char port);
void ISR_OF_EXTI0(void);
void ISR_OF_EXTI1(void);

#endif /* INC_INTERRUPT_H_ */
