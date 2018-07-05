#include <iostream>
#include "heap.h"

maxheap::maxheap(int Max_size)
    :max_size(Max_size), heap(new int[Max_size])
{
}

maxheap::~maxheap()
{
    delete[] heap;
}

void maxheap::create(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        maxheap *new_data = new maxheap(len);
    }
}

int* maxheap::getN() const
{
    return n;
}

bool maxheap::HeapFull(int* n)
{
    return *n == max_size;
}

void maxheap::insert_maxheap(int item, int* n)
{
    int i;
    if (HeapFull(n))
    {
        std::cerr << "Heap is full" << std::endl;
        return;
    }
    i = ++(*n);
    while ((i != 1) && (item > heap[i / 2]))
    {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = item;
}

bool maxheap::HeapEmpty(int *n)
{
    return *n == 0;
}

int maxheap::delete_maxheap(int *n)
{
    int parent, child;
    int item, temp;

    if (HeapEmpty(n))
    {
        std::cerr << "Heap is empty" << std::endl;
        return -1;
    }

    item = heap[1];  // save the highest key
    temp = heap[(*n)--];  // use the last element

    parent = 1;
    child = 2;

    while (child <= *n)
    {
        if ((child < *n) && (heap[child] < heap[child + 1]))
            child++;  // find largest child
        if (temp >= heap[child])
            break;
        heap[parent] = heap[child];
        parent = child;
        child = child * 2;
    }
    heap[parent] = temp;
    return item;
}

void maxheap::search(int item, int* n)
{
    for (int i = 0; i < *n;i++)
    {
        if (heap[i] == item)
        {
            std::cout << item << " is found." << std::endl;
        }
        else
        {
            std::cout << item << " is not found." << std::endl;
        }
    }
}

