#include "Node.h"
#include <iostream>
Node::Node(int rowPos, int colPos, int value)
{
	this->rowPos = rowPos;
	this->colPos = colPos;
	this->value = value;
	this->next = NULL;
	this->prev = NULL;
}

Node::~Node()
{
}