#include <utility>

#include "SLLNode.h"

SLLNode::SLLNode(TElem elem) : info{std::move(elem)}, next{nullptr} {
};

SLLNode::~SLLNode() = default;
