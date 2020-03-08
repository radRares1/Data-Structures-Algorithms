#pragma once

#include <vector>

typedef int TKey;
typedef int TValue;

#include <utility>

typedef std::pair<TKey, TValue> TElem;
using namespace std;

typedef bool(*Relation)(TKey, TKey);

class SortedMultiMap;
class SMMIterator;

class SLLNode {
private:
    friend class SortedMultiMap;
    friend class SMMIterator;
    TElem info;
    SLLNode * next;

public:
    explicit SLLNode(TElem elem);
    ~SLLNode();

};