/*
 * GPO.h
 *
 *  Created on: Nov 9, 2024
 *      Author: francois
 */

#ifndef GPO_H_
#define GPO_H_

#include "GPIO.h"

#define GPO_MAX_COUNT 16

void GPO_Init(GPIO_Pin_t *pins, uint16_t count);

void GPO_Process(void);

void GPO_SetState(uint16_t id, bool state);

bool GPO_GetState(uint16_t id);

#endif /* GPO_H_ */
