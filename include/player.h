#ifndef player_h
#define player_h

#include "macros.h"

//player movement
int PMove(int[][M][W], Pawn*);

//game ending function
int isWinner(Path*, Pawn*);

#endif
