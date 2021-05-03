#ifndef macros_h
#define macros_h

#include <stdlib.h> //abs, exit, srand, rand
#include <ncurses.h> //visuals

//dimensions N-rows, M-columns
#define N 10
#define M 20

//walls
#define W 4
enum {down, left, up, right} Wall;

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
