/**
*@file validate.c
*@author Jonathan Nguyen (jhnguye4) 
*This file is used to validate certain parts of the sudoku puzzle. It will check the rows, *columns, and subgrids
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
*This function is part of the validate component. It returns true if every row in the grid *contains exactly one digit in the range 1 to size, false, otherwise
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if row is valid and false if not
*/
bool validateRows(int size, int grid[size][size])
{
  int array[size];
  for(int i = 0; i < size; i++){
    for(int k = 0; k < size; k++){
      array[k] = 0;
    }
    for(int j = 0; j < size; j++){
      if(grid[i][j] < 1 || grid[i][j] > size){
        return false;
      }
      int value = grid[i][j];
      if(array[value - 1] > 0){
        return false;
      }
      array[value - 1] += 1;
    }
  }
  return true;
}

/**
*This function is part of the validate component. It returns true if every column in the grid * *contains exactly one digit in the range 1 to size, false, otherwise.
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if col is valid and false if not  
*/
bool validateCols(int size, int grid[size][size])
{
  int array[size];
  for(int i = 0; i < size; i++){
    for(int k = 0; k < size; k++){
      array[k] = 0;
    }
    for(int j = 0; j < size; j++){
      if(grid[j][i] < 1 || grid[j][i] > size){
        return false;
      }
      int value = grid[j][i];
      if(array[value -1] > 0){
        return false;
      }
      array[value - 1] = value;
    }
  }
  return true;
}

/**
*This function is part of the validate component. It returns true if every n X n square (subgrid) *in the grid contains exactly one digit in the range 1 to size.
*@param n is the square root of the size
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if square is valid and false if not
*/
bool validateSquares(int n, int size, int grid[size][size])
{
  int array[size];
  for(int i = 0; i < size; i += n){
    for(int j = 0; j < size; j += n){
      for(int k = 0; k < size; k++){
        array[k] = 0;
      }
      for(int k = i; k < i + n; k++){
        for(int l = j; l < j + n; l++) {
          if(grid[k][l] < 1 || grid[k][l] > size){
            return false;
          }
          int value = grid[k][l];
          if(array[value -1] > 0){
            return false;
          }
          array[value - 1] = value;
        }
      }
    
    }
  }
  return true;
}

/**
*This function is part of the validate component. It returns true if every row in the grid *contains *no more than one digit in the range 1 to size, false, otherwise
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if row is valid and false if not  
*/
bool validateRowsWithSpaces(int size, int grid[size][size])
{
  int array[size];
  for(int i = 0; i < size; i++){
    for(int k = 0; k < size; k++){
      array[k] = 0;
    }
    for(int j = 0; j < size; j++){
      if(grid[i][j] < 0 || grid[i][j] > size){
        return false;
      }
      int value = grid[i][j];
      if(value == 0){
        continue;
      }
      if(array[value - 1] > 0){
        return false;
      }
      array[value - 1] += 1;
    }
  }
  return true;
}

/**
*This function is part of the validate component. It returns true if every row in the grid contains *no more than one digit in the range 1 to size, false, otherwise
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if col is valid and false if not  
*/
bool validateColsWithSpaces(int size, int grid[size][size])
{
  int array[size];
  for(int i = 0; i < size; i++){
    for(int k = 0; k < size; k++){
      array[k] = 0;
    }
    for(int j = 0; j < size; j++){
      if(grid[j][i] < 0 || grid[j][i] > size){
        return false;
      }
      int value = grid[j][i];
      if(value == 0){
        continue;
      }
      if(array[value -1] > 0){
        return false;
      }
      array[value - 1] = value;
    }
  }
  return true;
}

/**
*This function is part of the validate component. It returns true if every n X n square (subgrid) *in the grid contains no more than one digit in the range 1 to size.
*@param n is the square root of the size
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if square is valid and false if not  
*/
bool validateSquaresWithSpaces(int n, int size, int grid[size][size])
{
  int array[size];
  for(int i = 0; i < size; i += n){
    for(int j = 0; j < size; j += n){
      for(int k = 0; k < size; k++){
        array[k] = 0;
      }
      for(int k = i; k < i + n; k++){
        for(int l = j; l < j + n; l++) {
          if(grid[k][l] < 0 || grid[k][l] > size){
            return false;
          }
          int value = grid[k][l];
          if(value == 0){
            continue;
          }
          if(array[value -1] > 0){
            return false;
          }
          array[value - 1] = value;
        }
      }
    
    }
  }
  return true;
}


