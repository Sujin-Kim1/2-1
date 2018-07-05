#include <iostream>
#include "heap.h"

int main()
{
    Heap h;
    h.Delete();
    h.Insert(8);
    h.Insert(6);
    h.Insert(4);
    h.Insert(2);
    h.Insert(5);
    h.Insert(3);
    h.printHeap();
    h.Insert(9);
    h.printHeap();
    h.Insert(7);    
    h.printHeap();
    h.Insert(7);    
    h.levelTest();    
    h.Delete();
    h.printHeap();
}