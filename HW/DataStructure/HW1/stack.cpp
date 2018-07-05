/*---------------------------------------------------------------------------
	file : stack.cpp
	국민대학교 소프트웨어학부 
    Author : 20171596 김수진
    Description : C++ file to implement the variables, functions, constructors
				declared in "stack.h"
------------------ ----------------------------------------------------------*/

#include "stack.h"
#include <iostream>

Stack::Stack() {
	top = -1;
}

void Stack::push(Position val) {
	if (!Stack::isFull()) {
		stack[++top] = val;	
	} 
	else std::cout << "Stack is Full!" << std::endl; 
}

Position Stack::pop() {
		return stack[top--];
	}

bool Stack::isFull() {
	return top == stackSize - 1;
}

bool Stack::isEmpty() {
	return top == -1;
}

Position::Position() {}

Position::Position(int i, int j, int d) {
	this -> x = i;
	this -> y = j;
	this -> dir = d;
}

