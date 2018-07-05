#pragma once

class Node
{
  private:
    int data;
    Node *next;
    Node *prev;
    Node(int data);
    friend class List;
};

class List
{
  private:
    Node *head;
  public:
    List();
    ~List();
    void insertFirst(int data);
    void insertLast(int data);
    void insertList(int);
    void insert_before(int index, int data);
    void insert_after(int index, int data);    
    void deleteList(int);
    void forwardList();
    void backwardList();
    void searchList(int);
    bool isEmpty();
    void locateCurrent(int Nth);
    int listLength();
    void deleteNth(int Nth);    
};