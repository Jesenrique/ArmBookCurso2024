//=====[Libraries]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"
#include "pressure_sensor.h"
#include "control_system.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
DigitalOut pump1(LED2);
DigitalOut pump2(LED3);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
bool statePump1 = false;
bool statePump2 = false;

//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================
static bool statusPump1();
static bool statusPump2();
static void checkPressure();

//=====[Implementations of public functions]===================================
void pumpsInit(){
    pump1=false;
    pump2=false;
}

void stopPumps(){
    pump1=false;
    pump2=false;
}

void runPumps(){
    pump1=true;
    pump2=true;
}


bool StatePump1Read()
{
    return pump1;
}

bool StatePump2Read()
{
    return pump2;
}


//=====[Implementations of private functions]==================================
