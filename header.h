//Branchement des matrices [à mettre en série...]

#define DIN 10     //Broche DIN
#define CS 11      //Broche CS
#define CLK 12    //Broche CLK
#define MAX7219 1 //Nombre de led

#define ADDRESS 0
#define MATRICE_DEFENSE 0x00 //Matrice de l'attaque [index 1]
#define MATRICE_ATTAQUE 0x00 //Matrice de l'attaque [index 0]
#define PORT_SERIE_DEFENSE 0x02
#define PORT_SERIE_ATTAQUE 0x03

#define WIDTH 8    //Dimensions de la matrice
#define HEIGHT 8

#define INTENSITE_LUMIERE_ATTAQUE 1 //Intensité lumineuse de la matrice de l'attaque [de 1 à 9]
#define INTENSITE_LUMIERE_DEFENSE 1 //Intensité lumineuse de la matrice de l'attaque [de 1 à 9]

//Bluetooth
#define RX 0
#define TX 1


//display
#define BOATS 0x00
#define TARGETS 0x01



#define START "START"
#define STOP "END"


//Ordres à l'adversaire
#define ATTAQUE "A"
#define TOUCHE "T"
#define COULE "C"
#define MANQUE "E"
#define TIRE "F"
#define PERDU "P"
//Branchement du potentiomètre

#define AXE_X A0
#define AXE_Y A1
#define BUTTON 2    //Broche numérique du bouton

#define DELAI_APPUI_COURT 100  //temps de pression pour effectuer un appui court
#define DELAI_APPUI_LONG 1000   //...
#define ANTI_REBOND 500     //Anti-rebond du bouton
#define DELAI_DEPLACEMENT 50  //Délai entre chaque déplcement d'un point ou d'un bouton

//Écran LCD

#define LIGNES 2    //Dimensions LCD
#define COLONNES 16
#define MESSAGE "Placer le bateau avec le joystick"


#define ROUGE 0
#define VERT 100
#define BLEU 255


//Protocole de communication

//Vitesse de Communication [bauds, bits/seconde]
#define VITESSE_UART 9600

//Ne pas modifier, dépend de la bibliothèque...


#define APPUI_COURT 5
#define APPUI_LONG 6


#define HAUT 0     //Valeur de retour pour joystick vers le haut
#define BAS 1    //Valeur de retour pour joystick vers le bas
#define DROITE 2     //Valeur de retour pour joystick vers la droite
#define GAUCHE 3     //Valeur de retour pour joystick vers la gauche
#define CENTRE 4   //Valeur de retour pour le bouton enfoncé
