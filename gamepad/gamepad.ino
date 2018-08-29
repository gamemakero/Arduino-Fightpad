
#include <Joystick.h>
//constantes de los pines
#define pinDOWN 10
#define pinLEFT 16
#define pinUP 14
#define pinRIGHT 15

#define pin1 2
#define pin2 3
#define pin3 4
#define pin4 5
#define pin5 6
#define pin6 7
#define pin7 8
#define pin8 9



void setup() {


  //Prepara los pines de los botones
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  pinMode(pin3, INPUT_PULLUP);
  pinMode(pin4, INPUT_PULLUP);
  pinMode(pin5, INPUT_PULLUP);
  pinMode(pin6, INPUT_PULLUP);
  pinMode(pin7, INPUT_PULLUP);
  pinMode(pin8, INPUT_PULLUP);
  pinMode(pinUP, INPUT_PULLUP);
  pinMode(pinDOWN, INPUT_PULLUP);
  pinMode(pinRIGHT, INPUT_PULLUP);
  pinMode(pinLEFT, INPUT_PULLUP);

  Joystick.begin(false); //Inicializa el joystick sin actualizar el estado automaticamente


}

void loop() {
  //Comprueba los botones 
  int i;
  int dpad[4];
  for (i=2;i<10;i++){//siendo i el pin
    Joystick.setButton(i-2, !digitalRead(i)); //
  }
  //estado del dpad
  dpad[0]=!digitalRead(pinDOWN);
  dpad[1]=!digitalRead(pinLEFT);
  dpad[2]=!digitalRead(pinRIGHT);
  dpad[3]=!digitalRead(pinUP);
  //se calcula el grado medio de las direcciones pulsadas ej arriba+derecha = 0+90/2=45
  int a = -1;
  a=a+(dpad[0] * 180) + (dpad[1]*270)+(dpad[2]*90)+(dpad[3]*360);
  if(a!=-1){
     if(a==449 && dpad[2]){//arreglo para evitar que arribaDerecha = abajoIZQ
        a=45;
     }else{
        a = (a+1) / (dpad[0]+dpad[1]+dpad[2]+dpad[3]); 
     }
  }
  Joystick.setHatSwitch(0,a);
 
  Joystick.sendState(); //actualiza el estado del gamepad



}
