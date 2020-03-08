//
// Created by Cristian Cerbusca on 2019-04-30.
//

#include <iostream>
#include "SortedMap.h"

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
int hash(TKey key, int m) {
	double nr =  (double)key * 0.6180339887;
	double frac = nr - std::floor(nr);
	return std::floor(m * frac);
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
SortedMap::SortedMap(Relation r): r{r}, _size{0}, ht{} {
	ht.m = 64;
	ht.arr = new Node*[ht.m]();
	ht.hash = hash;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
int SortedMap::size() const {
	return _size;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
SMIterator SortedMap::iterator() const {
	return SMIterator{*this};
}


///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
bool SortedMap::isEmpty() const {
	return _size == 0;
}

///Worst case: O(n), Best Case: O(n), Average case: Theta(n)
void HashTable::resize() {
	m *= 2;
	auto **newArr = new Node*[m]();
	int count = m / 2;
	for (int i = 0; i < count; i++) {
		auto currentN = arr[i];
		while (currentN != nullptr) {
			int newPos = hash(currentN->elem.first, m);
			auto nextPos = currentN->next;
			currentN->next = newArr[newPos];
			newArr[newPos] = currentN;
			currentN = nextPos;
		}
	}
	delete[] arr;
	arr = newArr;
}

///Worst case: O(n), Best Case: O(1), Average case: O(n)
TValue SortedMap::add(TKey c, TValue v) {
	if ((double)_size / ht.m > 0.7) {
		ht.resize();
	}
	int pos = ht.hash(c, ht.m);
	auto currentN = ht.arr[pos];
	while (currentN != nullptr and currentN->elem.first != c)
		currentN = currentN->next;
	if (currentN == nullptr) {
		Node *node = new Node;
		node->elem = {c, v};
		node->next = ht.arr[pos];
		ht.arr[pos] = node;
		_size++;
		return NULL_TVALUE;
	} else {
		int aux = currentN->elem.second;
		currentN->elem.second = v;
		return aux;
	}
}

///Worst case: O(N), Best Case: O(1), Average case: O(n)
TValue SortedMap::remove(TKey c) {
	int poz = ht.hash(c, ht.m);
	auto currentN = ht.arr[poz];
	Node *previous = nullptr;
	while (currentN != nullptr and currentN->elem.first != c) {
		previous = currentN;
		currentN = currentN->next;
	}
	if (currentN == nullptr)
		return NULL_TVALUE;
	else {
		int ret = currentN->elem.second;
		if (previous != nullptr)
			previous->next = currentN->next;
		else
			ht.arr[poz] = currentN->next;
		delete currentN;
		_size--;
		return ret;
	}
}

///Worst case: O(n), Best Case: O(1), Average case: O(n)
TValue SortedMap::search(TKey c) const {
	auto pos = ht.hash(c, ht.m);
	auto currentN = ht.arr[pos];
	while (currentN != nullptr and currentN->elem.first != c)
		currentN = currentN->next;
	if (currentN != nullptr)
		return currentN->elem.second;
	else
		return NULL_TVALUE;
}

///Worst case: O(n), Best Case: O(n), Average case: Theta(n)
SortedMap::~SortedMap() {
	for (int i = 0; i < ht.m; i++) {
		auto currentN = ht.arr[i];
		Node *nextNode = nullptr;
		while (currentN != nullptr) {
			nextNode = currentN->next;
			delete currentN;
			currentN = nextNode;
		}
	}
	delete[] ht.arr;
}