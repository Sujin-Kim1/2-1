//-------------------------------------------------------------------
// File : Stack.cpp
// 국민대학교 소프트웨어학부
// Author : 20171595 김성식
// Date : 2018.04.02
// Description : C++ file to implement constructors, variables and
// functions declared in "Stack.h"
// Purpose : to struct stack data structure
//-------------------------------------------------------------------

#include "Stack.h"

Stack::Stack() {
    top = -1;
}
void Stack::Push(Position pos) {
    if (IsFull()) {
        return;
    } else {
        position[++top] = pos;
    }
}
Position Stack::Pop() {
    if (IsEmpty()) {
        return Position(-1, -1, -1);
    }
    return (position[top--]);
}
bool Stack::IsEmpty() {
    return (top == -1);
}
bool Stack::IsFull() {
    return (top == STACK_SIZE - 1);
}

Position::Position(int x, int y, int dir) {
    this -> x = x;
    this -> y = y;
    this -> dir = dir;
}

Position::Position() {
}