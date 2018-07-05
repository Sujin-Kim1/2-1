#include <iostream>
#include "lab5.h"

int main() 
{
    List l;
    l.insertList(10);
    l.insertList(20);
    l.insertList(30);
    l.forwardList();
    l.insert_after(2, 40);
    l.forwardList();
    l.insert_before(3, 50);    
    l.forwardList();
    l.deleteNth(5);
    l.forwardList();
    l.backwardList();
    }