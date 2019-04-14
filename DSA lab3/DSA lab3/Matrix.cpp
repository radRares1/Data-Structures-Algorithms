#include "Matrix.h"

Matrix::Matrix(int rowNumber, int columnNumber)
{
	if (rowNumber <= 0 || columnNumber <= 0)
		cout << "wrong numbers";

	else
	{
		this->rowNumber = rowNumber;
		this->columnNumber = columnNumber;
		DoublyLinkedList dll;
	}
}

int Matrix::nrLines()
{
	return this->rowNumber;
}

int Matrix::nrCols()
{
	return this->columnNumber;
}

int Matrix::element(int i, int j)
{
	int elem = 0;
	if (this->dll.search(i, j) == true)
		elem = this->dll.getElement(i, j);

	return elem;
		
}

void Matrix::modify(int i, int j, int e)
{
	if (i > this->rowNumber or j > this->columnNumber)
	{
		cout << "Error, can't modify";
	}

	if (e != 0)
		this->dll.modify(i, j, e);
	else
		this->dll.deleteNode(i, j);

}
