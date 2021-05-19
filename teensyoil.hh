#include <Arduino.h>
#include <FlexCAN_T4.h>
#include <math.h>

#define OIL_SENSOR_MSG_ID 0x015

uint16_t parseOilSensorMessage(CAN_message_t msg, float* oilLevel, float* pcbTemp, float* oilTemp);
