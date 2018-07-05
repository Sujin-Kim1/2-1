#pragma once
#include <string>

class Node
{
  private:
    int data;
    Node* next;

  public:
    Node();
    Node(int key);
    friend class List;
    friend class Graph;
};

class List
{
  public:
    Node *head;
    List();
    ~List();
    void insertNode(int);
    bool isEmpty();
};