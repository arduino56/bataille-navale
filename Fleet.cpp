#include "Fleet.h"
#include "Grid.h"
#include "Boat.h"
#include "Joystick.h"
#include "header.h"

Fleet::Fleet(byte size_fleet) {

  boats = (Boat *) malloc(sizeof(Boat)*size_fleet);
}//End Fleet::Fleet


void Fleet::addCommunication(SoftwareSerial *tmp_comm, unsigned long speed) {

  _comm = tmp_comm;
  _comm->begin(speed);


}//End Fleet::addCommunication


void Fleet::addMap(Grid *grid) {

  _grid = grid;
  grid->blink(5,50);

}//End Fleet::addMap


void Fleet::addKeyBoard(Joystick *joystick) {

  _joystick = joystick;

}//End Fleet::addMap

void Fleet::println(String message) {

  _comm->println(message);

 
}//End Fleet::println


void Fleet::addBoat(Boat *boat) {

  
  boats[_nb_boats] = *boat;
  _nb_boats++;
  println("New boat called '"+String(boat->getName()+"'"));

}//End Fleet::addBoat


int Fleet::size() {

  return _nb_boats;
}

bool Fleet::debug() {

  //std::cout << _boats->getName()[0];
  //std::cout << "\nFleet information \n";
  for (int a = 0;a<int(_nb_boats);a++)
  {

    //std::cout << " -> Boat called '" << _boats[a].getName() << "' with a length of "<<  _boats[a].getLength() << "\n";
    boats[a].getData();

  }


  return false;
}//End debug



void Fleet::rotateBoat(Boat *boat) {

   boat->changeOrientation();


}//End rotateBoat

bool Fleet::setLocation(Boat *boat) {

  int etat;
  //################# BEGIN ROTATE ##########################
 do {
        
  etat = _joystick->read();
  println(String(etat));

  if (etat==APPUI_COURT) {
          
    //lcd.clear();
    //lcd.print("Rotation...");
    boat->changeOrientation();
    show(boat);
    delay(ANTI_REBOND);
    //lcd.clear();
          
  }//Fin if appui_court

 } while(etat!=APPUI_LONG);
 
      //################# END ROTATE ##########################

      //################# BEGIN MOVE ##########################
      do {

        etat = _joystick->read();
        
        switch(etat) {

          case GAUCHE: //gauche
            moveBoat(boat, LEFT);
            delay(DELAI_DEPLACEMENT);
            break;

          case DROITE:
            moveBoat(boat, RIGHT);
            delay(DELAI_DEPLACEMENT);
            break;

            
          //########""
          //A corriger :) 
          //########""

          case BAS: // bas

            moveBoat(boat, DOWN);
            delay(DELAI_DEPLACEMENT);
            break;


          case HAUT: //haut

            moveBoat(boat , HIGH);
            delay(DELAI_DEPLACEMENT);
            break;

          case APPUI_LONG:

            //lcd.clear();
            //lcd.print("bateau suivant");
            delay(1000);
            //lcd.clear(etat);
            delay(DELAI_DEPLACEMENT);
      
      break;

  }//Fin switch



} while (etat!=APPUI_LONG); //joystick var glob
      //################# END MOVE ##########################


}//End Bota::setLocation



bool Fleet::moveBoat(Boat *boat, int direction) {



      switch(direction) {

        case 0:

          println("Boat move to up");
          boat->up();
          break;

        case 1:

          println("Boat move to down");
          boat->down();
          break;

        case 2:

          println("Boat move to right");
          boat->right();
          break;

        case 3:

          println("Boat move to left");
          boat->left();
          break;

        default:

          //std::cout << "The input direction is forbidden \n";
          break;


      }//End switch


}//End moveBoat


bool Fleet::fire(int x, int y) {
  //std::cout << "Foud boat at (" << x << "<" << y << "\n";
  int nb_target = 0;
  for (int i = 0; i < _nb_boats; i++)
  {
    
    if(boats[i].isHere(x,y)) {
      //std::cout << "Foud boat at (" << x << "," << y << ")\n";
      nb_target++;
    }
  }
  if (nb_target==0) {
    //std::cout << "Any boat at (" << x << "," << y << ")\n";
  }
}//Fleet.fire()


void Fleet::show(Boat *boat) {

  _grid->show(boat);
  
}//End Fleet::show