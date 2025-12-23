/*
	space invaders clone written with SDL1.2 in C
	* nov 28 2025
	* Marlow Rekers
	* Dec -  2025
	* Moon
*/

#include "game.h"

/***
DONT USE THE FRENCH VERSION OF COLOR XD
***/



int main()  {

  character_t *mainGuy;  //first element in a linked list.
  
  mainGuy = malloc(sizeof(character_t));
  
  characterInit(mainGuy, 10, 208,  32,  32, 4, 4, "image/jointship.bmp");
  characterAdd (mainGuy,  0,   0, 320, 240, 0, 0, "image/bg.bmp");
  characterAdd (mainGuy, 50,  10,  32,  32, 0, 0, "boop");   
  characterAdd (mainGuy,  0, 320,   4,   8, 0, 0, "bap");
  characterAdd (mainGuy,  0,   0,   4,   8, 0, 0, "bip");
  
  dumpList(mainGuy);
  
  SDL_Quit();
    
	return 0;
 }
 
