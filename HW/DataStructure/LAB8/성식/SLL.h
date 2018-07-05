#pragma once

class Node {
private:
    int data;
    Node *next;

public:
    Node(int num) {
        data = num;
        next = 0;
    }

    friend class List;
    friend class Graph;
};

class List {
public:
    Node *head;

    List();

    void Insert_back(int val);

    void Delete(int val);

    bool IsEmpty();

    void TraverseList();

    void SearchList(int val);

    ~List();
};