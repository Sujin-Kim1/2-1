#pragma once
#define stackSize 20

class Stack {
private:
	char stack[stackSize];
	int top;
public:
	Stack();
	void push(char val);
	int pop();
	int isEmpty();
	int isFull();
	void displayStack();
};

