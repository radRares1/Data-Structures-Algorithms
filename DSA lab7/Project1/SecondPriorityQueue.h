#pragma once
#include <utility>
#include "Heap.h"

using namespace std;


class SecondPriorityQueue
{
private:
	Relation relation;
	Heap heap;

public:
	//implicit constructor
	SecondPriorityQueue(Relation r);

	//adds an element with a priority to the queue
	void push(TElem e, TPriority p);

	//returns the element with the second highest priority with respect to the relation
   //throws exception if the queue has less than 2 elements
	Element top()  const;

	//removes and returns the element with the second highest priority
	//throws exception if the queue has less than 2 elements
	Element pop();

	//checks if the queue has at most one element
	bool atMostOne() const;

	void list();

	//destructor
	~SecondPriorityQueue();
};

