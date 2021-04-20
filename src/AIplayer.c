#include "AIplayer.h"

int manhattanDistance(int currRow, int currCol, int destRow, int destCol){
  return abs(currRow - destRow) + abs(currCol - destCol);
}

int findPath(int maze[][M][W], Path *startEnd, int currRow, int currCol, int visited[][M], int manhattanDistanceToEnd[][M], int correctPath[][M]){
  //return if end is reached
  if (currRow == startEnd->rowEnd && currCol == startEnd->colEnd) return 1;

  //return if there are none unvisited neighbours
  if ((currRow + 1 > N - 1 || visited[currRow + 1][currCol] == 1) && (currCol - 1 < 0 || visited[currRow][currCol - 1] == 1) && (currRow - 1 < 0 || visited[currRow - 1][currCol] == 1) && (currCol + 1 > M - 1 || visited[currRow][currCol + 1] == 1)){
    return 0;
  }

  //mark current cell visited
  visited[currRow][currCol] = 1;

  //for reachable assing value based on manhattan distance to end (heuristcs)
  for (int i = 0; i < W; i++){
    //if there is no wall in direction calculate manhattan distance
    if (maze[currRow][currCol][i] == 0)
      manhattanDistanceToEnd[currRow][currCol] = manhattanDistance(currRow, currCol, startEnd->rowEnd, startEnd->colEnd);
  }

  //todo: pick cells in order of manhattan distance

  //call reachable neighbours in order of distance
  if (findPath(maze, startEnd, currRow + 1, currCol, visited, manhattanDistanceToEnd, correctPath)){
    //add cell to correct path
    correctPath[currRow][currCol] = 1;
    return 1;
  }
  else if (findPath(maze, startEnd, currRow, currCol - 1, visited, manhattanDistanceToEnd, correctPath)){
    //add cell to correct path
    correctPath[currRow][currCol] = 1;
    return 1;
  }
  else if (findPath(maze, startEnd, currRow - 1, currCol, visited, manhattanDistanceToEnd, correctPath)){
    //add cell to correct path
    correctPath[currRow][currCol] = 1;
    return 1;
  }
  else if (findPath(maze, startEnd, currRow, currCol + 1, visited, manhattanDistanceToEnd, correctPath)){
    //add cell to correct path
    correctPath[currRow][currCol] = 1;
    return 1;
  }

  //return if dead end is reached
  return 0;
}

void solveMaze(int maze[][M][W], Path *startEnd, int correctPath[][M]){

  //create variables for storing path infos
  int visited[N][M], manhattanDistanceToEnd[N][M];

  //initialize variables
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      correctPath[i][j] = 0; visited[i][j] = 0; manhattanDistanceToEnd[i][j] = -1;
    }
  }

  //find path
  findPath(maze, startEnd, startEnd->rowStart, startEnd->colStart, visited, manhattanDistanceToEnd, correctPath);
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
