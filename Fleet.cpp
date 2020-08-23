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
 // _comm->println("BEGIN [0xf47]");


}//End Fleet::addCommunication


void Fleet::addMap(Grid *grid) {

  _grid = grid;
  grid->blink(5,50);

}//End Fleet::addMap


void Fleet::addKeyBoard(Joystick *joystick) {

  _joystick = joystick;
  _joystick->begin();

}//End Fleet::addMap

void Fleet::println(String message) {

  _comm->println(message);

 
}//End Fleet::println

void Fleet::println(int message) {

  _comm->println(message);

 
}//End Fleet::println


void Fleet::addBoat(Boat *boat) {

  
  boats[_nb_boats] = *boat;
  _nb_boats++;
  println(">>> [Fleet] Boat '"+String(boat->getName()+"' added in fleet"));

}//End Fleet::addBoat


int Fleet::size() {

  return _nb_boats;
}


void Fleet::rotateBoat(Boat *boat) {

   boat->changeOrientation();


}//End rotateBoat

bool Fleet::setLocation(Boat *boat) {

  int etat = 0;
  //################# BEGIN ROTATE ##########################
 do {
        
  etat = _joystick->read();
  println(etat);

  if (etat==joystick::SHORT_PUSH) {
          
    //lcd.clear();
    println("Rotation...");
    println(boat->getOrientation());
    boat->changeOrientation();
    println(boat->getOrientation());
    show(boat);
    delay(ANTI_REBOND);
    //lcd.clear();
          
  }//Fin if appui_court

 } while(etat!=joystick::LONG_PUSH);
 delay(500);
 println("[Fleet] End rotation");
 delay(2000);
 
      //################# END ROTATE ##########################

      //################# BEGIN MOVE ##########################
      do {

        etat = _joystick->read();
        println(_joystick->read());


          if(etat==joystick::LEFT) { //gauche
            moveBoat(boat, boat::LEFT);
            //show(boat);
            delay(DELAI_DEPLACEMENT);
            break;
          }

          if(etat==joystick::RIGHT) { //droite
            moveBoat(boat, boat::RIGHT);
            //show(boat);
            delay(DELAI_DEPLACEMENT);
            break;
          }

          if(etat==joystick::DOWN) { //bas
            moveBoat(boat, boat::DOWN);
            //show(boat);
            delay(DELAI_DEPLACEMENT);
            break;
          }


          if(etat==joystick::UP) { //haut
            moveBoat(boat , boat::UP);
           // show(boat);
            delay(DELAI_DEPLACEMENT);
            break;
          }

          if(etat==joystick::LONG_PUSH) { //appui long

            
            println(">>> [Fleet] Location over");
            delay(1000);
            delay(DELAI_DEPLACEMENT);
            break;
          }




} while (1); //joystick var glob
      //################# END MOVE ##########################


}//End Bota::setLocation



bool Fleet::moveBoat(Boat *boat, int direction) {



      switch(direction) {

        case boat::UP:

          println("Boat move to up");
          boat->up();
          break;

        case boat::DOWN:

          println("Boat move to down");
          boat->down();
          break;

        case boat::RIGHT:

          println("Boat move to right");
          boat->right();
          break;

        case boat::LEFT:

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
  println(">>> [Fleet] Display '"+boat->getName()+"' boat");
  
}//End Fleet::show
