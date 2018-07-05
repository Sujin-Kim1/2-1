#include <iostream>
#include "palin.h"
#include <fstream>
#include <cstring>
#define MAX_SIZE 10

using namespace std;

int main() {
    ifstream inStream;
    inStream.open("data.txt");

    Stack s;
    char buffer[MAX_SIZE] = {0};
    int len;

    cout << "Check StackFull: ";
    cout << (s.isFull() ? "Stack is Full" : "Stack is not Full") << endl;
    
    cout << "Check StackEmpty: ";
    cout << (s.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;

    while(inStream.getline(buffer, 80)) {
        len = strlen(buffer);
        int i = 0;
        bool isPalindrome = true;
        while (i < (len / 2)) {
            s.push(buffer[i++]);
        }
        if (len % 2 == 1) i++;
        while (buffer[i] != '\0') {
            if (buffer[i++] != s.pop()) {
                isPalindrome = false;
                break;
            }
        }
        cout << buffer << (isPalindrome ? " a palindrome" : " not a palindrome") << endl;
    }

    inStream.close();
}