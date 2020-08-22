//Bibliothèques officielles
#include <SoftwareSerial.h>

//Bibliothèques personnels
#include "Fleet.h"
#include "Boat.h"
#include "Joystick.h"
#include "rgb_lcd.h"
#include "LedControl.h"

//Variables
#include "header.h"

#define NB_BOATS 4
//Instances
Fleet fleet(NB_BOATS); //new fleet
SoftwareSerial bluetooth(RX,TX); //simulate Bluetooth
Grid grid(WIDTH, HEIGHT, DIN, CLK, CS, ADDRESS, NB_BOATS);
Joystick joystick (AXE_X, AXE_Y, BUTTON, INPUT_PULLUP);   //type est INPUT_PULLUP ou rien

Boat *boats [NB_BOATS] = {new Boat("Porte-avions", 5), new Boat("Cuirasse", 4), new Boat("Sous-marins", 3), new Boat("Corvette", 2)};

void setup() {

  //Boats
  
  fleet.addCommunication(&bluetooth, VITESSE_UART);
  fleet.addMap(&grid);
  fleet.addKeyBoard(&joystick);

  fleet.addBoat(boats[0]);
  fleet.addBoat(boats[1]);
  fleet.addBoat(boats[2]);
  fleet.addBoat(boats[3]);


  for(int b=0;b<4;b++) {
    fleet.show(boats[b]);
    //fleet.setLocation(boats[b]);
    delay(500);
  }


  


}

void loop() {


}//Fin loop
