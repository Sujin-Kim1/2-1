#include <iostream>
#include "SLL.h"

List::List()
{
    head = 0;
}

bool List::isEmpty()
{
    return head == 0;
}

void List::insertNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    Node *p, *q;

    if (head == 0)
        head = temp;                  // 첫 노드가 만들어지는 경우
    else if (temp->data < head->data) // 노드 앞에 노드가 삽입될 경우
    {
        temp->next = head;
        head = temp;
    }
    else // 연결리스트의 가운데에 노드가 삽입되는 경우
    {
        p = head;
        while ((p != 0) && (p->data < temp->data))
        {
            q = p;
            p = p->next;
        }
        if (p != 0)
        {
            temp->next = p;
            q->next = temp;
        }
    }
}

void List::append(int data)
{
    Node *temp = new Node();

    temp->data = data;
    temp->next = 0;
}

void List::deleteNode(int num)
{
    Node *p, *q;

    if (head->data == num) // head 삭제
    {
        p = head;
        head = head->next;
        delete p;
    }
    else
    {
        p = head;
        while (p != 0 && p->data != num)
        {
            q = p;
            p = p->next;
        }
        if (p != 0)
        {
            q->next = p->next;
            delete p;
        }
        else
        {
            std::cout << num << "is not in the list" << std::endl;
        }
    }
}

void List::traverseList()
{
    Node *p;

    if (!isEmpty())
    {
        p = head;
        while (p)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "List is empty!" << std::endl;
}

void List::searchList(int num)
{
    Node *p;

    if (head != 0)
    {
        p = head;
        while (p != 0 && p->data != num)
        {
            p = p->next;
        }
        if (p)
            std::cout << p->data << " is found." << std::endl;
        else
            std::cout << num << " is not in the list" << std::endl;
    }
    else
        std::cout << "List is empty" << std::endl;
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