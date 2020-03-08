//
// Created by Cristian Cerbusca on 2019-04-30.
//

#include <stdexcept>
#include <iostream>
#include "SMIterator.h"

/// Best Case: O(n), Worst Case: all elements are to be inserted in the back: O(n^2), Average case: O(n^2)
SMIterator::SMIterator(const SortedMap &sm): sm{sm}, current{nullptr}, sorted{nullptr} {
	for (int i = 0; i < sm.ht.m; i++) {
		if (sm.ht.arr[i] != nullptr) {
			Node *newNode = new Node;
			newNode->elem = {sm.ht.arr[i]->elem.first, sm.ht.arr[i]->elem.second};
			if (sorted == nullptr or sm.r(newNode->elem.first, sorted->elem.first)) {
				newNode->next = sorted;
				sorted = newNode;
			} else {
				Node *currentN = sorted;
				while (currentN->next != nullptr and sm.r(currentN->next->elem.first, newNode->elem.first))
					currentN = currentN->next;
				newNode->next = currentN->next;
				currentN->next = newNode;
			}
		}
	}
	current = sorted;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
void SMIterator::first() {
	current = sorted;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
TElem SMIterator::getCurrent() const {
	if (!valid())
		throw std::runtime_error("Iterator not valid");
	return current->elem;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
void SMIterator::next() {
	if (!valid())
		throw std::runtime_error("Iterator not valid");
	current = current->next;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
bool SMIterator::valid() const {
	return current != nullptr;
}

//////Worst case: O(n), Best Case: O(n), Average case: Theta(n)
SMIterator::~SMIterator() {
	Node *nextNode;
	while (sorted != nullptr) {
		nextNode = sorted->next;
		delete sorted;
		sorted = nextNode;
	}
}