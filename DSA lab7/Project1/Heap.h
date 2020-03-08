#pragma once
#include "DynamicArray.h"

typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool(*Relation)(TPriority p1, TPriority p2);


class Heap {
private:
    DynamicArray<Element> heap;
	Relation relation;

public:

	//constructor
	Heap(Relation r);


	//adds an element to the sorted set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool insert(Element e);




	int size() const;

	void restoreUp(int index);

	void restoreDown(int index);



	DynamicArray<Element> getElements() const;

	// destructor
	~Heap();

};

