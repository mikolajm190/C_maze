#include "mazeGeneration.h"

/* passing coordinates of current cell
returns -1 when trying to jump out of maze and to the visited cell */
int jump(int maze[][M][W], int cellRow, int cellCol){
  int wallInt = rand()%400000;

  //try jumping down
  if (wallInt < 100000) {
    //check if down is inside the maze and if the cell is unvisited
    if (cellRow + 1 > (N - 1) || maze[cellRow + 1][cellCol][4] == 1)
      return -1;
    else
      return 0;
  }
  //try jumping left
  else if (wallInt < 200000) {
    //check if left is inside the maze and if the cell is unvisited
    if (cellCol - 1 < 0 || maze[cellRow][cellCol - 1][4] == 1)
      return -1;
    else
      return 1;
  }
  else if (wallInt < 300000) {
    //check if up is inside the maze and if the cell is unvisited
    if (cellRow - 1 < 0 || maze[cellRow - 1][cellCol][4] == 1)
      return -1;
    else
      return 2;
  }
  else {
    //check if right is inside the maze and if the cell is unvisited
    if (cellCol + 1 > (M - 1) || maze[cellRow][cellCol + 1][4] == 1)
      return -1;
    else
      return 3;
  }

  return -1;
}

/* passing coordinates of current cell
it drills cells in random directions until surrounded by visited cells */
void dfs(int maze[][M][W], int cellRow, int cellCol){

  //marking current cell visited
  maze[cellRow][cellCol][4] = 1;

  while(1){
  //breaking recursion when all neighbouring cells are visited (before checking any cell index has to be checked)
  if ((cellRow - 1 < 0 || maze[cellRow - 1][cellCol][4] == 1) &&
  (cellRow + 1 > N - 1 || maze[cellRow + 1][cellCol][4] == 1) &&
  (cellCol - 1 < 0 || maze[cellRow][cellCol - 1][4] == 1) &&
  (cellCol + 1 > M - 1 || maze[cellRow][cellCol + 1][4] == 1))
    return;

  //making sure that the jump is in the viable direction
  int wallInt = jump(maze, cellRow, cellCol);
  while (wallInt == -1) {
    wallInt = jump(maze, cellRow, cellCol);
  }

  switch (wallInt) {
    //down cell
    case 0:
    //removing walls
    maze[cellRow][cellCol][0] = 0; maze[cellRow + 1][cellCol][2] = 0;

    //jump to next cell
    dfs(maze, cellRow + 1, cellCol);
    break;

    //left side neighbour
    case 1:
    //removing walls
    maze[cellRow][cellCol][1] = 0; maze[cellRow][cellCol - 1][3] = 0;

    //jump to next cell
    dfs(maze, cellRow, cellCol - 1);
    break;

    //up side neighbour
    case 2:
    //removing walls
    maze[cellRow][cellCol][2] = 0; maze[cellRow - 1][cellCol][0] = 0;

    //jump to next cell
    dfs(maze, cellRow - 1, cellCol);
    break;

    //right side neighbour
    case 3:
    //removing walls
    maze[cellRow][cellCol][3] = 0; maze[cellRow][cellCol + 1][1] = 0;

    //jump to next cell
    dfs(maze, cellRow, cellCol + 1);
    break;
  }
}
}

void buildMaze(int maze[][M][W]){

  /* array initialization */
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      //at first all walls are present
      for (int k = 0; k < (W - 1); k++)
        maze[i][j][k] = 1;
    }
  }

  //random entrance and exit (row is radomized column is predefined)
  int entranceRow = rand()%10, exitRow = rand()%10;

  //creating entrance and exit
  maze[entranceRow][0][1] = 0; maze[exitRow][M - 1][3] = 0;

  /* depth first search algorithm */
  dfs(maze, entranceRow, 0);

}
