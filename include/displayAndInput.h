#ifndef displayAndInput_h
#define displayAndInput_h

#include "macros.h" //dimensions

//converts char to string
void chtostr(char, char*);

//display pawn function
void displayPawn(Pawn*, char);

//display pawns for battle mode
void displayPawns(Pawn*, Pawn*);

//maze drawing function
void displayMaze(int maze[][M][W]);

#endif
