#include <iostream>
#include "Lab3.h"
// Stack implementation with arrays example

int main() {
	Stack s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.displayStack();

	std::cout << "Pop: " << s1.pop() << std::endl; 
	std::cout << "Pop: " << s1.pop() << std::endl;
	std::cout << "Pop: " << s1.pop() << std::endl;
	std::cout << "Pop: " << s1.pop() << std::endl;
	
	if (s1.isEmpty()) std::cout << "Stack is empty\n";

}

	