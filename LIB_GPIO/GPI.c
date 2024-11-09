/*
 * GPI.c
 *
 *  Created on: Nov 8, 2024
 *      Author: francois
 */

#include "GPI.h"

#define GPI_DESC GPI_Instance.descriptor
#define GPI_CFG GPI_Instance.config
#define GPI_COUNT GPI_Instance.descriptor.count
#define GPI_PINS GPI_Instance.descriptor.pins
#define GPI_STATES GPI_Instance.data.states
#define GPI_OLD_STATES GPI_Instance.data.old_states
#define GPI_LAST_SEND GPI_Instance.data.last_send
#define GPI_PERIOD GPI_Instance.config.send_period

typedef struct
{
	GPIO_Pin_t pins[GPI_MAX_COUNT];
	uint16_t count;
}
GPI_Descriptor_t;

typedef struct
{
	bool states[GPI_MAX_COUNT];
	bool old_states[GPI_MAX_COUNT];
	uint32_t last_send;
}
GPI_Data_t;

typedef struct
{
	GPI_Descriptor_t descriptor;
	GPI_Config_t config;
	GPI_Data_t data;
}
GPI_Instance_t;

GPI_Instance_t GPI_Instance;

static void GPI_ReadStates(void);
static bool GPI_IsStateChanged(void);

static void GPI_ReadStates(void)
{
	uint16_t id;
	GPIO_Pin_t *pin;
	for(id=0; id<GPI_COUNT; id++)
	{
		GPI_OLD_STATES[id] = GPI_STATES[id];

		pin = &(GPI_PINS[id]);
		GPI_STATES[id] = HAL_GPIO_ReadPin(pin->port, pin->pin);
	}
}

static bool GPI_IsStateChanged(void)
{
	uint16_t id;
	for(id=0; id<GPI_COUNT; id++)
	{
		if ( GPI_OLD_STATES[id] != GPI_STATES[id] ) return 1;
	}
	return 0;
}



void GPI_Init(GPIO_Pin_t *pins, uint16_t count)
{
	if(count>GPI_MAX_COUNT)
	{
		while(1); // forbidden case
	}
	memcpy(GPI_PINS, pins, count);
	GPI_COUNT = count;
}

void GPI_Process(void)
{
	GPI_ReadStates();
}

bool GPI_GetState(uint16_t id)
{
	if ( id >= GPI_COUNT ) return 0; // forbidden case
	return GPI_STATES[id];
}

void GPI_SetConfig(GPI_Config_t *new_config)
{
	memcpy(&GPI_CFG, new_config, sizeof(GPI_Config_t));
}

bool GPI_SendingRequired(void)
{
	if ( GPI_CFG.send_on_change && GPI_IsStateChanged()) return 1;
	if ( GPI_CFG.send_periodically_states && HAL_GetTick() >= (GPI_LAST_SEND+GPI_PERIOD)) return 1;
	return 0;
}

void GPI_SendingPerformed(void)
{
	GPI_LAST_SEND = HAL_GetTick();
}
