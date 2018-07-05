#include <iostream>
#include "circularQueue.h"

CircularQueue::CircularQueue()
{
    front = -1;
    rear = -1;
}

void CircularQueue::enque(char item)
{
    if (IsFull())
    {
        std::cout << "Queue is Full" << std::endl;
        return;
    }
    else 
    {
        rear = (rear + 1) % QUEUE_SIZE;
        circularQ[rear] = item;
    }
}

void CircularQueue::deque()
{
    if (IsEmpty())
    {
        std::cout << "Queue is Empty" << std::endl;
        return;
    }
    else 
    {
        front = (front + 1) % QUEUE_SIZE;
        circularQ[front];
    }
}

bool CircularQueue::IsFull() 
{
    int temp = (rear + 1) % QUEUE_SIZE;
    return front == temp;
}

bool CircularQueue::IsEmpty()
{
    return front == rear;
}


void CircularQueue::DisplayCircularQueue()
{
    int i;
    i = front + 1;
    while (i <= rear)
    {
        std::cout << circularQ[i++] << " ";
    }
    std::cout << std::endl;
}