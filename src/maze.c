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
#define SEED 1001

//driver functions for each play mode
void playerMode(int [][M][W], Path*);
void aiMode(int [][M][W], Path*);
void battleMode(int [][M][W], Path*);

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
    playerMode(maze, &startEnd);
  }
  //ai player mode
  else if (strcmp(argv[1], "ai") == 0) {
    aiMode(maze, &startEnd);
  }
  //battle mode
  else {
    battleMode(maze, &startEnd);
  }

  return EXIT_SUCCESS;
}


void playerMode(int maze[][M][W], Path* startEnd){
  //initialization of a pawn based on values returned by buildMaze() (entranceRow and exitRow)
  Pawn P1; P1.row = startEnd->rowStart; P1.column = startEnd->colStart; P1.pawnChar = '1';

  //first display
  displayMaze(maze);
  displayPawn(&P1, P1.pawnChar);
  refresh();

  //let player move until he wins
  while (!isWinner(startEnd, &P1)) {
    usleep((unsigned int) (50000));
    PMove(maze, &P1);

    //display changes
    displayMaze(maze);
    displayPawn(&P1, P1.pawnChar);
    refresh();
  }
  endwin();
  printf("Well done, you have won.\n");
}

void aiMode(int maze[][M][W], Path* startEnd){
  Pawn P2; P2.row = startEnd->rowStart; P2.column = startEnd->colStart; P2.pawnChar = '2';

  //first display
  displayMaze(maze);
  displayPawn(&P2, P2.pawnChar);
  refresh();

  //find path and store it in array
  int correctPath[N][M] = {{0}}, visited[N][M] = {{0}};
  solveMaze(maze,correctPath, visited, startEnd);

  //for user to enable exit during ai playthrough
  int key = -1;

  //let ai move until it reaches exit
  while (!isWinner(startEnd, &P2)) {
    usleep(300000);
    AImove(maze, correctPath, visited, &P2);

    //display changes
    displayMaze(maze);
    displayPawn(&P2, P2.pawnChar);
    refresh();

    //if player wish to exit
    key = getch();
    if (key == 'q'){
      endwin();
      printf("Program ended by user.\n");
      exit(EXIT_SUCCESS);
    }
  }
  endwin();
  printf("AI has won the game.\n");
}

void battleMode(int maze[][M][W], Path* startEnd){
  Pawn P1; P1.row = startEnd->rowStart; P1.column = startEnd->colStart; P1.pawnChar = '1';
  Pawn P2; P2.row = startEnd->rowStart; P2.column = startEnd->colStart; P2.pawnChar = '2';

  //first display
  displayMaze(maze);
  displayPawns(&P1, &P2);
  refresh();

  //find path
  int correctPath[N][M] = {{0}}, visited[N][M] = {{0}};
  solveMaze(maze, correctPath, visited, startEnd);

  //let player and ai move until one of them reaches exit
  while (!isWinner(startEnd, &P1) && !isWinner(startEnd, &P2)) {
    usleep(250000);
    if (PMove(maze, &P1) == -1)
      AImove(maze, correctPath, visited, &P2);

    //display changes
    displayMaze(maze);
    displayPawns(&P1, &P2);
    refresh();
  }
  endwin();
}
