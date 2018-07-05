#include "Lab3.h"
#include <iostream>

Stack::Stack() {
	top = -1;
}

void Stack::push(char val) {
	if (!Stack::isFull()) {
		stack[++top] = val;	
	} 
	else std::cout << "Stack is Full!" << std::endl; 
}

int Stack::pop() {
		return stack[top--];
	}

int Stack::isFull() {
	return top == stackSize - 1;
}

int Stack::isEmpty() {
	return top == -1;
}

void Stack::displayStack() {
	int sp;
	sp = top;
	while (sp != -1) {
		std::cout << stack[sp--] << std::endl;
	}
}
