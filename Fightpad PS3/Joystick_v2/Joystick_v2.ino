// PIN mappings, usings constant ints would be more type safe but lets save some memory
#define PIN_UP        14
#define PIN_LEFT      16
#define PIN_RIGHT     15
#define PIN_DOWN      10

#define PIN_SQUARE    8
#define PIN_X         2
#define PIN_TRIANGLE  9
#define PIN_CIRCLE    7

#define PIN_R1 4

#define PIN_START     6
#define PIN_SELECT    5

#define PIN_HOME      3

// controller state
PS3ControllerState_t controllerState;

/***************************************************************
 * SETUP routine
 * 
 * Initialize pins to input with pullup 
 * Initialize controller state
 ***************************************************************/

void setup() {
  pinMode(PIN_UP,      INPUT_PULLUP);
  pinMode(PIN_DOWN,    INPUT_PULLUP);
  pinMode(PIN_LEFT,    INPUT_PULLUP);
  pinMode(PIN_RIGHT,   INPUT_PULLUP);

  pinMode(PIN_SQUARE,  INPUT_PULLUP);
  pinMode(PIN_CIRCLE,  INPUT_PULLUP);
  pinMode(PIN_X,       INPUT_PULLUP);
  pinMode(PIN_TRIANGLE,INPUT_PULLUP);

  pinMode(PIN_HOME,   INPUT_PULLUP);
  pinMode(PIN_R1,      INPUT_PULLUP);
  pinMode(PIN_SELECT,  INPUT_PULLUP);
  pinMode(PIN_START,   INPUT_PULLUP);


  PS3Controller.initController(); // Initialize controller and get current state
  controllerState  = PS3Controller.getState();
}

/***************************************************************
 * MAP 4 button layout to the controller
 ***************************************************************/
void map4ButtonLayout_1()
{
  controllerState.square   = !digitalRead(PIN_SQUARE);
  controllerState.cross    = !digitalRead(PIN_X);
  controllerState.circle   = !digitalRead(PIN_CIRCLE);
  controllerState.triangle = !digitalRead(PIN_TRIANGLE);

  controllerState.r1 = !digitalRead(PIN_R1);
}

/***************************************************************
 * MAP start and select to the controller
 ***************************************************************/
void mapStartSelect()
{
  controllerState.start  = !digitalRead(PIN_START);
  controllerState.select = !digitalRead(PIN_SELECT);
}

/***************************************************************
 * MAP start and select as home button to the controller
 * this must be called after mapStartSelect
 ***************************************************************/
void mapHome()
{
    controllerState.home    = !digitalRead(PIN_HOME);
  
}

/***************************************************************
 * MAP joystict to dpad
 ***************************************************************/

void mapJoystick()
{
    controllerState.dpad = 8;
    if(!digitalRead(PIN_UP)){
      controllerState.dpad = 0;
      if (!digitalRead(PIN_RIGHT)){
        controllerState.dpad = 1;
      } else if (!digitalRead(PIN_LEFT)){
        controllerState.dpad = 7;
      }
    } else if (!digitalRead(PIN_RIGHT)) {
      controllerState.dpad = 2;
      if (!digitalRead(PIN_DOWN)) {
        controllerState.dpad = 3;
      }
    } else if (!digitalRead(PIN_DOWN)) {
      controllerState.dpad = 4;
      if (!digitalRead(PIN_LEFT))  {
        controllerState.dpad = 5;
      }
    } else if (!digitalRead(PIN_LEFT)) {
      controllerState.dpad = 6;
      if (!digitalRead(PIN_UP)){
        controllerState.dpad = 7;
      }
    }; 
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
  delay(5); //delays the next loop to avoid noise problems in the buttons.
}
