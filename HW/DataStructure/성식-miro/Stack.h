//-------------------------------------------------------------------
// File : Stack.h
// 국민대학교 소프트웨어학부
// Author : 20171595 김성식
// Date : 2018.04.02
// Description : Header file to declare Position and Stack class
// Purpose : to struct stack data structure
//-------------------------------------------------------------------
#define STACK_SIZE 100

// Class Name : Position
// Global variables
// * x, y - type : integer
// - purpose : to save the coordinate value of the position
// * dir - type : int
// - purpose : to save the direction you come from
class Position {
    public:
        int x;
        int y;
        int dir;
        Position();
        Position(int x, int y, int dir);
};

// Class Name : Stack
// Global variables
// * top - type : integer
// - purpose : to identify top index of stack
// * position - type : Position array
// - purpose : to contain the data of position
// Functions
// * Push - return type : void
// - purpose : to add a new position to stack
// * Pop - return type : Position
// - purpose : to get the last element of the stack
// * IsEmpty - return type : boolean
// - purpose : to identify if the stack is empty
// * IsFull - return type : boolean
// - purpose : to identify if the stack is full
class Stack {
    public:
        int top;    
        Position position[STACK_SIZE];
        Stack();
        void Push(Position pos);
        Position Pop();
        bool IsEmpty();
        bool IsFull();
};