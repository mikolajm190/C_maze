#ifndef AIplayer_h
#define AIplayer_h

#include "macros.h"

//calculate manhattan distance
int manhattanDistance(int, int, int, int);;

//pathfinding algorithm
int findPath(int[][M][W], Path*, int, int, int[][M], int[][M]);

//solve maze (recursive + heuristcs)
void solveMaze(int[][M][W], Path*, int[][M]);

//AI movement
void AImove(int[][M], Pawn*);

#endif
