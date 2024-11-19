//=====[#include guards - begin]===============================================

#ifndef _PUMPS_
#define _PUMPS_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void pumpsInit();
void runPumps();
void stopPumps();
bool StatePump1Read();
bool StatePump2Read();
void checkPressure();

//=====[#include guards - end]=================================================

#endif // _PUMPS_