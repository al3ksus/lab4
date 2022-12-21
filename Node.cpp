#include "Node.h"

Node::Node() {
    info = '\0';
    next = nullptr;
}

Node::Node(char info) {
    this->info = info;
    next = nullptr;
}