/*
 * StatusLeds.h
 *
 *  Created on: Nov 9, 2024
 *      Author: francois
 */

#ifndef STATUSLEDS_H_
#define STATUSLEDS_H_

#include "GPIO.h"

typedef struct
{
	GPIO_Pin_t ApplicationLed;
	GPIO_Pin_t ErrorLed;
	GPIO_Pin_t RxDataLed;
	GPIO_Pin_t TxDataLed;
}
StatusLeds_Descriptor_t;

void StatusLeds_Init(StatusLeds_Descriptor_t *descriptor);
void StatusLeds_kHz_Process(void);

void StatusLeds_TxEvent(void);
void StatusLeds_RxEvent(void);

void StatusLeds_SetError(void);
void StatusLeds_ResetError(void);
void StatusLeds_FatalError(void);


#endif /* STATUSLEDS_H_ */
