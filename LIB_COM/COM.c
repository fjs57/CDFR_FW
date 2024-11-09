/*
 * COM.c
 *
 *  Created on: Nov 6, 2024
 *      Author: francois
 */


#include "../LIB_COM/COM.h"

#include "usbd_cdc_if.h"

#include "../LIB_COM/CDFR_COM_LIB/nanoPB/common/pb_common.h"
#include "../LIB_COM/CDFR_COM_LIB/nanoPB/common/pb_decode.h"
#include "../LIB_COM/CDFR_COM_LIB/nanoPB/common/pb_encode.h"
#include "../LIB_COM/CDFR_COM_LIB/nanoPB/messages/Common.pb.h"
#include "../LIB_COM/CDFR_COM_LIB/nanoPB/messages/Encoder.pb.h"
#include "../LIB_COM/CDFR_COM_LIB/nanoPB/messages/GPIO.pb.h"
#include "../LIB_COM/CDFR_COM_LIB/nanoPB/messages/Servo.pb.h"
#include "../LIB_COM/CDFR_COM_LIB/nanoPB/messages/Stepper.pb.h"
#include "../LIB_COM/CDFR_COM_LIB/TinyFrame/TF.h"
#include "../LIB_COMMON/Board.h"

TinyFrame COM_tf;

void TF_WriteImpl(TinyFrame *tf, const uint8_t *buff, uint32_t len)
{
	CDC_Transmit_FS((uint8_t*)buff, len);
}

TF_Result COM_FallbackListener(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnMcuIdReceived(TinyFrame *tf, TF_Msg *msg)
{
	BoardStatus data;
	pb_ostream_t ostream;
	TF_Msg txmsg;

	data.board_timestamp = Board_GetTimestamp();
	data.error_code = Board_GetErrorCode();
	data.temperature = Board_GetTemperature();
	data.firmware_version = Board_GetFirmwareVersion();

	ostream = pb_ostream_from_buffer((pb_byte_t*)txmsg.data, BoardStatus_size);

	if( pb_encode(&ostream, &BoardStatus_msg, (const void*)&data) )
	{
		TF_Send(&COM_tf, &txmsg);
	}
	return TF_STAY;
}

TF_Result COM_OnMcuStatusReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnSafetyWatchdogPingReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnSafetyWatchdogConfigReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnSafetyWatchdogStatusReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnEmergencyStopReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}



