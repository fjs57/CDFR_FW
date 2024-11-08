/*
 * Board.c
 *
 *  Created on: Nov 8, 2024
 *      Author: francois
 */


#include "Board.h"

uint32_t Board_GetTimestamp(void)
{
	return HAL_GetTick();
}

float Board_GetTemperature(void)
{
	return 999.99;
}

Board_ErrorCode_t Board_GetErrorCode(void)
{
	return BOARD_NO_ERROR;
}

uint32_t Board_GetFirmwareVersion(void)
{
	return FW_VERSION;
}
