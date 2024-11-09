/*
 * GPI.h
 *
 *  Created on: Nov 8, 2024
 *      Author: francois
 */

#ifndef GPI_H_
#define GPI_H_

#include "GPIO.h"

#define GPI_MAX_COUNT 16

typedef struct
{
	bool send_periodically_states;
	uint32_t send_period;
	bool send_on_change;
}
GPI_Config_t;

void GPI_Init(GPIO_Pin_t *pins, uint16_t count);
void GPI_Process(void);

bool GPI_GetState(uint16_t id);
void GPI_SetConfig(GPI_Config_t *new_config);

bool GPI_SendingRequired(void);
void GPI_SendingPerformed(void);

#endif /* GPI_H_ */
