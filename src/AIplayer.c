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

  //mark current cell visited
  visited[currRow][currCol] = 1;

  //add cell to correct path
  correctPath[currRow][currCol] = 1;

  //try going in one of 4 directions if there's legal path and cell is unvisited
  if (maze[currRow][currCol][0] == 0 && isUnivisited(visited, currRow + 1, currCol)){
    if (findPath(maze, startEnd, currRow + 1, currCol, visited, correctPath)){
      return 1;
    }
  }
  if (maze[currRow][currCol][1] == 0 && isUnivisited(visited, currRow, currCol - 1)){
    if (findPath(maze, startEnd, currRow, currCol - 1, visited, correctPath)){
      return 1;
    }
  }
  if (maze[currRow][currCol][2] == 0 && isUnivisited(visited, currRow - 1, currCol)){
    if (findPath(maze, startEnd, currRow - 1, currCol, visited, correctPath)){
      return 1;
    }
  }
  if (maze[currRow][currCol][3] == 0 && isUnivisited(visited, currRow, currCol + 1)){
    if (findPath(maze, startEnd, currRow, currCol + 1, visited, correctPath)){
      return 1;
    }
  }

  //if none of the above worked backtrack
  correctPath[currRow][currCol] = 0;

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

//follow the path that you got from solveMaze
void AImove(int maze[][M][W], int correctPath[][M], int visited[][M], Pawn *P){

  //mark current cell visited
  visited[P->row][P->column] = 1;

  //look for next step and go
  if (maze[P->row][P->column][0] == 0 && isUnivisited(visited, P->row + 1, P->column) && correctPath[P->row + 1][P->column] == 1) {
    P->row += 1;
  }
  else if (maze[P->row][P->column][1] == 0 && isUnivisited(visited, P->row, P->column - 1) && correctPath[P->row][P->column - 1] == 1) {
    P->column -= 1;
  }
  else if (maze[P->row][P->column][2] == 0 && isUnivisited(visited, P->row - 1, P->column) && correctPath[P->row - 1][P->column] == 1) {
    P->row -= 1;
  }
  else if (maze[P->row][P->column][3] == 0 && isUnivisited(visited, P->row, P->column + 1) && correctPath[P->row][P->column + 1] == 1) {
    P->column += 1;
  }

  clear();
}
