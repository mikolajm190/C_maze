#include "AIplayer.h"
#include "mazeUtils.h"

int findPath(int maze[][M][W], Path *startEnd, int currRow, int currCol, int visited[][M], int correctPath[][M]){
  //return if end is reached
  if (currRow == startEnd->rowEnd && currCol == startEnd->colEnd){
    //add ending cell to path
    correctPath[currRow][currCol] = 1;
    return 1;
  }

  //return if there are none unvisited neighbours
  if (!hasUnivistedNeighbours(visited, currRow, currCol)){
    return 0;
  }

  //mark current cell visited
  visited[currRow][currCol] = 1;

  //add cell to correct path
  correctPath[currRow][currCol] = 1;

  //call reachable neighbours
  if (jumpToUnivisited(visited, currRow + 1, currCol) && maze[currRow][currCol][0] == 0){
    if (findPath(maze, startEnd, currRow + 1, currCol, visited, correctPath)){
      return 1;
    }
  }
  if (jumpToUnivisited(visited, currRow, currCol - 1) && maze[currRow][currCol][1] == 0){
    if (findPath(maze, startEnd, currRow, currCol - 1, visited, correctPath)){
      return 1;
    }
  }
  if (jumpToUnivisited(visited, currRow - 1, currCol) && maze[currRow][currCol][2] == 0){
    if (findPath(maze, startEnd, currRow - 1, currCol, visited, correctPath)){
      return 1;
    }
  }
  if (jumpToUnivisited(visited, currRow, currCol + 1) && maze[currRow][currCol][3] == 0){
    if (findPath(maze, startEnd, currRow, currCol + 1, visited, correctPath)){
      return 1;
    }
  }

  //if none of the above worked backtrack, unmark current cell
  correctPath[currRow][currCol] = 0;

  //return if there is no solution
  return 0;
}

void solveMaze(int maze[][M][W], int correctPath[][M], int visited[][M], Path *startEnd){

  //find path
  findPath(maze, startEnd, startEnd->rowStart, startEnd->colStart, visited, correctPath);
}

void AImove(int correctPath[][M], int visited[][M], Pawn *P){
  //follow the path that you got from solveMaze

  //mark current cell visited
  visited[P->row][P->column] = 1;

  //look for next step and go
  if (jumpToUnivisited(visited, P->row + 1, P->column) && correctPath[P->row + 1][P->column] == 1) {
    P->row += 1;
  }
  else if (jumpToUnivisited(visited, P->row, P->column - 1) && correctPath[P->row][P->column - 1] == 1) {
    P->column -= 1;
  }
  else if (jumpToUnivisited(visited, P->row - 1, P->column) && correctPath[P->row - 1][P->column] == 1) {
    P->row -= 1;
  }
  else if (jumpToUnivisited(visited, P->row, P->column + 1) && correctPath[P->row][P->column + 1] == 1) {
    P->column += 1;
  }

  clear();
}
