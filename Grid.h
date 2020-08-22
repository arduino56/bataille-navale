
#include "LedControl.h"
#include "Boat.h"

#ifndef GRID
#define GRID

class Grid : public LedControl {

    public:
    
    Grid(const byte width,const byte height,const byte din_pin,const byte clk_pin,const byte cs_pin, const byte address, const byte nb_boats); //Constructeur
    void blink(int count, int period); 
    
    void show(Boat * boat);
    private:   //variables privées non accessible de manière directe

    byte _width = 0;
    byte _height = 0;

    byte _address = 0;


    


};//End class Grid

#endif