#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
    first = nullptr;
}

bool Stack::isEmpty() {
    return first == nullptr;
}

void Stack::push(char x) {
    Node* temp = new Node(x);

    if (isEmpty()) {
        first = temp;
        return;
    }

    temp->next = first;
    first = temp;
}

char Stack::pop() {

    if (isEmpty()) {
        return '\0';
    }

    char x = first->info;
    Node* temp = first->next;

    delete first;

    first = temp;

    return x;
}

void Stack::print() {
    Stack tempStack;
    char x;

    if (isEmpty()) {
        return;
    }

    while (first) {
        x = this->pop();
        cout << x << ' ';
        tempStack.push(x);
    }

    cout << endl;

    while (tempStack.first) {
        this->push(tempStack.pop());
    }
}
