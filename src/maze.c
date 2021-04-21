/*
author: Mikolaj Mochocki
UKSW, PPI
topic: maze
*/

/* argument validation */
#include <string.h> //strcmp

/* delay */
#include <unistd.h> //usleep

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

  //passed arguments check
  if (argc != 2){
    printf("Wrong number of arguments passed. 1 is needed.\n");
    exit(EXIT_FAILURE);
  }
  else if (strcmp(argv[1], "player") != 0 && strcmp(argv[1], "ai") != 0 && strcmp(argv[1], "battle") != 0){
    printf("Wrong argument given. Should be player/ai/battle.\n");
    exit(EXIT_FAILURE);
  }

  //initialization of random numbers generator
  srand(SEED);

  // Initialize ncurses, no line buffering and no echo for getch
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
	timeout(0);

  int maze[N][M][W] = {{{0, 0, 0, 0}}};
  /*
       ___
      |__|    index - direction:  0 - down, 1 - left, 2 - up, 3 - right

      every cell stores values that represent wall or its lack
      0 - no wall, 1 - wall
  */

  //build maze
  Path startEnd;
  buildMaze(maze, &startEnd);

  //player mode
  if (strcmp(argv[1], "player") == 0) {
    Pawn P1; P1.row = startEnd.rowStart; P1.column = startEnd.colStart; P1.pawnChar = '1';

    //initialization of a pawn based on values returned by buildMaze() (entranceRow and exitRow)
    displayMaze(maze);
    displayPawn(&P1, P1.pawnChar);
    refresh();

    while (!isWinner(&startEnd, &P1)) {
      usleep((unsigned int) (50000));
      PMove(maze, &P1);
      displayMaze(maze);
      displayPawn(&P1, P1.pawnChar);
      refresh();
    }

    endwin();
  }
  //ai player mode
  else if (strcmp(argv[1], "ai") == 0) {
    Pawn P2; P2.row = startEnd.rowStart; P2.column = startEnd.colStart; P2.pawnChar = '2';

    displayMaze(maze);
    displayPawn(&P2, P2.pawnChar);
    refresh();

    //find path
    int correctPath[N][M];
    solveMaze(maze, &startEnd, correctPath);

    while (!isWinner(&startEnd, &P2)) {
      usleep(1000000);
      AImove(correctPath, &P2);
      displayMaze(maze);
      displayPawn(&P2, P2.pawnChar);
      refresh();
    }
    endwin();
  }
  //battle mode
  else {
    Pawn P1; P1.row = startEnd.rowStart; P1.column = startEnd.colStart; P1.pawnChar = '1';
    Pawn P2; P2.row = startEnd.rowStart; P2.column = startEnd.colStart; P2.pawnChar = '2';

    displayMaze(maze);
    displayPawns(&P1, &P2);
    refresh();

    //find path
    int correctPath[N][M];
    solveMaze(maze, &startEnd, correctPath);

    while (!isWinner(&startEnd, &P1) || !isWinner(&startEnd, &P2)) {
      //if player doesnt move in 2 seconds move ai
      PMove(maze, &P1);
      AImove(correctPath, &P2);
      displayMaze(maze);
      displayPawns(&P1, &P2);
      refresh();
    }
    endwin();
  }

  return EXIT_SUCCESS;
}
