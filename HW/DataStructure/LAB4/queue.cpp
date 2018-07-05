#include <iostream>
#include "queue.h"

Queue::Queue()
{
    front = -1;
    rear = -1;
}

void Queue::ENQUE(char item)
{
    if (QFull())
    {
        std::cout << "Queue Full" << std::endl;
    }
    else
        queue[++rear] = item;
}

void Queue::DEQUE()
{
    if (QEmpty())
    {
        std::cout << "QUEUE EMPTY" << std::endl;
    }
    else
        queue[++front];
}

bool Queue::QFull()
{
    return rear == MAX_QUEUE_SIZE - 1;
}

bool Queue::QEmpty()
{
    return rear == front;
}

void Queue::DisplayQueue()
{
    int i;
    i = front + 1;
    while (i <= rear)
    {
        std::cout << queue[i++] << " ";
    }
    std::cout << std::endl;
}



