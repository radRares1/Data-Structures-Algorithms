#pragma once
#include "DLL.h"


typedef int TElem;

#define NULL_TELEM 0


class Matrix {



private:
	int columnNumber = 0;
	int rowNumber = 0;
	DoublyLinkedList dll;

public:

	//constructor

	//throws exception if nrLines or nrCols is negative or zero
	
	Matrix(int rowNumber, int columnNumber);



	//returns the number of lines

	int nrLines() ;



	//returns the number of columns

	int nrCols();



	//returns the element from line i and column j (indexing starts from 0)

	//throws exception if (i,j) is not a valid position in the Matrix

	int element(int i, int j);



	//modifies the value from line i and column j

	//returns the previous value from the position

	//throws exception if (i,j) is not a valid position in the Matrix

	void modify(int i, int j, int e);



};
