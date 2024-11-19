//=====[#include guards - begin]===============================================
#include <stdio.h>
#include <string.h>
#include "mbed.h"
#ifndef _PRESSURE_SENSOR_H_
#define _PRESSURE_SENSOR_H_

//=====[Declaration of public defines]=========================================
extern Ticker timeCheckPressure;

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void pressureSensorInit();
void pressureSensorUpdate();
void strPressureM1(char* buffer, size_t bufferSize);
void strPressureM2(char* buffer, size_t bufferSize);
float readPressureM1();
float readPressureM2();

//=====[#include guards - end]=================================================

#endif // _PRESSURE_SENSOR_H_