#define queueSize 100
#pragma once

class Queue {
    public:
        int front;
        int rear;
        int queue[queueSize];
        Queue();
        void EnQueue(int val);
        int DeQueue();
        bool IsFull();
        bool IsEmpty();
        void DisplayQueue();
};