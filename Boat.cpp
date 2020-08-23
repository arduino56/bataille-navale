/*
Projet Bataille Navale
Antoine SCAVINER - Nicolas LE GUERROUE
Fichier de définition de la bibliothèque Boat
*/
#include "Boat.h"
#include <SoftwareSerial.h>

/*########################################################
#  Constructors
##########################################################*/
Boat::Boat() {
  SoftwareSerial a(4,5);
  Boat("default_name", 3, &a, 9600);

}//End Boat::Boat

Boat::Boat(String name, uint8_t length, SoftwareSerial *debug_comm, unsigned long speed)  {

  _direction = 0;
  _name = name;
  _length = length;

  _debug_comm = debug_comm;


  _x_points = (int *) malloc(sizeof(int)*_length);
  _y_points = (int *) malloc(sizeof(int)*_length);

  debug_comm->begin(speed);
  debug_comm->println(">>> [Boat] : '"+name+"' - Length = "+String(_length));
  if(_x_points==nullptr || _y_points==nullptr) {
    _debug_comm->println("Impossible to create boat");
  }

  //Compute points on y of boat with direction to up and length given

  for (uint8_t i = 0; i < _length; ++i){

    _y_points[i] = i;
    _x_points[i] = 0;
    
  }//End for

  computeData();
  getData();

}//End Boat::Boat

/*########################################################
#  functions (private)
##########################################################*/

String Boat::getName() { 

  return _name;

}//End Boat::getName

uint8_t Boat::getLength() {

  return _length;

}//End Boat::getLength


void Boat::changeOrientation() {

  _direction = !(_direction);
  _debug_comm->println(">>> [Boat] Rotation of '"+_name+"'boat ");
  computeData();

}//End Boat::changeOrientation

int Boat::getOrientation() {

 return _direction;

}//End Boat::changeOrientation


void Boat::up() {

  if(_y!=(_max_size_grid-1) ) { //can up
    _y++;
    computeDataMoving();
  }//End if
  else {

  }//End else
}//End Boat::up

void Boat::down() {
  if(_y!=0) {
    _y--;
    computeDataMoving();
  }
  else {

  }//End else

}//End Boat::down

void Boat::right() {

  if(_x!=(_max_size_grid-1)) { //can up
    _x++;
    computeDataMoving();
  }//End if
  else {

  }//End else

}//End Boat::right

void Boat::left() {
  if(_x!=0) {
    _x--;
    computeDataMoving();
  }
  else {

  }//End else

}//End Boat::left


void Boat::computeData() {

  if(_direction==0) {//up
    for (int i = 0; i < _length; ++i) {  _y_points[i]=_y+i; }//End for
  }//End if
  
  if(_direction==1) { //right

    for (int i = 0; i < _length; ++i) {  _x_points[i]=_x+i;
    }//End for
  }//End if

}//End Boat::computeData

void Boat::computeDataMoving() {

  if(_direction==0) {//up
    for (int i = 0; i < _length; ++i) {  _y_points[i]=_y+i; _x_points[i]=0;}//End for
  }//End if
  
  if(_direction==1) { //right

    for (int i = 0; i < _length; ++i) {  _x_points[i]=_x+i; _y_points[i]=0; 
    }//End for
  }//End if

}//End Boat::computeDataMoving

bool Boat::isHere(uint8_t x, uint8_t y) {

  for (uint8_t i = 0; i < _length; ++i) {

    if(_x_points[i]==x && _y_points[i]==y) {
      return true;
    }//End if

  }//End for

  return false;

}//End Boat::isHere

int **Boat::getData() {

    //Create array
   int ** return_array = (int **)malloc(sizeof(int*)*_length );

     if(return_array==nullptr) {
    for(int i=0;i<50;i++) {
      digitalWrite(_debug_pin, 1);
      delay(50);
      digitalWrite(_debug_pin, 0);
      delay(50);
    }
  }
   for (uint8_t index = 0; index<_length; index++ )
   {
      return_array[index] = (int *)malloc(2*sizeof(int) );
      return_array[index][0] = _x_points[index];
      return_array[index][1] = _y_points[index];
   }
   return return_array;


}//End Boat::getData

int **Boat::getDataSink() {
  
    //Create array
   int ** return_array = (int **)malloc(sizeof(int*)*_length );
   for (uint8_t index = 0; index<_length; index++ )
   {
      return_array[index] = (int *)malloc(2*sizeof(int) );
      return_array[index][0] = _x_points_removed[index];
      return_array[index][1] = _y_points_removed[index];
   }
   return return_array;



}//End Boat::getDataSink

void Boat::sink() {

  free(_x_points);
  free(_y_points);

  free(_x_points_removed);
  free(_y_points_removed);
  
}//End Boat::sink
