#include "AIplayer.h"

int manhattanDistance(int currRow, int currCol, int destRow, int destCol){
  return abs(currRow - destRow) + abs(currCol - destCol);
}

int findPath(int maze[][M][W], Path *startEnd, int currRow, int currCol, int visited[][M], int correctPath[][M]){
  //return if end is reached
  if (currRow == startEnd->rowEnd && currCol == startEnd->colEnd){
    //add ending cell to path
    correctPath[currRow][currCol] = 1;
    return 1;
  }

  //return if there are none unvisited neighbours
  if ((currRow + 1 > N - 1 || visited[currRow + 1][currCol] == 1) && (currCol - 1 < 0 || visited[currRow][currCol - 1] == 1) && (currRow - 1 < 0 || visited[currRow - 1][currCol] == 1) && (currCol + 1 > M - 1 || visited[currRow][currCol + 1] == 1)){
    return 0;
  }

  //mark current cell visited
  visited[currRow][currCol] = 1;

  //add cell to correct path
  correctPath[currRow][currCol] = 1;

  //todo: pick cells in order of manhattan distance

  //call reachable neighbours in order of distance
  if (currRow + 1 < N && maze[currRow][currCol][0] == 0){
    if(findPath(maze, startEnd, currRow + 1, currCol, visited, correctPath)){
      return 1;
    }
  }
  if (currCol - 1 >= 0 && maze[currRow][currCol][1] == 0){
    if (findPath(maze, startEnd, currRow, currCol - 1, visited, correctPath)){
      return 1;
    }
  }
  if (currRow - 1 >= 0 && maze[currRow][currCol][2] == 0){
    if (findPath(maze, startEnd, currRow - 1, currCol, visited, correctPath)){
      return 1;
    }
  }
  if (currCol + 1 < M && maze[currRow][currCol][3] == 0){
    if (findPath(maze, startEnd, currRow, currCol + 1, visited, correctPath)){
      return 1;
    }
  }

  //if none of the above worked backtrack, unmark current cell
  correctPath[currRow][currCol] = 0;

  //return if there is no solution
  return 0;
}

void solveMaze(int maze[][M][W], Path *startEnd, int correctPath[][M]){

  //create variables for storing path info
  int visited[N][M];

  //initialize variables
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      correctPath[i][j] = 0; visited[i][j] = 0;
    }
  }

  //find path
  findPath(maze, startEnd, startEnd->rowStart, startEnd->colStart, visited, correctPath);
}

void AImove(int correctPath[][M], Pawn *P){
  //follow the path that you got from solveMaze

  //look for next step and go
  if (P->row + 1 < N && correctPath[P->row + 1][P->column] == 1){
    P->row += 1;
  }
  else if (P->column - 1 >= 0 && correctPath[P->row][P->column - 1] == 1){
    P->column -= 1;
  }
  else if (P->row - 1 >= 0 && correctPath[P->row - 1][P->column] == 1){
    P->row -= 1;
  }
  else{
    P->column += 1;
  }
}
