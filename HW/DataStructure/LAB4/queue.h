#pragma once
#define MAX_QUEUE_SIZE 3

class Queue
{
  private:
    char queue[MAX_QUEUE_SIZE];
    int front, rear;

  public:
    Queue();
    void ENQUE(char item);
    void DEQUE();
    bool QFull();
    bool QEmpty();
    void DisplayQueue();
};