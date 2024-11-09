/*
 * GPO.c
 *
 *  Created on: Nov 8, 2024
 *      Author: francois
 */

#include "GPO.h"

#include "string.h"

#define GPO_DESC GPO_Instance.descriptor
#define GPO_COUNT GPO_DESC.count
#define GPO_PINS GPO_DESC.pins
#define GPO_STATES GPO_Instance.data.states

typedef struct
{
	GPIO_Pin_t pins[GPO_MAX_COUNT];
	uint16_t count;
}
GPO_Descriptor_t;

typedef struct
{
	bool states[GPO_MAX_COUNT];
}
GPO_Data_t;

typedef struct
{
	GPO_Descriptor_t descriptor;
	GPO_Data_t data;
}
GPO_Instance_t;

GPO_Instance_t GPO_Instance;

void GPO_Init(GPIO_Pin_t *pins, uint16_t count)
{
	if(count>GPO_MAX_COUNT)
	{
		while(1); // forbidden case
	}
	memcpy(GPO_PINS, pins, count);
	GPO_COUNT = count;
}

void GPO_Process(void)
{
	uint16_t id;
	for ( id=0; id<GPO_COUNT; id++ )
	{
		HAL_GPIO_WritePin(GPO_PINS[id].port, GPO_PINS[id].pin, GPO_STATES[id]);
	}
}

void GPO_SetState(uint16_t id, bool state)
{
	if ( id >= GPO_COUNT ) return; // forbidden case
	GPO_STATES[id] = state;
}

bool GPO_GetState(uint16_t id)
{
	if ( id >= GPO_COUNT ) return 0; // forbidden case
	return GPO_STATES[id];
}
