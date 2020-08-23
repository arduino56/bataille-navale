#ifndef FLEET
#define FLEET 

#define MAX_BOATS 4 //Define max number boats

#include <SoftwareSerial.h>

#include "Boat.h"
#include "Grid.h"
#include "Joystick.h"

class Fleet

{

public:

  Fleet(byte size_fleet);
  int size();
  
  void addCommunication(SoftwareSerial *tmp_comm, unsigned long speed);
  void addBoat(Boat *boat);
  void addMap(Grid *grid); 
  void addKeyBoard(Joystick *joystick);
  
  void println(String message);
  void println(int message);
  
  void rotateBoat(Boat *boat);
  bool setLocation(Boat *boat);
  bool moveBoat(Boat *boat, int direction);
  bool removeBoat();

  void show(byte target); //display points or boats
  void show(Boat *boat);
  bool fire(int x, int y);

private:

  SoftwareSerial *_comm;
  Grid *_grid;
  Joystick *_joystick;

  byte _nb_boats = 0; //Default : 0 boat is available
  Boat *boats;// = nullptr;


  
};
#endif
