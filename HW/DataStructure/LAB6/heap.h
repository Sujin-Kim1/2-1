#pragma once

class maxheap
{
  private:
    int* n;
    int max_size;
    int item;
    int* heap;

  public:
    maxheap(int Max_size);
    ~maxheap();
    void create(int [], int);
    int* getN() const; 
    bool HeapFull(int *n);
    void insert_maxheap(int item, int *n);
    bool HeapEmpty(int *n);
    int delete_maxheap(int *n);
    void search(int item, int* n);
};