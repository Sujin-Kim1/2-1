#pragma once
#define Stack_size 20

class Stack {
private:
    char stack[Stack_size];
    int top;
public:
    Stack();
    void push(char val);
    char pop();
    int isEmpty();
    int isFull();
};