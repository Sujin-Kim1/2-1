#pragma once

class Node
{
  private:
    int data;
    Node *next;
    friend class List;
};

class List
{
  private:
    Node *head;

  public:
    List();
    bool isEmpty();
    void insertNode(int);
    void append(int);
    void deleteNode(int);
    void traverseList();
    void searchList(int);
    ~List();
};