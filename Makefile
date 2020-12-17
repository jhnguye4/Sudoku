CC = gcc 
CFLAGS = -Wall -std=c99 -g

sudoku: sudoku.o validate.o solve.o

sudoku.o: sudoku.c validate.h solve.h
validate.o: validate.c 
solve.o: solve.c validate.h

clean:
	rm -f sudoku.o validate.o solve.o
	rm -f sudoku
	rm -f output.*
