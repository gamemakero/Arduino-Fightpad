# Arduino-Fightpad
Fightpad compatible with PC and PS3

There are two variants, the "gamepad" variant which only works on PC as far as I tested and the "Fightpad PS3" variant that works both on PC and PS3.

Requirements:
              
* An HID arduino compatible board, I used the Pro Micro.

* For PS3 Fightpad you will need the arduino ide 1.6.5.
              
* For PC pad you will need this joystick library: https://github.com/MHeironimus/ArduinoJoystickLibrary
              
Setup:

* PC pad: Having the joystick library installed, upload the sketch to your board using the latest arduino IDE.
  
* PS3 pad: Get Arduino IDE 1.6.5, copy and replace HID.cpp and USBAPI.h on \arduino-1.6.5-r5\hardware\arduino\avr\cores\arduino, 
            then open the IDE select the port and upload the .ino sketch.

Original PS3 files were coded by user miisalo at https://www.arcade-projects.com/forums/index.php?thread/391-neogeo-joystick-to-pc-ps3/
