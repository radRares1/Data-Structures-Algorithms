#include "SMMIterator.h"

SMMIterator::SMMIterator(const SortedMultiMap &smm) : smm{smm} { // Ꝋ(1)
    this->current_node = smm.head;
}

TElem SMMIterator::getCurrent() { // Ꝋ(1)
    return this->current_node->info;
}

bool SMMIterator::valid() { // Ꝋ(1)
    return this->current_node != nullptr;
}

void SMMIterator::next() { // Ꝋ(1)
    this->current_node = this->current_node->next;
}

void SMMIterator::first() { // Ꝋ(1)
    this->current_node = smm.head;
}
