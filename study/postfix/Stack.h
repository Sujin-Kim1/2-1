#pragma once

class Stack {
    private:
        int top;
        const int SIZE;
        char * stack;
    public:
        Stack();
        Stack(int);
        ~Stack();
        void Push(char val);
        char Top();
        char Pop();
        int IsEmpty();
        int IsFull();
        void DisplayStack();
};