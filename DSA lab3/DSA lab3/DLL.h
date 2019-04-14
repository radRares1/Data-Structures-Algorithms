#pragma once
#include <iostream>
#include "Node.h"
using namespace std;



class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void insert_front(int,int,int);
	void insert_back(int,int,int);
	void delete_front();
	void delete_back();
	bool is_empty();
	int length();
	bool search(int,int);

	void modify(int rowPos, int colPos,int value);

	int getElement(int rowPos, int colPos);

	void deleteNode(int rowPos, int colPos);

private:
	Node* head;
	Node* tail;
	int size;

};

