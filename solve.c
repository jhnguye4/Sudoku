/**
*This part of the program is called if there are blank spaces in the puzzle. This function will  *call upon the the validate functions and check if the puzzle can be solved
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "validate.h"
/*
*This function is part of the solve component. It attempts to solve the Sudoku puzzle represented *by the grid. It returns true if it is successful in solving the puzzle, false, otherwise. It must *use the algorithm for solving the puzzle as described below. If the puzzle is successfully *solved, grid will contain the solved Sudoku puzzle when the function returns. 
*@param n is the square root of the size
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if it can be solved and false if it cannot 
*/
bool solve(int n, int size, int grid[size][size])
{
  int count = 0;
  int cords = 0;
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(grid[i][j] == 0){
        count++;
      }
    }
  }
  int unsolved[count][2];
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(grid[i][j] == 0){
        unsolved[cords][0] = i;
        unsolved[cords][1] = j;
        cords++;
      }
    }
  }
  int current = 0;
  int i = 1;
  while(true){
    int x = unsolved[current][0];
    int y = unsolved[current][1];

    i = grid[x][y];
    i++;

    grid[x][y] = i;
    if(validateRowsWithSpaces(size, grid) && validateColsWithSpaces(size, grid) && validateSquaresWithSpaces(n, size, grid)){
      current++;

    }
    if (i > size) {
      grid[x][y] = 0;
      current--;
      
    }
    if(current == count){
      for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
          printf("%3d ", grid[i][j]);
        }
        printf("\n");
      }
      return true;
    }

    if(current < 0){
      return false;
    }
  }
  return true;
}
