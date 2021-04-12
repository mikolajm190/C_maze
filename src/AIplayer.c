#include "AIplayer.h"

void manhattanDistance(int manDistToEnd[][M], int currRow, int currCol, int destRow, int destCol){
  manDistToEnd[currRow][currCol] = abs(currRow - destRow) + abs(currCol - destCol);
}

void distanceFromEntrance(int distanceFromEnt[][M], int currRow, int currCol){
  //
}

void assignNeighbours(int maze[][M][W], int currRow, int currCol, int manDistToEnd[][M], int distanceFromEnt[][M]){
  //assign value for each neighbour that isnt separated by wall and is inside maze
  for(int i = 0; i < W; i++){
    //down neighbour
    if(currRow + 1 < N && maze[currRow][currCol][0] == 0){}
      //
  }
}

void AImove(int maze[][M][W], Path *startEnd){

  int manDistToEnd[N][M] = {{0}};
  int distanceFromEnt[N][M] = {{0}};

  //begin from entrance
  int currRow = startEnd->rowStart; int currCol = 0;

  //search until exit is found
  while (currRow != startEnd->rowEnd && currCol != startEnd->colEnd) {
    //assign values

    //choose neighbour and move
  }
}
