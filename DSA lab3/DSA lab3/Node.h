#pragma once
#include <iostream>
class Node
{

public:
	int rowPos = 0;
	int colPos = 0;
	int value = 0;
	Node* next;
	Node* prev;
public:
	Node(int rowPos, int colPos,int value);
	~Node();
};