#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() : SIZE(10) {
    top = -1;
    stack = new char[10];
}

Stack::Stack(int size) : SIZE(size) {
    top = -1;
    stack = new char[SIZE];
}

Stack::~Stack() {
    delete[] stack;
}

void Stack::Push(char val) {
    if (IsFull()) {
        cout << "Stack Full" << endl;
    } else {
        stack[++top] = val;
    }
}

char Stack::Top() {
    if (!IsEmpty())
        return stack[top];
}

char Stack::Pop() {
    if (IsEmpty()) {
        cout << "Stack Empty" << endl;
    }
    return (stack[top--]);
}

int Stack::IsEmpty() {
    return (top == -1);
}

int Stack::IsFull() {
    return (top == SIZE - 1);
}

void Stack::DisplayStack() {
    int sp = 0;
    while (sp <= top) {
        cout << stack[sp++] << endl;
    }
}