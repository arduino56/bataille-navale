
#include "Grid.h"
#include "LedControl.h"
#include "Boat.h"

Grid::Grid(const byte width,const byte height,const byte din_pin,const byte clk_pin,const byte cs_pin, const byte address, const byte nb_boats) : LedControl(din_pin,clk_pin,cs_pin,1) {
//Mise à jour des variables privées

_width = width;
_height = height;

_address = address;

shutdown(_address,false);//false=POWER ON
setIntensity(_address,1);
clearDisplay(_address);

}//End Grid::Grid

void Grid::blink(int count, int period) {

  for(int i=0;i<count;i++)  {
    
      for(int width=0;width<_width;width++){//row 

          for(int height=0;height<_height;height++){//col 
            
            setLed(_address, width, height, true);

          }//End for height
    }//End for

    delay(period);

      for(int width=0;width<_width;width++){//row 

          for(int height=0;height<_height;height++){//col 
            
            setLed(_address, width, height, false);

          }//End for height
    }//End for

    delay(period);

  }//End for
  
}

void Grid::show(Boat *boat){ //display one boat only

  clearDisplay(0);
  int ** points = boat->getData();
    
  for(uint8_t index = 0;index<boat->getLength();index++) {

    setLed(_address, points[index][0], points[index][1], 1);
    
  }//End for points
 
}//End Grid::show