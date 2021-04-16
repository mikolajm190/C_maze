#include "player.h"

//check if a move is viable and move if true
void PMove(int maze[][M][W], Pawn *P){
  //get user input
  int key = -1;
	key = getch();
	switch (key) {
	case 'q': //quit
		endwin();
    exit(0);
		break;
  case KEY_DOWN: //go down
    //check if a move is possible (wall, end of maze)
    if (P->row + 1 < N && maze[P->row][P->column][0] == 0) {
      P->row += 1;
    }
  	break;
  case KEY_LEFT: //go left
    //check if a move is possible (wall, end of maze)
    if (P->column - 1 >= 0 && maze[P->row][P->column][1] == 0) {
      P->column -= 1;
    }
  	break;
	case KEY_UP: //go up
    //check if a move is possible (wall, end of maze)
    if (P->row - 1 >= 0 && maze[P->row][P->column][2] == 0) {
      P->row -= 1;
    }
		break;
	case KEY_RIGHT: //go right
    //check if a move is possible (wall, end of maze)
    if (P->column + 1 < M && maze[P->row][P->column][3] == 0) {
      P->column += 1;
    }
		break;
	}
  clear();
  return;
}

//check if player has reached an exit (if yes return 1, return 0 otherwise)
int isWinner(Path *End, Pawn *P){
  //compare coordinates
  if (End->rowEnd == P->row && End->colEnd == P->column) {
    return 1;
  } else {
    return 0;
  }
}
