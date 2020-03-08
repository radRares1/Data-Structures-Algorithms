#pragma once

#include "SLLNode.h"

class SMMIterator;

class SortedMultiMap {
private:
    friend class SLLNode;

    friend class SMMIterator;

    pair<SLLNode *, SLLNode *> searchNode(TKey c) const;
    // Returns a pair <previousNode, KNode>
    // If c is found, KNode is its first position and previousNode the one before
    // If c is not found, KNode is nullptr and previousNode the one before where it should be added

    SLLNode *head;
    Relation r;
public:

    // constructor
    explicit SortedMultiMap(Relation r);

    //adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

    //returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

    //removes a key value pair from the sorted multimap
    //returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();
};
