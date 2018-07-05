#include <iostream>
#include "heap.h"

Element::Element(int k)
{
    key = k;
}

Element::Element()
{
}

int Element::getKey() const
{
    return key;
}

Heap::Heap()
{
    n = 0;
}

void Heap::Insert(int k)
{
    int i;
    Element item(k);
    if (IsFull())
    {
        std::cout << "Heap is Full" << std::endl;
        return;
    }
    i = ++n;
    while ((i != 1) && (item.getKey() > heap[i / 2].getKey()))
    {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = item;
}

void Heap::Delete()
{
    if (IsEmpty())
    {
        std::cout << "Heap is Empty" << std::endl;
        return;
    }

    int parent, child;
    Element item, temp;

    item = heap[1];  // save highest key
    temp = heap[n--]; // use the last element
    parent = 1;
    child = 2;

    while (child <= n)  // 배열의 크기만큼
    {
        if (child < n && heap[child].getKey() < heap[child + 1].getKey())  // 왼쪽 오른쪽 비교
        {
            child++;
        }
        if (temp.getKey() >= heap[child].getKey())
        {
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
}

bool Heap::IsEmpty()
{
    return n == 0;
}

bool Heap::IsFull()
{
    return n == MAX_SIZE - 1;
}

void Heap::Search(int item)
{    
    for (int i = 1; i <= n; i++)
    {
        if (heap[i].getKey() == item)
        {
            std::cout << item << " is found." << std::endl;
            return;
        }
    }
    std::cout << item << " is not found." << std::endl;
}

void Heap::printHeap()
{
    for (int i = 1; i <= n; i++)
    {
        std::cout << heap[i].getKey() << " ";
    }
    std::cout << std::endl;
}

void Heap::levelTest()
{   
    int level = 0;
    for (int i = n; i >= 1; i /= 2)
    {
        level++;
    }
    std::cout << "Heap Level " << level << std::endl;
}