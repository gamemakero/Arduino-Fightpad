// PIN mappings, usings constant ints would be more type safe but lets save some memory
#define PIN_UP        14
#define PIN_LEFT      16
#define PIN_RIGHT     15
#define PIN_DOWN      10

#define PIN_SQUARE    8
#define PIN_X         2

#define PIN_TRIANGLE  4
#define PIN_CIRCLE    9

#define PIN_START     5
#define PIN_SELECT    6

#define PIN_HOME      4
#define PIN_KICK2     A2
#define PIN_KICK3     A3
#define PIN_KICK1     2
// controller state
PS3ControllerState_t controllerState;

/***************************************************************
 * SETUP routine
 * 
 * Initialize pins to input with pullup 
 * Initialize controller state
 ***************************************************************/

void setup() {

  pinMode(PIN_X,       INPUT_PULLUP);


  PS3Controller.initController(); // Initialize controller and get current state
  controllerState  = PS3Controller.getState();
}

/***************************************************************
 * MAP 4 button layout to the controller
 ***************************************************************/
void map4ButtonLayout_1()
{

  controllerState.cross    = !digitalRead(PIN_X);

}

/***************************************************************
 * MAP start and select to the controller
 ***************************************************************/
void mapStartSelect()
{

}

/***************************************************************
 * MAP start and select as home button to the controller
 * this must be called after mapStartSelect
 ***************************************************************/
void mapHome()
{

}

/***************************************************************
 * MAP joystict to dpad
 ***************************************************************/

void mapJoystick()
{

}

/***************************************************************
 * MAIN LOOP - Map and send state
 ***************************************************************/

void loop() {
  map4ButtonLayout_1();
  mapStartSelect();
  mapHome();
  mapJoystick();
  PS3Controller.setState(&controllerState);
  PS3Controller.sendState();
}
