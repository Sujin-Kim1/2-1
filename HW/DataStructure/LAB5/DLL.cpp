#include <iostream>
#include "DLL.h"

Node::Node(int val)
{
    data = val;
    next = 0;
    prev = 0;
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

void List::insertFirst(int data)
{
    Node *temp = new Node(data);

    if (head == 0)
    {
        head == temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void List::insertLast(int data)
{
    Node *temp = new Node(data);

    if (head == 0)
    {
        head = temp;
    }
    else
    {
        Node *p = head;
        while (p->next != 0)
        {
            p = p->next; // move to the last
        }
        p->next = temp;
        temp->prev = p;
    }
}

void List::insertList(int data)
{
    Node *temp = new Node(data);
    Node *p, *q;

    if (head == 0) // if empty list
    {
        head == temp;
    }
    else if (temp->data < head->data) // head node 앞에 삽입
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else // 가운데 삽입
    {
        p = head;
        q = head;
        while (p != 0 && p->data < temp->data)
        {
            q = p;
            p = p->next; // 이동
        }
        if (p != 0)
        {
            temp->next = p;
            temp->prev = q;
            q->next = temp;
            p->prev = temp;
        }
        else // temp가 큰 경우
        {
            q->next = temp;
            temp->prev = q;
        }
    }
}

void List::insertNth(int index, int data)
{
    Node *temp = new Node(data);
    Node *p, *q;
    int pos = 1;
    if (index == 1)
    {
        if (head == 0)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp; 
            head = temp;
        }
    }
    else if (index <= listLength() && index > 1)
    {
        p = head;
        q = head;
        while (pos != index)
        {
            q = p;
            p = p->next;
            pos++;
        }
        temp->next = p;
        temp->prev = q;
        q->next = temp;
        p->prev = temp;
    }
    else if (index == listLength() + 1)
    {
        insertLast(data);
    }
    else 
    {
        std::cout << "index out of range" << std::endl;
    }
}

void List::deleteList(int key)
{
    Node *p, *q;

    if (head == 0)
    {
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        if (head->data == key) // 삭제될 노드가 head인 경우
        {
            if (head->next != 0) // head 외에 다른 노드가 있을 경우
            {
                p = head;
                head = head->next;
                head->prev = 0;
                delete p;
            }
            else // 노드가 head밖에 없을 경우
            {
                head = 0;
            }
        }
        else // 가운데 노드가 삭제될 경우
        {
            p = head;
            q = head;
            while (p != 0 && p->data != key) // 이동
            {
                q = p;
                p = p->next;
            }
            if (p->next != 0 && p->data == key)
            {
                q->next = p->next;
                p->next->prev = q;
                delete p;
            }
            else
            {
                std::cout << key << " is not in the list" << std::endl;
            }
        }
    }
}

void List::forwardList()
{
    if (!isEmpty())
    {
        Node *p = head;
        std::cout << "=========FORWARD LIST=========" << std::endl;
        while (p != 0)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
}

void List::backwardList()
{
    if (!isEmpty())
    {
        Node *p = head;
        while (p->next != 0)
        {
            p = p->next;
        }
        std::cout << "=========BACKWARD LIST=========" << std::endl;
        while (p != 0)
        {
            std::cout << p->data << " ";
            p = p->prev;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
}

void List::searchList(int key)
{
    if (!isEmpty())
    {
        Node *p = head;
        while (p != 0 && p->data != key)
        {
            p = p->next;
        }
        if (p != 0)
        {
            std::cout << p->data << " is in the list" << std::endl;
        }
        else
        {
            std::cout << key << " is not in the list" << std::endl;
        }
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
}

bool List::isEmpty()
{
    return head == 0;
}

void List::locateCurrent(int Nth)
{
    Node *p;
    int pos = 1;

    if (head == 0)
    {
        std::cout << "List is empty!" << std::endl;
    }
    else if (Nth <= listLength())
    {
        p = head;
        while (pos != Nth)
        {
            p = p->next;
            pos++;
        }
        std::cout << pos << " * " << p->data << std::endl;
    }
    else
    {
        std::cout << "No such a line" << std::endl;
    }
}

int List::listLength()
{
    Node *p = head;
    int len = 0;
    while (p != 0)
    {
        p = p->next;
        ++len;
    }
    return len;
}