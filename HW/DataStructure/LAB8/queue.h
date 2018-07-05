#pragma once
#define MAX_QUEUE_SIZE 100

class Queue
{
  private:
    int queue[MAX_QUEUE_SIZE];
    int front, rear;

  public:
    Queue();
    void ENQUE(int item);
    int DEQUE();
    bool QFull();
    bool QEmpty();
    void DisplayQueue();
};