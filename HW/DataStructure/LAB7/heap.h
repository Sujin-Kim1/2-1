#pragma once
#define MAX_SIZE 9

class Element
{
  private:
    int key;
    friend class Heap;
  public:
    int getKey() const;
    Element(int);
    Element();
};

class Heap
{
  private:
    Element heap[MAX_SIZE];
    int n;
  public:
    Heap();
    void Insert(int);
    void Delete();
    bool IsEmpty();
    bool IsFull();
    void Search(int item);
    void printHeap();
    void levelTest();
};