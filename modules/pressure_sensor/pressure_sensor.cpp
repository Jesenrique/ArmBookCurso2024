//=====[Libraries]=============================================================
#include "arm_book_lib.h"
#include "pumps.h"
#include "pressure_sensor.h"

//=====[Declaration of private defines]========================================
#define PRESSURE_CUT_IN_P1          20//psi
#define PRESSURE_CUT_OFF_P1         80//psi
#define TIME_INCREMENT_MS           10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
AnalogIn potentiometer(A0);
Ticker timeCheckPressure; 

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
float valuePressure1=0.0;
float valuePressure2=0.0;
bool flagUpdateAnalogValue= true;
float analogValue=0.0;
float voltagePsi;

//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================
float readPressureM1();
float readPressureM2();

//=====[Implementations of public functions]===================================

void pressureSensorInit() {
    timeCheckPressure.attach(checkPressure, 1500ms);
}

void pressureSensorUpdate(){ 
    while(flagUpdateAnalogValue){
        if (valuePressure1 <= PRESSURE_CUT_IN_P1) {
            stopPumps();
        } else if (valuePressure1 > PRESSURE_CUT_IN_P1 && valuePressure1 <= PRESSURE_CUT_OFF_P1) {
            runPumps();
        } else {
            stopPumps();
        }

        if (valuePressure2 <= PRESSURE_CUT_IN_P1) {
            stopPumps();
        } else if (valuePressure2 > PRESSURE_CUT_IN_P1 && valuePressure2 <= PRESSURE_CUT_OFF_P1) {
            runPumps();
        } else {
            stopPumps();
        }
        flagUpdateAnalogValue=false;
        analogValue = potentiometer.read();  
    }
};

void strPressureM1(char* buffer, size_t bufferSize){
    snprintf(buffer, bufferSize, "%.2f", valuePressure1); // Convertir float a char
}

void strPressureM2(char* buffer, size_t bufferSize){
    snprintf(buffer, bufferSize, "%.2f", valuePressure2); // Convertir float a char
}

float readPressureM1(){
    return valuePressure1;
}

float readPressureM2(){
    return valuePressure2;
}


void checkPressure() {
    voltagePsi= analogValue* 3.3*30;
    valuePressure1=voltagePsi;
    valuePressure2=valuePressure1-5;
    flagUpdateAnalogValue=true;
}


//=====[Implementations of private functions]==================================

