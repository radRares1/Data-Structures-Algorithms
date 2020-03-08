#pragma once
#include "SortedMultiMap.h"

class SLLNode;
class SortedMultiMap;

class SMMIterator {
private:
    friend class SortedMultiMap;
    friend class SLLNode;
    const SortedMultiMap &smm;
    SLLNode * current_node;

    explicit SMMIterator(const SortedMultiMap &smm);
public:

    TElem getCurrent();

    bool valid();

    void next();

    void first();
};


