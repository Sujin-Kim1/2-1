#pragma once
#define QUEUE_SIZE 3

class CircularQueue
{
  private:
    char circularQ[QUEUE_SIZE];
    int front, rear;

  public:
    CircularQueue();
    void enque(char item);
    void deque();
    bool IsFull();
    bool IsEmpty();
    void DisplayCircularQueue();
};