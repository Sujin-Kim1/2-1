#pragma once
#define MAX_QUEUE_SIZE 100

class Queue {
public:
    Queue();

    void ENQUE(int item);

    int DEQUE();

    bool QEmpty() const;

    bool QFull() const;

private:
    int queue[MAX_QUEUE_SIZE];
    int front, rear;
};