#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "Arduino.h" //Allow String using

namespace joystick {

const uint8_t UP  = 0;     //Valeur de retour pour joystick vers le haut
const uint8_t DOWN = 1;     //Valeur de retour pour joystick vers le bas
const uint8_t RIGHT = 2;     //Valeur de retour pour joystick vers la droite
const uint8_t LEFT = 3;     //Valeur de retour pour joystick vers la gauche
const uint8_t CENTER = 4;   //Valeur de retour pour le bouton enfoncé
const uint8_t SHORT_PUSH = 5;
const uint8_t LONG_PUSH = 6;
const uint8_t VOID = 7;

const uint8_t OFFSET = 50;     //décalage de la valeur moyenne au repos
const uint16_t MAX  = 900;     //Valeur max pour une butée
const uint16_t MIN  = 150;     //Valeur min pour une butée
const uint8_t BOUND = 10;    //Anti-rebond

const uint16_t SHORT_DELAY = 800;   //Délai court
const uint16_t LONG_DELAY  = 2000;   //délai long


}//End namespace



class Joystick
{
public:


  Joystick( int axe_x, int axe_y, int button, int type);  //type est INPUT_PULLUP ou rien
  void setShortTime(int short_delay);             //
  void setLongTime(int long_delay);
  uint16_t read();                      //Lecture instantannée
  void begin();


private:

  int _button=0;
  int _axe_x=0;
  int _axe_y=0;
  int _mode=0;

  int _short_delay = joystick::SHORT_DELAY;
  int _long_delay = joystick::LONG_DELAY;

  
};


#endif
