#pragma once
#define MAX_STACK_SIZE 2

class Stack
{
  private:
    char stack[MAX_STACK_SIZE];
    int top;

  public:
    Stack();
    void PUSH(char val);
    void POP();
    bool Stackfull();
    bool Stackempty();
    void DisplayStack();
};