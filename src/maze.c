/*
author: Mikolaj Mochocki
UKSW, PPI
topic: maze
*/

//test
#include <stdio.h>

/* maze generation functions */
#include "mazeGeneration.h"

/* AI related functions */
#include "AIplayer.h"

/* player related functions */
#include "player.h"

/* display and input functions */
#include "displayAndInput.h"

//change the seed if you want to generate different maze
#define SEED 100

int main(int argc, char** argv){

  //initialization of random numbers generator
  srand(SEED);

  // Initialize ncurses, no line buffering and no echo for getch
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	timeout(0);

  int maze[N][M][W] = {{{0, 0, 0, 0, 0}}};
  /*
       ___
      |__|    index - direction:  0 - down, 1 - left, 2 - up, 3 - right

      every cell stores values that represent wall or its lack
      0 - no wall, 1 - wall
  */
  Pawn P1; P1.row = 0; P1.column = 0; P1.pawnChar = '1';
  Pawn P2; P2.row = 0; P2.column = 0; P2.pawnChar = '2';

  buildMaze(maze);

  //initialization of a pawn based on values returned by buildMaze() (entranceRow and exitRow)

  displayMaze(maze);
  displayPawn(P2);
  refresh();

  getchar();
  endwin();

  /* test
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      for(int k = 0; k < W; k++){
        printf("%d", maze[i][j][k]);
      }
      printf("\t");
    }
    printf("\n");
  }
  */

  return 0;
}
