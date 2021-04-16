#ifndef macros_h
#define macros_h

#include <stdlib.h> //abs, exit, srand, rand
#include <ncurses.h> //api

//dimensions
#define N 10
#define M 20
//walls and visit digit
#define W 4

//struct representing a player pawn
typedef struct pawn {
  int row, column;
  char pawnChar;
} Pawn;

//struct for start and end cells coordinates
typedef struct path {
  int rowStart, colStart, rowEnd, colEnd;
} Path;

#endif
