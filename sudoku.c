/** 
*@file sudoku.c
*@author Jonathan Nguyen (jhnguye4) 
*This program is used to check and solve sudoku puzzles. It will call upon functions in       *validate.c and solve.c to see if the puzzle in the input can be solved
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "validate.h"
#include "solve.h"

/**
*This function scans the input file and places all the numbers into a grid.
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*/
void readGrid( int size, int grid[ size ][ size ] )
{
  int value;
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      scanf("%d", &value);
      grid[i][j] = value;
    }
  }
}
/** 
*This is the main function that calls upon the functions in validate and solve to check if the  *sudoku puzzle is able to be solved or not.
*@return EXIT_SUCCESS for success status
*@return EXIT_FAILURE for fail status
*/
int main() {

  int size;
  int n = 0;
  scanf("%d", &size);

  for(int i = 0; i < size; i++){
    if((i*i) == size){
      n = i;
    }
  }
  if(n == 0){
    printf("Invalid size\n");
    return EXIT_FAILURE;
  }

  int array[size][size];
  
  readGrid(size, array);
  int zero = 0;
  for(int i = 0; i < size; i++){
    for(int j =0; j < size; j++){
      if(array[i][j] == 0){
        zero++;
      }
      if(array[i][j] < 0 || array[i][j] > size){
        printf("Invalid input\n");
        return EXIT_FAILURE;
      }
    }
  }

  if(zero == 0){
    if(validateRows(size, array) && validateCols(size, array) && validateSquares(n,size, array)){
      printf("Valid\n");
      return EXIT_SUCCESS;
    } 
    else{
      printf("Invalid\n");
      return EXIT_FAILURE;  
    }
  }
  if(zero > 0){
    if(!solve(n, size, array)){
      printf("Invalid\n");
      return EXIT_FAILURE;
    }
    
  }


}
