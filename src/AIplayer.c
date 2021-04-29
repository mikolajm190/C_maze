#include "AIplayer.h"
#include "mazeUtils.h"

//needs fixing
int findPath(int maze[][M][W], Path *startEnd, int currRow, int currCol, int visited[][M], int correctPath[][M]){
  //return if end is reached
  if (currRow == startEnd->rowEnd && currCol == startEnd->colEnd){
    //add exit cell to path
    correctPath[currRow][currCol] = 1;
    return 1;
  }

  //return if there are none unvisited neighbours
  if (!hasUnivistedNeighbours(visited, currRow, currCol)){
    return 0;
  }

  //mark current cell visited
  visited[currRow][currCol] = 1;

  //call reachable neighbours
  if (maze[currRow][currCol][0] == 0 && isUnivisited(visited, currRow + 1, currCol)){
    if (findPath(maze, startEnd, currRow + 1, currCol, visited, correctPath)){
      //add cell to correct path
      correctPath[currRow][currCol] = 1;
      return 1;
    }
  }
  if (maze[currRow][currCol][1] == 0 && isUnivisited(visited, currRow, currCol - 1)){
    if (findPath(maze, startEnd, currRow, currCol - 1, visited, correctPath)){
      //add cell to correct path
      correctPath[currRow][currCol] = 1;
      return 1;
    }
  }
  if (maze[currRow][currCol][2] == 0 && isUnivisited(visited, currRow - 1, currCol)){
    if (findPath(maze, startEnd, currRow - 1, currCol, visited, correctPath)){
      //add cell to correct path
      correctPath[currRow][currCol] = 1;
      return 1;
    }
  }
  if (maze[currRow][currCol][3] == 0 && isUnivisited(visited, currRow, currCol + 1)){
    if (findPath(maze, startEnd, currRow, currCol + 1, visited, correctPath)){
      //add cell to correct path
      correctPath[currRow][currCol] = 1;
      return 1;
    }
  }

  return 0;
}

void solveMaze(int maze[][M][W], int correctPath[][M], int visited[][M], Path *startEnd){
  //initialize arrays
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      correctPath[i][j] = 0; visited[i][j] = 0;
    }
  }

  //find path
  findPath(maze, startEnd, startEnd->rowStart, startEnd->colStart, visited, correctPath);

  //clear visited array
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      visited[i][j] = 0;
    }
  }
}

void AImove(int correctPath[][M], int visited[][M], Pawn *P){
  //follow the path that you got from solveMaze

  //mark current cell visited
  visited[P->row][P->column] = 1;

  //look for next step and go
  if (isUnivisited(visited, P->row + 1, P->column) && correctPath[P->row + 1][P->column] == 1) {
    P->row += 1;
  }
  else if (isUnivisited(visited, P->row, P->column - 1) && correctPath[P->row][P->column - 1] == 1) {
    P->column -= 1;
  }
  else if (isUnivisited(visited, P->row - 1, P->column) && correctPath[P->row - 1][P->column] == 1) {
    P->row -= 1;
  }
  else if (isUnivisited(visited, P->row, P->column + 1) && correctPath[P->row][P->column + 1] == 1) {
    P->column += 1;
  }

  clear();
}
