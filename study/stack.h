#pragma once
#define STACK_SIZE 20

class Stack
{
  private:
    int stack[STACK_SIZE];
    int top;

  public:
    Stack();
    void PUSH(int top, char token);
    void POP();
    bool isEmpty();
    bool isFull();
    void displayStack();
};
