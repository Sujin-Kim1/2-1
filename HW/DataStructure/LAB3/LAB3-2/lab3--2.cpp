#include <iostream>
#include <cstring>
#include <fstream>
#include "Lab3.h"

int main() {
    std::ifstream infile;
    infile.open("data.txt");
    
    Stack s;
    char buffer[10] = {0};
    int len;

    std::cout << "Check StackFULL: " <<(s.isFull() ? "Stack is Full" : "Stack is not Full") << std::endl;
    std::cout << "Check StackEmpty: " << (s.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << std::endl;

    while (infile.getline(buffer, 80)) {
        len = strlen(buffer);
        int i = 0;
        bool isPalindrome = true;
        while (i < (len / 2)) { 
            s.push(buffer[i]);
        }
        if (len % 2 != 0) i++;    
    

        while (buffer[i] != '\0') {
            if (buffer[i] != s.pop()) {
                isPalindrome = false;
                break;
            }   
        }
        std::cout << buffer << (isPalindrome ? " a palindrome" : " not a palindrome") << std::endl;
        
    }
}