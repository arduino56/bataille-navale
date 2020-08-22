#ifndef JOYSTICK_H
#define JOYSTICK_H

#define LOCKED_JOYSTICK 0xff  		//Attente de l'appui d'un bouton si constante appelée

#define J_UP 0x0 		//Valeur de retour pour joystick vers le haut
#define J_DOWN 0x1 		//Valeur de retour pour joystick vers le bas
#define J_RIGHT 0x2 		//Valeur de retour pour joystick vers la droite
#define J_LEFT 0x3 		//Valeur de retour pour joystick vers la gauche
#define J_CENTER 0x4 	//Valeur de retour pour le bouton enfoncé
#define J_SHORT_PUSH 0x5
#define J_LONG_PUSH 0x6
#define J_VOID 0x7

#define J_OFFSET 50 		//décalage de la valeur moyenne au repos
#define J_MAX 900 		//Valeur max pour une butée
#define J_MIN 150 		//Valeur min pour une butée
#define J_BOUND 10   	//Anti-rebond

#define J_SHORT_DELAY 200 	//Délai court
#define J_LONG_DELAY 2000		//délai long



class Joystick
{
public:


	Joystick( int axe_x, int axe_y, int button, int type); 	//type est INPUT_PULLUP ou rien
	void setShortTime(int short_delay); 						//
	void setLongTime(int long_delay);
	int read(); 											//Lecture instantannée
  void begin();


private:

	int _button=0;
	int _axe_x=0;
	int _axe_y=0;
	int _mode=0;

	int _short_delay = 100;
	int _long_delay = 400;

	
};


#endif