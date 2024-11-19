//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "buttons.h"
#include "display.h"
#include "matrix_keypad.h"
#include "pressure_sensor.h"
#include "pumps.h"
#include "serial_communication.h"
#include "level_tank.h"

//=====[Declaration of private defines]========================================
#define TIME_INCREMENT_MS 10

//=====[Declaration of private defines]========================================
typedef enum {
  INIT,
  PRESSURE_SP1,
  PRESSURE_SP2,
  PUMP1,
  PUMP2,
  LEVEL_TANK,
  STOP
} lcdState_t;

typedef enum { MENU, READ_KEYPAD, CONFIRM, EXIT } ajustFrequency_t;

typedef enum {
  OPTIONS,
  CHANGE_FREQUENCY,
  STATUS_SYSTEM,
  STOP_SYSTEM
} options_menu_t;

//=====[Declaration and initialization of public global objects]===============
Ticker tickerChangeStateLcd;

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
bool flagMenuFrecuency = false;
bool stopSystemFlag = true;
const char* statusTank;

//=====[Declaration and initialization of private global variables]============
static int transitionTime = 0;
static int timeChangeFrequency = 0;

static lcdState_t lcdState;
static ajustFrequency_t ajustFrequency;
static options_menu_t options_menu;
static int length;

static char keyPressedList[3];
static bool confirmFrequency = false;
static bool statusMenuFrecuency = false;

//=====[Declarations (prototypes) of private functions]========================
static void updateMenuDisplay();
static void ajustValueFrequency();
static void selectOptionMenu();
static void changeStatuslcd();

//=====[Implementations of public functions]===================================

void controlPanelInit() {
  matrixKeypadInit(10);
  serialComInit();
  buttonsInit(10);
  displayInit(DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER);
  pressureSensorInit();
  pumpsInit();
  levelTankInit();
  lcdState = INIT;
  ajustFrequency = MENU;
  options_menu = OPTIONS;
  tickerChangeStateLcd.attach(changeStatuslcd, 4000ms);
}

void controlPanelUpdate() {
  if (stopSystemFlag) {
    pressureSensorUpdate();
  }
  if (statusButton()) {
    flagMenuFrecuency = true;
  }
  if (flagMenuFrecuency) {
    ajustValueFrequency();
  }
  updateMenuDisplay();
}

void stopEmergencyControlPanel() {
  stopSystemFlag = false;
  lcdState = STOP;
  tickerChangeStateLcd.detach();
}

void stopTankFull() {
  stopPumps();
  stopSystemFlag = false;
}

void fillTank() {
  runPumps();
  stopSystemFlag = true;
}

static void changeStatuslcd() {
  if (lcdState <= PUMP2) {
    lcdState = lcdState_t(lcdState + 1);
  } else {
    lcdState = PRESSURE_SP1;
  }
}

//=====[Implementations of private functions]==================================

static void updateMenuDisplay() {
  char buffer[16];
  switch (lcdState) {
  case INIT:
    displayCharPositionWrite(0, 0);
    displayStringWrite("Iniciando");
    displayCharPositionWrite(0, 1);
    displayStringWrite("Sistema...");
    break;

  case PRESSURE_SP1:
    displayCharPositionWrite(0, 0);
    displayStringWrite("Presion SP1: ");
    displayCharPositionWrite(0, 1);
    strPressureM1(buffer,
                  sizeof(buffer)); // Llamar con el tamaño correcto del buffer
    displayStringWrite(buffer);
    displayStringWrite(" psi  ");
    break;

  case PRESSURE_SP2:
    displayCharPositionWrite(0, 0);
    displayStringWrite("Presion SP2: ");
    displayCharPositionWrite(0, 1);
    strPressureM2(buffer, sizeof(buffer));
    displayStringWrite(buffer);
    displayStringWrite(" psi   ");
    break;

  case PUMP1:
    displayCharPositionWrite(0, 0);
    displayStringWrite("Bomba 1:    ");
    displayCharPositionWrite(0, 1);
    length = snprintf(buffer, sizeof(buffer), "%s",
                      StatePump1Read() ? "Encendida" : "Apagada  ");
    displayStringWrite(buffer);
    break;

  case PUMP2:
    displayCharPositionWrite(0, 0);
    displayStringWrite("Bomba 2:    ");
    displayCharPositionWrite(0, 1);
    length = snprintf(buffer, sizeof(buffer), "%s",
                      StatePump2Read() ? "Encendida" : "Apagada  ");
    displayStringWrite(buffer);
    break;

  case LEVEL_TANK:
    displayCharPositionWrite(0, 0);
    displayStringWrite("Nivel tanque:   ");
    displayCharPositionWrite(0, 1);
    statusTank = levelTankUpdate();
    displayStringWrite(statusTank);
    break;

  case STOP:
    displayCharPositionWrite(0, 0);
    displayStringWrite("PARO EMERGENCIA");
    displayCharPositionWrite(0, 1);
    displayStringWrite("    ACTIVADO    ");
    stopPumps();
    break;
  }
}

