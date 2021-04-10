#ifndef displayAndInput_h
#define displayAndInput_h

#include "macros.h" //dimensions

#include <ncurses.h> //api for the aplication
#include <stdlib.h>

//converts char to string
void chtostr(char, char*);

//display pawn function
void displayPawn(Pawn P);

//maze drawing function
void displayMaze(int maze[][M][W]);

#endif
