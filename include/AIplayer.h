#ifndef AIplayer_h
#define AIplayer_h

#include "macros.h"

//pathfinding algorithm
void findShortestPath(int[][M][W]);

//
void manhattanDistance(int[][M], int, int, int, int);;

//
void distanceFromEntrance(int[][M], int, int);

//function that assign values to cells neighbours (heuristic based movement)
void assignNeighbours(int[][M][W], int, int, int[][M], int[][M]);

//AI movement
void AImove(int[][M][W], Path*);

#endif