TF_Result COM_OnStepperEnableReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperEnableReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperEnableReceived_3(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperEnableReceived_4(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnStepperModeReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperModeReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperModeReceived_3(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperModeReceived_4(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnStepperTelemetryReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperTelemetryReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperTelemetryReceived_3(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperTelemetryReceived_4(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnStepperTargetSpeedReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperTargetSpeedReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperTargetSpeedReceived_3(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperTargetSpeedReceived_4(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnStepperTargetPositionReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperTargetPositionReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperTargetPositionReceived_3(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperTargetPositionReceived_4(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnStepperCurrentSpeedReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperCurrentSpeedReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperCurrentSpeedReceived_3(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperCurrentSpeedReceived_4(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnStepperCurrentPositionReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperCurrentPositionReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperCurrentPositionReceived_3(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperCurrentPositionReceived_4(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnStepperConfigReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperConfigReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperConfigReceived_3(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperConfigReceived_4(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnStepperStatusReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperStatusReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperStatusReceived_3(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnStepperStatusReceived_4(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}



TF_Result COM_OnServosEnableReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnServosSetTargetReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnServosSetVoltageReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnServosStatusReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnDigitalInputStatesReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnDigitalInputConfigReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnDigitalOutputStatesReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnAnalogInputStatesReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnAnalogInputConfigReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnEncoderStateReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnEncoderConfigReceived_1(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnEncoderStateReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnEncoderConfigReceived_2(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}


TF_Result COM_OnResetBoardReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}

TF_Result COM_OnGoToDfuReceived(TinyFrame *tf, TF_Msg *msg)
{
	return TF_STAY;
}











void COM_SendMcuId(void)
{

}

void COM_SendMcuStatus(void)
{

}

void COM_SendSafetyWatchdogPing(void)
{

}

void COM_SendSafetyWatchdogConfig(void)
{

}

void COM_SendSafetyWatchdogStatus(void)
{

}

void COM_SendEmergencyStop(void)
{

}



void COM_SendStepperEnable_1(void)
{

}

void COM_SendStepperEnable_2(void)
{

}

void COM_SendStepperEnable_3(void)
{

}

void COM_SendStepperEnable_4(void)
{

}


void COM_SendStepperMode_1(void)
{

}

void COM_SendStepperMode_2(void)
{

}

void COM_SendStepperMode_3(void)
{

}

void COM_SendStepperMode_4(void)
{

}


void COM_SendStepperTelemetry_1(void)
{

}

void COM_SendStepperTelemetry_2(void)
{

}

void COM_SendStepperTelemetry_3(void)
{

}

void COM_SendStepperTelemetry_4(void)
{

}


void COM_SendStepperTargetSpeed_1(void)
{

}

void COM_SendStepperTargetSpeed_2(void)
{

}

void COM_SendStepperTargetSpeed_3(void)
{

}

void COM_SendStepperTargetSpeed_4(void)
{

}


void COM_SendStepperTargetPosition_1(void)
{

}

void COM_SendStepperTargetPosition_2(void)
{

}

void COM_SendStepperTargetPosition_3(void)
{

}

void COM_SendStepperTargetPosition_4(void)
{

}


void COM_SendStepperCurrentSpeed_1(void)
{

}

void COM_SendStepperCurrentSpeed_2(void)
{

}

void COM_SendStepperCurrentSpeed_3(void)
{

}

void COM_SendStepperCurrentSpeed_4(void)
{

}


void COM_SendStepperCurrentPosition_1(void)
{

}

void COM_SendStepperCurrentPosition_2(void)
{

}

void COM_SendStepperCurrentPosition_3(void)
{

}

void COM_SendStepperCurrentPosition_4(void)
{

}


void COM_SendStepperConfig_1(void)
{

}

void COM_SendStepperConfig_2(void)
{

}

void COM_SendStepperConfig_3(void)
{

}

void COM_SendStepperConfig_4(void)
{

}


void COM_SendStepperStatus_1(void)
{

}

void COM_SendStepperStatus_2(void)
{

}

void COM_SendStepperStatus_3(void)
{

}

void COM_SendStepperStatus_4(void)
{

}



void COM_SendServosEnable(void)
{

}

void COM_SendServosSetTarget(void)
{

}

void COM_SendServosSetVoltage(void)
{

}

void COM_SendServosStatus(void)
{

}


void COM_SendDigitalInputStates(void)
{

}

void COM_SendDigitalInputConfig(void)
{

}

void COM_SendDigitalOutputStates(void)
{

}

void COM_SendAnalogInputStates(void)
{

}

void COM_SendAnalogInputConfig(void)
{

}


void COM_SendEncoderState_1(void)
{

}

void COM_SendEncoderConfig_1(void)
{

}

void COM_SendEncoderState_2(void)
{

}

void COM_SendEncoderConfig_2(void)
{

}


void COM_SendResetBoard(void)
{

}

void COM_SendGoToDfu(void)
{

}



void COM_Init(void)
{
	TF_InitStatic(&COM_tf, TF_SLAVE);
	TF_AddGenericListener(&COM_tf, COM_FallbackListener);

	TF_AddTypeListener(&COM_tf, TF_TYPE_MCU_ID, 					COM_OnMcuIdReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_MCU_STATUS, 				COM_OnMcuStatusReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_SAFETY_WATCHDOG_PING, 		COM_OnSafetyWatchdogPingReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_SAFETY_WATCHDOG_CONFIG, 	COM_OnSafetyWatchdogConfigReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_SAFETY_WATCHDOG_STATUS, 	COM_OnSafetyWatchdogStatusReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_EMERGENCY_STOP, 			COM_OnEmergencyStopReceived);

	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_1_ENABLE, 			COM_OnStepperEnableReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_1_MODE, 			COM_OnStepperModeReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_1_TELEMETRY, 		COM_OnStepperTelemetryReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_1_TARGET_SPEED, 	COM_OnStepperTargetSpeedReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_1_TARGET_POSITION, 	COM_OnStepperTargetPositionReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_1_CURRENT_SPEED, 	COM_OnStepperCurrentSpeedReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_1_CURRENT_POSITION, COM_OnStepperCurrentPositionReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_1_CONFIG, 			COM_OnStepperConfigReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_1_STATUS, 			COM_OnStepperStatusReceived_1);
	
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_2_ENABLE, 			COM_OnStepperEnableReceived_2);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_2_MODE, 			COM_OnStepperModeReceived_2);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_2_TELEMETRY, 		COM_OnStepperTelemetryReceived_2);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_2_TARGET_SPEED, 	COM_OnStepperTargetSpeedReceived_2);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_2_TARGET_POSITION, 	COM_OnStepperTargetPositionReceived_2);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_2_CURRENT_SPEED, 	COM_OnStepperCurrentSpeedReceived_2);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_2_CURRENT_POSITION, COM_OnStepperCurrentPositionReceived_2);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_2_CONFIG, 			COM_OnStepperConfigReceived_2);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_2_STATUS, 			COM_OnStepperStatusReceived_2);

	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_3_ENABLE, 			COM_OnStepperEnableReceived_3);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_3_MODE, 			COM_OnStepperModeReceived_3);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_3_TELEMETRY, 		COM_OnStepperTelemetryReceived_3);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_3_TARGET_SPEED, 	COM_OnStepperTargetSpeedReceived_3);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_3_TARGET_POSITION, 	COM_OnStepperTargetPositionReceived_3);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_3_CURRENT_SPEED, 	COM_OnStepperCurrentSpeedReceived_3);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_3_CURRENT_POSITION, COM_OnStepperCurrentPositionReceived_3);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_3_CONFIG, 			COM_OnStepperConfigReceived_3);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_3_STATUS, 			COM_OnStepperStatusReceived_3);

	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_4_ENABLE, 			COM_OnStepperEnableReceived_4);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_4_MODE, 			COM_OnStepperModeReceived_4);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_4_TELEMETRY, 		COM_OnStepperTelemetryReceived_4);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_4_TARGET_SPEED, 	COM_OnStepperTargetSpeedReceived_4);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_4_TARGET_POSITION, 	COM_OnStepperTargetPositionReceived_4);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_4_CURRENT_SPEED, 	COM_OnStepperCurrentSpeedReceived_4);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_4_CURRENT_POSITION, COM_OnStepperCurrentPositionReceived_4);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_4_CONFIG, 			COM_OnStepperConfigReceived_4);
	TF_AddTypeListener(&COM_tf, TF_TYPE_STEPPER_4_STATUS, 			COM_OnStepperStatusReceived_4);

	TF_AddTypeListener(&COM_tf, TF_TYPE_SERVOS_ENABLE, 				COM_OnServosEnableReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_SERVOS_SET_TARGET, 			COM_OnServosSetTargetReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_SERVOS_SET_VOLTAGE, 		COM_OnServosSetVoltageReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_SERVOS_STATUS, 				COM_OnServosStatusReceived);


	TF_AddTypeListener(&COM_tf, TF_TYPE_DIGITAL_INPUT_STATES, 		COM_OnDigitalInputStatesReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_DIGITAL_INPUT_CONFIG, 		COM_OnDigitalInputConfigReceived);

	TF_AddTypeListener(&COM_tf, TF_TYPE_DIGITAL_OUTPUT_STATES, 		COM_OnDigitalOutputStatesReceived);

	TF_AddTypeListener(&COM_tf, TF_TYPE_ANALOG_INPUT_STATES, 		COM_OnAnalogInputStatesReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_ANALOG_INPUT_CONFIG, 		COM_OnAnalogInputConfigReceived);

	TF_AddTypeListener(&COM_tf, TF_TYPE_ENCODER_1_STATE, 			COM_OnEncoderStateReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_ENCODER_1_CONFIG, 			COM_OnEncoderConfigReceived_1);
	TF_AddTypeListener(&COM_tf, TF_TYPE_ENCODER_2_STATE, 			COM_OnEncoderStateReceived_2);
	TF_AddTypeListener(&COM_tf, TF_TYPE_ENCODER_2_CONFIG, 			COM_OnEncoderConfigReceived_2);

	TF_AddTypeListener(&COM_tf, TF_TYPE_RESET_BOARD, 				COM_OnResetBoardReceived);
	TF_AddTypeListener(&COM_tf, TF_TYPE_GO_TO_DFU, 					COM_OnGoToDfuReceived);

}

void COM_ReceiveFrame(uint8_t *buf, uint32_t len)
{
	TF_Accept(&COM_tf, buf, len);
}

void COM_Process(void)
{

}

void COM_kHz_Process(void)
{
	TF_Tick(&COM_tf);
}
