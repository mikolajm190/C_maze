#include "mazeUtils.h"

int hasUnivistedNeighbours(int visited[][M], int cellRow, int cellCol){
  //check if cell has any unvisited neighbours, before check if coordinates are valid
  if ((cellRow + 1 > N - 1 || visited[cellRow + 1][cellCol] == 1) && (cellCol - 1 < 0 || visited[cellRow][cellCol - 1] == 1) && (cellRow - 1 < 0 || visited[cellRow - 1][cellCol] == 1) && (cellCol + 1 > M - 1 || visited[cellRow][cellCol + 1] == 1)) {
    return 0;
  }
  else {
    return 1;
  }
}

int jumpToUnivisited(int visited[][M], int cellRow, int cellCol){
  //check if cell with given cooridnates is inside the maze
  if (cellRow < 0 || cellRow > N - 1 || cellCol < 0 || cellCol > M - 1){
    return 0;
  }
  //check if the cell has been visited
  else if (visited[cellRow][cellCol] == 1){
    return 0;
  }
  else {
    return 1;
  }
}
