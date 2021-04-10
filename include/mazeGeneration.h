#ifndef mazeGeneration_h
#define mazeGeneration_h

#include "macros.h" //dimensions

#include<stdlib.h> //srand, rand

//jump to next cell function
int jump(int[][M][W], int, int);

//dfs
void dfs(int[][M][W], int, int);

//maze generator
void buildMaze(int[][M][W]);

//winner check
int isWinner(int[][M][W]);

#endif
