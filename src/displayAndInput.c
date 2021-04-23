#include "displayAndInput.h"

void chtostr(char ch, char* str){
  str[0] = ch;
  str[1] = '\0';
}

void displayPawn(Pawn *P, char pawnChar){

  char pawnSign[2];
  chtostr(pawnChar, pawnSign);

  //converting coordinates for proper display
  int disRow = 2 * P->row + 1, disCol = 2 * P->column + 1;

  mvprintw(disRow, disCol, pawnSign);
}

void displayPawns(Pawn *P1, Pawn *P2){
  if (P1->row == P2->row && P1->column == P2->column){
    char pawnsChar = '3';
    displayPawn(P1, pawnsChar);
  }
  else{
    displayPawn(P1, P1->pawnChar);
    displayPawn(P2, P2->pawnChar);
  }
}

void displayMaze(int maze[][M][W]){

  char rowSign[2], colSign[2];
  chtostr('-', rowSign);
  chtostr('|', colSign);

      /* printing walls
        function is designed to check the values in maze tab and print
        corresponding walls

        coordinates conversion ---> (0, 0) in maze array = (1, 1) on board
        (1, 1) in maze array = (3, 1) on board
        (0, 1) = (1, 3)
      */

      for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

          //converting coordinates for proper display
          int disRow = 2 * i + 1, disCol = 2 * j + 1;

          //parts of the maze that arent dependent on maze
          mvprintw(disRow - 1, disCol - 1, rowSign);
          mvprintw(disRow - 1, disCol + 1, rowSign);
          mvprintw(disRow + 1, disCol - 1, rowSign);
          mvprintw(disRow + 1, disCol + 1, rowSign);

          //random cell
          for(int k = 0; k < W; k++){
            if(k == 0 && maze[i][j][0]) //down
              mvprintw(disRow + 1, disCol, rowSign);
            else if (k == 1 && maze[i][j][1]) //left
              mvprintw(disRow, disCol - 1, colSign);
            else if (k == 2 && maze[i][j][2]) //up
              mvprintw(disRow - 1, disCol, rowSign);
            else if (k == 3 && maze[i][j][3]) //right
              mvprintw(disRow, disCol + 1, colSign);
            }
          }
        }

  return;
}
