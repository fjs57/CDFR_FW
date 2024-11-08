/*
 * Board.h
 *
 *  Created on: Nov 8, 2024
 *      Author: francois
 */

#ifndef BOARD_H_
#define BOARD_H_

typedef enum
{
	BOARD_NO_ERROR = 0,
	BOARD_GENERIC_ERROR
}
Board_ErrorCode_t;

uint32_t Board_GetTimestamp(void);
float Board_GetTemperature(void);
Board_ErrorCode_t Board_GetErrorCode(void);
uint32_t Board_GetFirmwareVersion(void);

#endif /* BOARD_H_ */
