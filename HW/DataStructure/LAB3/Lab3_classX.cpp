/*
	Author : 20171596 김수진
	File Name : ARRAYSTK1.cpp
	Description : <Array Implementation of a Stack>
					don't use the class code
	*/

#include <iostream>
const int stackSize = 3;
int stack[stackSize];
int top;


int main() {
	void create_stack(), push(int), traverse_stack(), displayStack(); 
	int strcmp(std::string, std::string), pop(), isEmpty(), isFull(), exit(int);
	int num;
	char input[10];

	create_stack();

	while (1) {
		std::cout << "Enter command(push, pop, traverse, exit): ";
		std::cin >> input;

		if (strcmp(input, "push") == 0) {
			if (!isFull()) {
				std::cout << "Enter an integer to push => "; 
				std::cin >> num; 
				push(num);
			}
			else std::cout << "Stack is full!\n";
		}
		else if (strcmp(input, "pop") == 0) {
			if (!isEmpty()) {
				num = pop();
				std::cout << num << " is popped.\n";
			}
			else {
				std::cout << "Stack is empty!\n";
			}
		}
		else if (strcmp(input, "traverse") == 0) displayStack();
		else if (strcmp(input, "exit") == 0) break;
		else std::cout << "Bad Command!\n"; 
		}
}

	int strcmp(std::string inputStr, std::string String) {
		if (inputStr == String) {
			return 0;
			}
		return 1;
	}

	void create_stack() { 
		top = -1;
	}
	
	int isFull() { 
		if (top == stackSize - 1) return 1; 
		else return 0;
	}

	int isEmpty() {
	if (top == -1) return 1; 
	else return 0;
	 }

	 void push(int num) {
		 ++top; 
		 stack[top] = num;
 }
 
	 int pop() {
		return (stack[top--]);
	}

	 void displayStack() {
	 int sp; 
	 if (isEmpty()) std::cout << "Stack is empty!" << std::endl; 
	 else {
		 sp = top;
		 while (sp != -1) {
			 std::cout << stack[sp] << std::endl;
			 --sp;
		 }
	 } 
	}

	

