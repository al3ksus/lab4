#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

enum State{
    AFTER_BRACKETS, DEFAULT
};

void clearBrackets(Stack &stack) {
    char temp;

    do {
        temp = stack.pop();
    } while (temp != '(');
}

bool fun(string str) {
    Stack stack;
    State state = DEFAULT;
    char temp;

    for (char s : str) {
        if (s == '(') {
            temp = stack.pop();

            if (temp == '(' || temp == '+' || temp == '*' || temp == '/' || temp == '-' || temp == '\0') {
                if (temp != '\0') {
                    stack.push(temp);
                }
                stack.push(s);
            } else {
                return false;
            }
        } else if (s == ')') {
            temp = stack.pop();

            if (state == AFTER_BRACKETS) {
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                    clearBrackets(stack);
                } else {
                    return false;
                }
            } else {
                if ((temp >= '0' && temp <= '9') || temp == '(') {
                    clearBrackets(stack);
                    state = AFTER_BRACKETS;
                } else {
                    return false;
                }
            }
        } else if (s >= '0' && s <= '9') {
            if (state == AFTER_BRACKETS) {
                return false;
            }

            temp = stack.pop();

            if ((temp >= '0' && temp <= '9') || temp == '(' || temp == '+' || temp == '-' || temp == '*' ||
                temp == '/' || temp == '\0') {
                if (temp != '\0') {
                    stack.push(temp);
                }
                stack.push(s);
                state = DEFAULT;
            } else {
                return false;
            }
        } else if (s == '+' || s == '-' || s == '*' || s == '/') {
            temp = stack.pop();

            if (temp >= '0' && temp <= '9') {
                stack.push(temp);
                stack.push(s);
                state = DEFAULT;
            } else if ((temp == '(' || temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '\0') &&
                       state == AFTER_BRACKETS) {
                if (temp != '\0') {
                    stack.push(temp);
                }
                stack.push(s);
                state = DEFAULT;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    temp = stack.pop();

    if ((temp == '+' || temp == '-' || temp == '*' || temp == '/') && state == DEFAULT) {
        return false;
    }

    while (!stack.isEmpty()) {
        temp = stack.pop();
        if (temp == '(') {
            return false;
        }
    }

    return true;
}

int main() {

    string ex;
    cin >> ex;
    if (fun(ex)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}
