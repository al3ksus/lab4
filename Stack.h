#include "Node.h"

class Stack {
public:
    Node* first;

    Stack();

    bool isEmpty();

    void push(char x);

    char pop();

    void print();
};

