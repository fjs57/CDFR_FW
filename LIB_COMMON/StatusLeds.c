/*
 * StatusLeds.c
 *
 *  Created on: Nov 9, 2024
 *      Author: francois
 */

#include "StatusLeds.h"

#define STATUSLED_APPLICATION_BLINK_PERIOD 500
#define STATUSLED_APPLICATION_BLINK_HIGH_TIME 250

#define STATUSLED_ERROR_BLINK_PERIOD 250
#define STATUSLED_ERROR_BLINK_HIGH_TIME 200

#define STATUSLED_COM_HIGH_TIME 10

typedef struct
{
	bool enable;
	uint32_t time_ref;
}
StatusLed_Data_t;

typedef struct
{
	StatusLed_Data_t ApplicationLed;
	StatusLed_Data_t ErrorLed;
	StatusLed_Data_t RxDataLed;
	StatusLed_Data_t TxDataLed;
	bool initialized;
}
StatusLeds_Data_t;

typedef struct
{
	uint32_t period;
	uint32_t high_time;
}
StatusLed_Config_t;

typedef struct
{
	StatusLed_Config_t ApplicationLed;
	StatusLed_Config_t ErrorLed;
	StatusLed_Config_t RxDataLed;
	StatusLed_Config_t TxDataLed;
}
StatusLeds_Config_t;

typedef struct
{
	StatusLeds_Descriptor_t *descriptor;
	StatusLeds_Config_t config;
	StatusLeds_Data_t data;
}
StatusLeds_Instance_t;

StatusLeds_Instance_t StatusLeds_Instance = {
		.config = {
				.ApplicationLed = {
						.period = STATUSLED_APPLICATION_BLINK_PERIOD,
						.high_time = STATUSLED_APPLICATION_BLINK_HIGH_TIME
				},
				.ErrorLed = {
						.period = STATUSLED_ERROR_BLINK_PERIOD,
						.high_time = STATUSLED_ERROR_BLINK_HIGH_TIME
				},
				.RxDataLed = {
						.period = 0,
						.high_time = STATUSLED_COM_HIGH_TIME
				},
				.TxDataLed = {
						.period = 0,
						.high_time = STATUSLED_COM_HIGH_TIME
				}
		},
		.data = {
				.initialized = 0,
				.ApplicationLed = {
						.enable = 1,
						.time_ref = 0
				},
				.ErrorLed = {
						.enable = 0,
						.time_ref = 0
				},
				.RxDataLed = {
						.enable = 0,
						.time_ref = 0
				},
				.TxDataLed = {
						.enable = 0,
						.time_ref = 0
				}
		}
};

static void StatusLedProcess(GPIO_Pin_t *pin, StatusLed_Config_t *cfg, StatusLed_Data_t *data);

static void StatusLedProcess(GPIO_Pin_t *pin, StatusLed_Config_t *cfg, StatusLed_Data_t *data)
{
	uint32_t time;
	bool state;

	time = HAL_GetTick();

	if ( cfg->period != 0 )
	{
		if ( time >= data->time_ref+cfg->period )
		{
			data->time_ref = time;
		}
	}

	if ( cfg->high_time != 0 )
	{
		state = ( time <= data->time_ref+cfg->high_time );
	}
	else
	{
		state = 1;
	}

	state = state && data->enable;

	HAL_GPIO_WritePin(pin->port, pin->pin, state);
}

void StatusLeds_Init(StatusLeds_Descriptor_t *descriptor)
{
	StatusLeds_Instance.descriptor = descriptor;
	StatusLeds_Instance.data.initialized = 1;
}

void StatusLeds_kHz_Process(void)
{
	if (!StatusLeds_Instance.data.initialized) return;

	StatusLedProcess(
		&(StatusLeds_Instance.descriptor->ApplicationLed),
		&(StatusLeds_Instance.config.ApplicationLed),
		&(StatusLeds_Instance.data.ApplicationLed)
	);

	StatusLedProcess(
		&(StatusLeds_Instance.descriptor->ErrorLed),
		&(StatusLeds_Instance.config.ErrorLed),
		&(StatusLeds_Instance.data.ErrorLed)
	);

	StatusLedProcess(
		&(StatusLeds_Instance.descriptor->RxDataLed),
		&(StatusLeds_Instance.config.RxDataLed),
		&(StatusLeds_Instance.data.RxDataLed)
	);

	StatusLedProcess(
		&(StatusLeds_Instance.descriptor->TxDataLed),
		&(StatusLeds_Instance.config.TxDataLed),
		&(StatusLeds_Instance.data.TxDataLed)
	);
}

void StatusLeds_TxEvent(void)
{
	StatusLeds_Instance.data.TxDataLed.time_ref = HAL_GetTick();
	StatusLeds_Instance.data.TxDataLed.enable = 1;
}

void StatusLeds_RxEvent(void)
{
	StatusLeds_Instance.data.RxDataLed.time_ref = HAL_GetTick();
	StatusLeds_Instance.data.RxDataLed.enable = 1;
}

void StatusLeds_SetError(void)
{
	StatusLeds_Instance.data.ErrorLed.enable = 1;
}

void StatusLeds_ResetError(void)
{
	StatusLeds_Instance.data.ErrorLed.enable = 0;
}

void StatusLeds_FatalError(void)
{
	HAL_GPIO_WritePin(StatusLeds_Instance.descriptor->ErrorLed.port, StatusLeds_Instance.descriptor->ErrorLed.pin, 1);
}
