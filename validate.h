/** 
*@file validate.h
*@author Jonathan Nguyen (jhnguye4) 
* This is the prototype function for validate.
*/

#include <stdbool.h>

/**
*This function is part of the validate component. It returns true if every row in the grid *contains exactly one digit in the range 1 to size, false, otherwise
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if row is valid and false if not
*/
bool validateRows(int size, int grid[size][size]);

/**
*This function is part of the validate component. It returns true if every column in the grid * *contains exactly one digit in the range 1 to size, false, otherwise.
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if col is valid and false if not  
*/
bool validateCols(int size, int grid[size][size]);

/**
*This function is part of the validate component. It returns true if every n X n square (subgrid) *in the grid contains exactly one digit in the range 1 to size.
*@param n is the square root of the size
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if square is valid and false if not
*/
bool validateSquares(int n, int size, int grid[size][size]);

/**
*This function is part of the validate component. It returns true if every row in the grid *contains *no more than one digit in the range 1 to size, false, otherwise
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if row is valid and false if not  
*/
bool validateRowsWithSpaces(int size, int grid[size][size]);

/**
*This function is part of the validate component. It returns true if every row in the grid contains *no more than one digit in the range 1 to size, false, otherwise
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if col is valid and false if not  
*/
bool validateColsWithSpaces(int size, int grid[size][size]);

/**
*This function is part of the validate component. It returns true if every n X n square (subgrid) *in the grid contains no more than one digit in the range 1 to size.
*@param n is the square root of the size
*@param size is the height and with of grid
*@param this is the grid that stores all the values of the puzzle
*@return bool, true if square is valid and false if not  
*/
bool validateSquaresWithSpaces(int n, int size, int grid[size][size]);


