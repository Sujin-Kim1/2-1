#pragma once
#include "SLL.h"
#include "Queue.h"

#define MAX_SIZE 100

class Graph {
private:
    Node *headnodes[MAX_SIZE];
    int n;
    bool visited[MAX_SIZE];
public:
    Graph() { n = 0; };

    int GetNum() const;

    bool IsEmpty();

    bool IsFull();

    void Insert(List *l);

    void Print();

    void DFS(int v);

    void BFS(int v, Queue *q);

    void SetVisitedFalse();
};