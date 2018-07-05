#include <iostream>
#include "stack.h"

Stack::Stack()
{
    top = -1;
}

void Stack::PUSH(int top, char token)
{
    if (!isFull())
    {
        stack[++top] == token;
    }
    else
        std::cout << "Stack is Full" << std::endl;
}

void Stack::POP()
{
    if (!isEmpty())
    {
        stack[top--];
    }
    else
        std::cout << "Stack is Empty" << std::endl;
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == STACK_SIZE - 1;
}

void Stack::displayStack()
{
    int sp = top;
    while (sp != -1)
    {
        std::cout << stack[top--] << std::endl;
    }
}