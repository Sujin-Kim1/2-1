#include <iostream>
#include "stack.h"

Stack::Stack()
{
    top = -1;
}

void Stack::PUSH(char val)
{
    if (Stackfull())
    {
        std::cout << "Stack Full" << std::endl;
        return;
    }
    else stack[++top] = val;
}

void Stack::POP()
{
    if (Stackempty())
    {
        std::cout << "STACK EMPTY" << std::endl;
        return;
    }
    else stack[top--];
}

bool Stack::Stackfull()
{
    return top == MAX_STACK_SIZE - 1;
}

bool Stack::Stackempty() 
{
    return top == -1;
}

void Stack::DisplayStack()
{
    int sp = 0;
    while (sp <= top)
    {
        std::cout << stack[sp++] << " ";
    }
    std::cout << std::endl;
}