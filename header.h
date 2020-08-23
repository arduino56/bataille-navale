//Branchement des matrices [à mettre en série...]

#define DIN 10     //Broche DIN
#define CS 11      //Broche CS
#define CLK 12    //Broche CLK
#define MAX7219 1 //Nombre de led



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
#define ANTI_REBOND 200     //Anti-rebond du bouton
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
#define VITESSE_UART 115200
