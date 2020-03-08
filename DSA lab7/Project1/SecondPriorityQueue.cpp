#include "SecondPriorityQueue.h"





SecondPriorityQueue::SecondPriorityQueue(Relation r) : relation(r), heap(relation)
{
}
//O(log N) height
void SecondPriorityQueue::push(TElem e, TPriority p)
{
	heap.insert(Element(std::make_pair(e, p)));
}
//O(1)
Element SecondPriorityQueue::top() const
{
	if (this->heap.size() < 3) throw std::exception();

	DynamicArray<Element> elements = this->heap.getElements();
	Element& max_child = elements[1];

	int child[3];

	for (int i = 1; i <= 2; i++)
		child[i] = ( i < elements.getSize()) ? i : -1;
	// loop to find the maximum of all 
	// the children of a given node 
    for (int i = 1; i <= 2; i++)
	{
		if (child[i] != -1 && relation(elements[child[i]].second, max_child.second))
		{
			max_child = elements[child[i]];
		}
	}
	return max_child;
}
//O(log N) height
Element SecondPriorityQueue::pop()
{
	if (this->heap.size() < 3) throw std::exception();
	DynamicArray<Element> elements = this->heap.getElements();
	Element& max_child = elements[1];

	int child[5];
	int max_child_index = 1;

	for (int i = 1; i <= 2; i++)
		child[i] = (i < elements.getSize()) ? i : -1;
	// loop to find the maximum of all 
	// the children of a given node 
	for (int i = 1; i <= 2; i++)
	{
		if (child[i] != -1 && relation(elements[child[i]].second, max_child.second))
		{
			max_child_index = child[i];
			max_child = elements[child[i]];
		}
	}

	heap.restoreDown(max_child_index);
	return max_child;
}
//O(1)
bool SecondPriorityQueue::atMostOne() const
{
	return this->heap.size() <= 2;
}
//O(N)
void SecondPriorityQueue::list() {
	DynamicArray<Element> elements = this->heap.getElements();
	for (int i = 0; i < elements.getSize(); i++)
		printf("%d ", elements[i].first);
}

SecondPriorityQueue::~SecondPriorityQueue()
{
}
