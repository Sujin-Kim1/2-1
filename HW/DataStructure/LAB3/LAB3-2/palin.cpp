#include <iostream>
#include "palin.h"

Stack::Stack() {
    top = -1;
}

void Stack::push(char val) {
    stack[++top] = val;
}

char Stack::pop() {
    return stack[top--];
}

int Stack::isEmpty() {
    return top == -1;
}

int Stack::isFull() {
    return top == Stack_size - 1;
}