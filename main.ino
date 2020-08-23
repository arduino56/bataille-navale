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

#define ADDRESS 0
#define WIDTH 8    //Dimensions de la matrice
#define HEIGHT 8

//Instances
Fleet fleet(NB_BOATS);                                          //new fleet
SoftwareSerial bluetooth(RX,TX);                                //simulate Bluetooth
Grid grid(WIDTH, HEIGHT, DIN, CLK, CS, ADDRESS, NB_BOATS);      //new grid
Joystick _joystick (AXE_X, AXE_Y, BUTTON, INPUT_PULLUP);         //type is INPUT_PULLUP or nothing

Boat b1("porte", 5, &bluetooth, VITESSE_UART);
Boat b2("cuirasse", 4, &bluetooth, VITESSE_UART);
Boat b3("marin", 3, &bluetooth, VITESSE_UART);
Boat b4("corvette", 2, &bluetooth, VITESSE_UART);


//Boat *boats [NB_BOATS] = {new Boat("a", 5, 13), new Boat("b", 4, 13), new Boat("x", 3, 13), new Boat("az", 2, 13)}; //Erreur avec nom

void setup() {

  _joystick.begin();
  _joystick.setShortTime(50);
  _joystick.setLongTime(1000);

  //Fleet
  fleet.addCommunication(&bluetooth, VITESSE_UART);
  fleet.addMap(&grid);
  fleet.addKeyBoard(&_joystick);

  fleet.addBoat(&b1);
  fleet.show(&b1);
  fleet.setLocation(&b1);
  delay(3000);
  fleet.show(&b2);
  fleet.setLocation(&b2);
delay(3000);

}

void loop() {



}//Fin loop
