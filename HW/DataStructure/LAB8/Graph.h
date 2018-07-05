#pragma once
#include "SLL.h"
#include "queue.h"
#define SIZE 100

class Graph
{
public:
  Graph() : size(0) {};
  void insert(List *);
  void DFS(int);
  void BFS(int, Queue *);
  void initializeQ(int);
  void settingVisited();
  bool isEmpty();
  bool isFull();

private:
  bool visited[SIZE];
  Node *graph[SIZE];
  int size;
};