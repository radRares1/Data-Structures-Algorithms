#include "SortedMultiMap.h"
#include "SMMIterator.h"

pair<SLLNode *, SLLNode *> SortedMultiMap::searchNode(TKey c) const { // O(n)
    SLLNode *previous = nullptr;
    SLLNode *current = this->head;
    while (current != nullptr) {
        if (current->info.first == c) {
            return pair<SLLNode *, SLLNode *>{previous, current};
        }
        if (this->r(c, current->info.first)) {
            return pair<SLLNode *, SLLNode *>{previous, nullptr};
        }
        previous = current;
        current = current->next;
    }
    return pair<SLLNode *, SLLNode *>{previous, nullptr};
}

SortedMultiMap::SortedMultiMap(Relation r) : r{r} { // Ꝋ(1)
    this->head = nullptr;
}

SortedMultiMap::~SortedMultiMap() { // Ꝋ(n)
    SLLNode *aux_node;
    while (this->head != nullptr) {
        aux_node = this->head;
        this->head = this->head->next;
        delete aux_node;
    }
}

void SortedMultiMap::add(TKey c, TValue v) { // O(n)
    SLLNode *new_node = new SLLNode(TElem(c, v));

    pair<SLLNode *, SLLNode *> found_pointers = this->searchNode(c);

    if (found_pointers.first == nullptr) {
        new_node->next = this->head;
        this->head = new_node;
    }
    else {
        new_node->next = found_pointers.first->next;
        (*found_pointers.first).next = new_node;
    }
}

vector<TValue> SortedMultiMap::search(TKey c) const { // O(n)
    pair<SLLNode *, SLLNode *> found_pointers = this->searchNode(c);

    vector<TValue> values;
    while (found_pointers.second != nullptr && found_pointers.second->info.first == c) {
        values.push_back(found_pointers.second->info.second);
        found_pointers.second = found_pointers.second->next;
    }
    return values;
}

bool SortedMultiMap::remove(TKey c, TValue v) { // O(n)
    pair<SLLNode *, SLLNode *> found_pointers = this->searchNode(c);

    if (found_pointers.second != nullptr) {
        while (found_pointers.second != nullptr && found_pointers.second->info.second != v &&
               found_pointers.second->info.first == c) {
            found_pointers.first = found_pointers.second;
            found_pointers.second = found_pointers.second->next;
        }
        if (found_pointers.second != nullptr) {
            if (found_pointers.second->info.second == v && found_pointers.second->info.first == c) {
                if (found_pointers.first == nullptr) {
                    this->head = this->head->next;
                }
                else {
                    found_pointers.first->next = found_pointers.second->next;
                }
                delete found_pointers.second;
                return true;
            }
        }
    }
    return false;
}

int SortedMultiMap::size() const { // Ꝋ(n)
    int nr_of_nodes = 0;
    SLLNode *current_node = this->head;
    while (current_node != nullptr) {
        nr_of_nodes++;
        current_node = current_node->next;
    }
    return nr_of_nodes;
}

bool SortedMultiMap::isEmpty() const { // Ꝋ(1)
    return this->head == nullptr;
}

SMMIterator SortedMultiMap::iterator() const { // Ꝋ(1)
    return SMMIterator(*this);
}
