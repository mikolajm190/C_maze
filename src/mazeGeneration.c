#include "mazeGeneration.h"
#include "mazeUtils.h"

/* passing coordinates of current cell
returns -1 when trying to jump out of maze and to the visited cell */
int jump(int maze[][M][W], int visited[][M], int cellRow, int cellCol){
  int wallInt = rand()%400000;

  //try jumping down
  if (wallInt < 100000) {
    //check if down is inside the maze and if the cell is unvisited
    if (!isUnivisited(visited, cellRow + 1, cellCol))
      return -1;
    else
      return 0;
  }
  //try jumping left
  else if (wallInt < 200000) {
    //check if left is inside the maze and if the cell is unvisited
    if (!isUnivisited(visited, cellRow, cellCol - 1))
      return -1;
    else
      return 1;
  }
  else if (wallInt < 300000) {
    //check if up is inside the maze and if the cell is unvisited
    if (!isUnivisited(visited, cellRow - 1, cellCol))
      return -1;
    else
      return 2;
  }
  else {
    //check if right is inside the maze and if the cell is unvisited
    if (!isUnivisited(visited, cellRow, cellCol + 1))
      return -1;
    else
      return 3;
  }

  return -1;
}

/* passing coordinates of current cell
it drills cells in random directions until surrounded by visited cells */
void dfs(int maze[][M][W], int visited[][M], int cellRow, int cellCol){

  //marking current cell visited
  visited[cellRow][cellCol] = 1;

  while(1){
    //breaking recursion when all neighbouring cells are visited (before checking any cell index has to be checked)
    if (!hasUnivistedNeighbours(visited, cellRow, cellCol))
      return;

    //making sure that the jump is in the viable direction
    int wallInt = jump(maze, visited, cellRow, cellCol);
    while (wallInt == -1) {
      wallInt = jump(maze, visited, cellRow, cellCol);
    }

    switch (wallInt) {
      //down cell
      case down:
      //removing walls
      maze[cellRow][cellCol][down] = 0; maze[cellRow + 1][cellCol][up] = 0;

      //jump to next cell
      dfs(maze, visited, cellRow + 1, cellCol);
      break;

      //left side neighbour
      case left:
      //removing walls
      maze[cellRow][cellCol][left] = 0; maze[cellRow][cellCol - 1][right] = 0;

      //jump to next cell
      dfs(maze, visited, cellRow, cellCol - 1);
      break;

      //up side neighbour
      case up:
      //removing walls
      maze[cellRow][cellCol][up] = 0; maze[cellRow - 1][cellCol][down] = 0;

      //jump to next cell
      dfs(maze, visited, cellRow - 1, cellCol);
      break;

      //right side neighbour
      case right:
      //removing walls
      maze[cellRow][cellCol][right] = 0; maze[cellRow][cellCol + 1][left] = 0;

      //jump to next cell
      dfs(maze, visited, cellRow, cellCol + 1);
      break;
    }
  }
}

void buildMaze(int maze[][M][W], Path *startEnd){

  //array storing info about visited cells
  int visited[N][M] = {{0}};

  /* array initialization */
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      visited[i][j] = 0;
      //at first all walls are present
      for (int k = 0; k < W; k++)
        maze[i][j][k] = 1;
    }
  }

  //random entrance and exit (row is radomized column is predefined)
  int entranceRow = rand()%N, exitRow = rand()%N;

  //creating entrance and exit
  maze[entranceRow][0][left] = 0; maze[exitRow][M - 1][right] = 0;
  startEnd->rowStart = entranceRow; startEnd->colStart = 0;
  startEnd->rowEnd = exitRow; startEnd->colEnd = M - 1;

  /* depth first search algorithm */
  dfs(maze, visited, entranceRow, 0);

}
