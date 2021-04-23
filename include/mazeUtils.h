#ifndef mazeUtils_h
#define mazeUtils_h

#include "macros.h"

//function that checks if cell has any unvisited neighbours
int hasUnivistedNeighbours(int[][M], int, int);

//function that checks if move to cell with given cooridnates is valid and if cell that will be moved to has already been visited
int jumpToUnivisited(int[][M], int, int);

#endif
