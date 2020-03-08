#include "Heap.h"


Heap::Heap(Relation r)
{
	this->relation = r;
	this->heap = DynamicArray<Element>{ 50 };
}

bool Heap::insert(Element element)
{
	this->heap.add(element);
	restoreUp(heap.getSize()-1);
	return true;
}



int Heap::size() const
{
	return this->heap.getSize();
}

void Heap::restoreUp(int index)
{
	// parent stores the index of the parent of the node 
	int parent = (index - 1) / 2;
	int poz = index;
	Element elem = heap[poz];
	while (poz > 0 && relation(elem.second, heap[parent].second))
	{
			heap[poz] = heap[parent];
			poz = parent;
			parent = (poz - 1) / 2;

	}
	heap[poz] = elem;
}


void Heap::restoreDown( int index)
{
	heap[index] = heap[heap.getSize() - 1];
	heap.remove(heap.getSize() - 1);
	// child array to store indexes of all the children of given node 
	int child[3];

	int poz = index;
	Element	elem = heap[index];

	while (poz < heap.getSize())
	{
		int max_child_index = -1;
		// child[i]=-1 if the node is a leaf 
		for (int i = 1; i <= 2; i++)
			child[i] = ((poz *2 + i) < heap.getSize()) ? (poz *2 + i) : -1;

		// max_child stores the maximum child and 
		// max_child_index holds its index 
		Element max_child = heap[child[1]];
		

		// loop to find the maximum of all 
		// the children of a given node 
		for (int i = 1; i <= 2; i++)
		{
			if (child[i] != -1 && relation(heap[child[i]].second, max_child.second))
			{
				max_child_index = child[i];
				max_child = heap[child[i]];
			}
		}

		// leaf node 
		if (max_child_index != -1 && relation( heap[max_child_index].second, elem.second)) {
			Element temp = heap[poz];
			heap[poz] = heap[max_child_index];
			heap[max_child_index] = temp;
			poz = max_child_index;
		
		}
		else  {
			poz = heap.getSize() + 1;
		}
		

	}
}




DynamicArray<Element> Heap::getElements() const
{
	return this->heap;
}

Heap::~Heap()
{
}
