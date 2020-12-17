/** 
*@file solve.h
*@author Jonathan Nguyen (jhnguye4) 
* This is the prototype function for solve.
*/

#include <stdbool.h>

/*
*This is the prototype function of the solve component. It attempts to solve the Sudoku puzzle represented *by the grid. It returns true if it is successful in solving the puzzle, false, otherwise. It must *use the algorithm for solving the puzzle as described below. If the puzzle is successfully *solved, grid will contain the solved Sudoku puzzle when the function returns. 
*@param n is the square root of the size
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if it can be solved and false if it cannot 
*/
bool solve(int n, int size, int grid[size][size]);
