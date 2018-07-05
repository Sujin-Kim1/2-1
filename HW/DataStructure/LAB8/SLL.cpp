#include <iostream>
#include "SLL.h"

Node::Node()
{
    data = -1;
    next = 0;
}

Node::Node(int key)
{   
    data = key;
    next = 0;
}

List::List()
{
    head = 0;
}

List::~List()
{
    Node *p;

    while (head != 0)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

void List::insertNode(int key)
{
    Node *temp = new Node(key);
    Node *p;
    if (head == 0)
    {
        head = temp;
    }
    else 
    {
        p = head;
        while (p->next != 0)
        {
            p = p->next;
        }
        p->next = temp;
    }
}


bool List::isEmpty()
{
    return head == 0;
}
