#ifndef AIplayer_h
#define AIplayer_h

#include "macros.h"

//pathfinding algorithm
int findPath(int[][M][W], Path*, int, int, int[][M], int[][M]);

//solve maze (recursive backtracker)
void solveMaze(int[][M][W], int[][M], int[][M], Path*);

//AI movement
void AImove(int[][M], int[][M], Pawn*);

#endif