static void ajustValueFrequency() {
  char buffer[50];
  char key;

  switch (ajustFrequency) {

  case MENU:
    serialMenu();
    ajustFrequency = READ_KEYPAD;
    break;

  case READ_KEYPAD:
    selectOptionMenu();
    break;

  case CONFIRM:
    key = matrixKeypadUpdate();
    if (key == '*') {
      int length = snprintf(buffer, sizeof(buffer), "Operación cancelada \n");
      serialComWrite(buffer, length);
      ajustFrequency = EXIT;
    }
    if (key == '#') {
      int length = snprintf(buffer, sizeof(buffer), "Frecuencia cambiada! \n");
      serialComWrite(buffer, length);
      ajustFrequency = EXIT;
    }
    break;

  case EXIT:
    flagMenuFrecuency = false;
    ajustFrequency = MENU;
  }
}

static void selectOptionMenu() {
  char buffer[50];
  static int timesKeyPressed = 0;
  char key;
  int length;

  switch (options_menu) {

  case OPTIONS:
    key = matrixKeypadUpdate();
    switch (key) {
    case '1':
      length = snprintf(buffer, sizeof(buffer), "Ingrese Frecuencia: \n");
      serialComWrite(buffer, length);
      options_menu = CHANGE_FREQUENCY;
      break;
    case '2':
      length = snprintf(buffer, sizeof(buffer), "El estado del sistema es: \n");
      serialComWrite(buffer, length);
      options_menu = STATUS_SYSTEM;
      break;
    case '3':
      options_menu = STOP_SYSTEM;
      break;
    default:
      options_menu = OPTIONS;
      break;
    }
    break;

  case CHANGE_FREQUENCY:
    key = matrixKeypadUpdate();
    if (key != '\0') {
      if (timesKeyPressed < 2) {
        keyPressedList[timesKeyPressed] = key;
        int length = snprintf(buffer, sizeof(buffer), "%c", key);
        serialComWrite(buffer, length);
        timesKeyPressed++;
      }
    }
    if (timesKeyPressed > 1) {
      int length = snprintf(buffer, sizeof(buffer),
                            " Hz \nPara confirmar frecuencia presione # \n");
      serialComWrite(buffer, length);
      length = snprintf(buffer, sizeof(buffer),
                        "Para cancelar frecuencia presione * \n");
      serialComWrite(buffer, length);
      options_menu = OPTIONS;
      ajustFrequency = CONFIRM;
      timesKeyPressed = 0;
    }
    break;

  case STATUS_SYSTEM:
    length = snprintf(buffer, sizeof(buffer), "\nPresión 1: %.2f \n",
                      readPressureM1());
    serialComWrite(buffer, length);
    length = snprintf(buffer, sizeof(buffer), "\nPresión 2: %.2f \n",
                      readPressureM2());
    serialComWrite(buffer, length);
    length = snprintf(buffer, sizeof(buffer), "\nBomba 1: %s \n",
                      StatePump1Read() ? "Encendida" : "Apagada");
    serialComWrite(buffer, length);
    length = snprintf(buffer, sizeof(buffer), "\nBomba 2: %s \n",
                      StatePump2Read() ? "Encendida" : "Apagada");
    serialComWrite(buffer, length);
    options_menu = OPTIONS;
    ajustFrequency = EXIT;
    break;

  case STOP_SYSTEM:
    options_menu = OPTIONS;
    ajustFrequency = EXIT;
    stopEmergencyControlPanel();
    break;
  }
};