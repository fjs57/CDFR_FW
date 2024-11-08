/*
 * COM.h
 *
 *  Created on: Nov 6, 2024
 *      Author: francois
 */

#ifndef COM_H_
#define COM_H_

#include "main.h"

void COM_Init(void);
void COM_Process(void);
void COM_kHz_Process(void);

void COM_ReceiveFrame(uint8_t *buf, uint32_t len);


void COM_SendMcuId(void);
void COM_SendMcuStatus(void);
void COM_SendSafetyWatchdogPing(void);
void COM_SendSafetyWatchdogConfig(void);
void COM_SendSafetyWatchdogStatus(void);
void COM_SendEmergencyStop(void);

void COM_SendStepperEnable_1(void);
void COM_SendStepperEnable_2(void);
void COM_SendStepperEnable_3(void);
void COM_SendStepperEnable_4(void);

void COM_SendStepperMode_1(void);
void COM_SendStepperMode_2(void);
void COM_SendStepperMode_3(void);
void COM_SendStepperMode_4(void);

void COM_SendStepperTelemetry_1(void);
void COM_SendStepperTelemetry_2(void);
void COM_SendStepperTelemetry_3(void);
void COM_SendStepperTelemetry_4(void);

void COM_SendStepperTargetSpeed_1(void);
void COM_SendStepperTargetSpeed_2(void);
void COM_SendStepperTargetSpeed_3(void);
void COM_SendStepperTargetSpeed_4(void);

void COM_SendStepperTargetPosition_1(void);
void COM_SendStepperTargetPosition_2(void);
void COM_SendStepperTargetPosition_3(void);
void COM_SendStepperTargetPosition_4(void);

void COM_SendStepperCurrentSpeed_1(void);
void COM_SendStepperCurrentSpeed_2(void);
void COM_SendStepperCurrentSpeed_3(void);
void COM_SendStepperCurrentSpeed_4(void);

void COM_SendStepperCurrentPosition_1(void);
void COM_SendStepperCurrentPosition_2(void);
void COM_SendStepperCurrentPosition_3(void);
void COM_SendStepperCurrentPosition_4(void);

void COM_SendStepperConfig_1(void);
void COM_SendStepperConfig_2(void);
void COM_SendStepperConfig_3(void);
void COM_SendStepperConfig_4(void);

void COM_SendStepperStatus_1(void);
void COM_SendStepperStatus_2(void);
void COM_SendStepperStatus_3(void);
void COM_SendStepperStatus_4(void);

void COM_SendServosEnable(void);
void COM_SendServosSetTarget(void);
void COM_SendServosSetVoltage(void);
void COM_SendServosStatus(void);

void COM_SendDigitalInputStates(void);
void COM_SendDigitalInputConfig(void);
void COM_SendDigitalOutputStates(void);
void COM_SendAnalogInputStates(void);
void COM_SendAnalogInputConfig(void);

void COM_SendEncoderState_1(void);
void COM_SendEncoderConfig_1(void);
void COM_SendEncoderState_2(void);
void COM_SendEncoderConfig_2(void);

void COM_SendResetBoard(void);
void COM_SendGoToDfu(void);


#endif /* COM_H_ */
