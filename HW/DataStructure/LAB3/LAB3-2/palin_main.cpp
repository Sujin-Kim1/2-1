#include <iostream>
#include <fstream>
#include "palin.h"
#include <cstring>

int main() {
    std::ifstream inStream;
    inStream.open("data.txt");

    Stack s;
    std::cout << "Check StackFULL: ";
    std::cout << (s.isFull()? "Stack is Full" : "Stack is not Full") << std::endl;
    std::cout << "Check StackEmpty: ";
    std::cout << (s.isEmpty()? "Stack is Empty" : "Stack is not Empty") << std::endl;

    int len;
    char buffer[100] = {0};


    while (inStream.getline(buffer, 80)) {
        len = strlen(buffer);
        int i = 0;
        bool isPal = true;
        while (i < (len / 2)) {
            s.push(buffer[i++]);
        }
        if (len % 2 != 0) {
            i++;
        }
        while (buffer[i] != '\0') {
            if (buffer[i++] != s.pop()) {
                isPal = false;
                break;
            }
        } 
        if (isPal) {
            std::cout << buffer << " a Palindrome" << std::endl;
        } else {
            std::cout << buffer << " not a Palindrome" << std::endl;
        }
    }
}