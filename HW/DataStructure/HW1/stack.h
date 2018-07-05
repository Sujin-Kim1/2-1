/*-----------------------------------------------------------------------
    file : stack.h
    국민대학교 소프트웨어학부 
    Author : 20171596 김수진
    Description : header file to declare Position and Stack class
-------------------------------------------------------------------------*/
#pragma once
#define stackSize 256

/*------------------------------------------------------------------------
	class Name : Position
	explanation of variables :
		x, y - current coordinates
		dir - current direction
-------------------------------------------------------------------------*/
class Position {
public:
	int x,y,dir;
	Position();
	Position(int x, int y, int dir);
};

/*---------------------------------------------------------------------------
	class Name : Stack
	explanation of variables :
		stack[] - array to store the data of current coordinates and direction
		top - identify the top index of stack
	explanation of function :
		push - push the Position object that was stored coordinates and direction
		pop - get the last element of stack
		isEmpty - return true if top is -1
		isFull - return true if top is 255 (stackSize - 1)
------------------ ----------------------------------------------------------*/

class Stack {
private:
	Position stack[stackSize];
	int top;
public:
	Stack();
	void push(Position val);
	Position pop();
	bool isEmpty();
	bool isFull();
};

