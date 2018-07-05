#include <iostream>
#include "SLL.h"

int main() 
{
    List l;
    l.insertNode(40);
    l.insertNode(30);
    l.append(50);
    l.append(80);
    l.traverseList();
    l.deleteNode(30);
    l.traverseList();
    l.searchList(30);
    l.searchList(40);
    l.~List();
    l.traverseList();
}