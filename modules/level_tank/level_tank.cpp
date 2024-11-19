
//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "control_panel.h"


//=====[Declaration of private defines]========================================


//=====[Declaration of private data types]=====================================
typedef enum {
    LEVEL_HIGH,
    LEVEL_MEDIUM,
    LEVEL_LOW,
    EMPTY,
    FAIL,
} levelState_t;


//=====[Declaration and initialization of public global objects]===============
InterruptIn highLevel(PC_10);
DigitalIn highLevelSensor(PC_10);
InterruptIn mediumLevel(PC_12);
DigitalIn mediumLevelSensor(PC_12);
InterruptIn lowLevel(PF_6);
DigitalIn lowLevelSensor(PF_6);
InterruptIn empty(PF_7);
DigitalIn emptySensor(PF_7);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
levelState_t levelState;
//=====[Declaration and initialization of private global variables]============
static int timeIncrement_ms = 0;
static int accumulatedDebouncebuttonTime = 0;

//=====[Declarations (prototypes) of private functions]========================
static void highLevelCallback();
static void mediumLevelCallback();
static void lowLevelCallback();
static void emptyLevelCallback();

//=====[Implementations of public functions]===================================
void levelTankInit()
{   
    highLevel.mode(PullDown);
    mediumLevel.mode(PullDown);
    lowLevel.mode(PullDown);
    empty.mode(PullDown);

    //verifica de inicio el nivel del tanque
    highLevel.rise(&highLevelCallback);
    mediumLevel.rise(&mediumLevelCallback);
    lowLevel.rise(&lowLevelCallback);
    empty.rise(&emptyLevelCallback);
    
    highLevel.fall(&highLevelCallback);
    mediumLevel.fall(&mediumLevelCallback);
    lowLevel.fall(&lowLevelCallback);
    empty.fall(&emptyLevelCallback);
}

const char* levelTankUpdate()
{
    switch(levelState){

        case LEVEL_HIGH:
        return("ALTO     ");
        break;

        case LEVEL_MEDIUM:
        return("MEDIO    ");
        break;

        case LEVEL_LOW:
        return("BAJO     ");
        break;

        case EMPTY:
        return("VACIO    ");
        break;

        case FAIL:
        return("ERROR SENSOR");
        break;
    }
}


//=====[Implementations of private functions]==================================
static void highLevelCallback(){
    if (mediumLevelSensor.read() && lowLevelSensor.read() && emptySensor.read()){
        if(highLevelSensor.read()) {
            levelState = LEVEL_HIGH;
            stopTankFull();
            }
        else {
            levelState = LEVEL_MEDIUM;
            fillTank();
            }
    }
    else levelState = FAIL;
}
static void mediumLevelCallback(){
    if (lowLevelSensor.read() && emptySensor.read() ) {
        if(mediumLevelSensor.read()) levelState = LEVEL_MEDIUM;
        else levelState = LEVEL_LOW;
        }
    else levelState = FAIL;
}
static void lowLevelCallback(){
    if(emptySensor.read()) levelState = LEVEL_LOW;
    else levelState = EMPTY;
}
static void emptyLevelCallback(){
    if ( !highLevelSensor.read() && !mediumLevelSensor.read() && !lowLevelSensor.read() ) {
        levelState = EMPTY;
        
    }
    else {
    stopEmergencyControlPanel();
    levelState = FAIL;
    }
}
