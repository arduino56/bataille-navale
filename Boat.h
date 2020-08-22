/*
Projet Bataille Navale
Antoine SCAVINER - Nicolas LE GUERROUE
Fichier de déclaration de la bibliothèque Boat
*/
#ifndef BOAT
#define BOAT

//Inclusions des bibliothèques
#include <Arduino.h>

//Constantes
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

//Classe Boat
class Boat
{
public:

  /*########################################################
  #  Constructors
  ##########################################################*/
  Boat();
  Boat(String name, byte length);

  /*########################################################
  #  functions (public)
  ##########################################################*/

  //Attributes
  String getName();                   //Get name of boat
  uint8_t getLength();                  //Get length of boat

  //actions 
  void changeOrientation();                 //Change orientation of boat

  void up();                          //move boat (up)
  void down();                        //move boat (down)
  void right();                         //move boat (right)
  void left();                        //move boat (left)

  bool isHere(uint8_t x, uint8_t y);            //Check if boat is here
  int **getData();                       //All points of boat
  int **getDataSink();                   //points don't show
  void sink();                        //free pointer
  

private:

  /*########################################################
  #  functions (private)
  ##########################################################*/
  void computeData(); //Compute new place of boat

  /*########################################################
  #  attributes (private)
  ##########################################################*/
  String _name ="default_boat";               //Name of boat
  uint8_t _direction = 0;                   //Direction -> 0=right, 1=up          
  uint8_t _length = 0;                      //Length of boat ->width=1
  
  int *_x_points = nullptr;                 //List of x points of boat
  int *_y_points = nullptr;                 //List of y points of boat

  uint8_t *_x_points_removed = nullptr;                 //List of x points of boat to blink
  uint8_t *_y_points_removed = nullptr;                 //List of y points of boat to blink

  uint8_t _x = 0;                       //Current x
  uint8_t _y = 0;                       //Current y

  uint8_t _max_size_grid = 8;

};
#endif
