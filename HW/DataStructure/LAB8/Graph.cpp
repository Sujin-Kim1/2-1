#include <iostream>
#include <fstream>
#include <cstdlib>
#include <deque>
#include "SLL.h"
#include "Graph.h"
#include "queue.h"

using namespace std;

void Graph::insert(List *li)
{
    if (!isFull())
    {
        graph[++size] = li->head;
        visited[size] = false;
    }
}

bool Graph::isEmpty()
{
    return size == 0;
}

bool Graph::isFull()
{
    return size == SIZE;
}

void Graph::DFS(int v)
{
    Node *w;
    visited[v] = true;
    cout << graph[v]->data << " ";
    for (w = graph[v]; w != 0; w = w->next)
    {
        int index;
        for (int i = 1; i <= size; i++)
        {
             if (graph[i]->data == w->data)
             {
                 index = i;
                 break;
             }
        }
        if (!visited[index])
        {
            DFS(index);
        }
    }
}

void Graph::BFS(int v, Queue *q)
{
    Node *p;
    visited[v] = true;
    q -> ENQUE(v);
    cout << v << " ";

    while (!(q->QEmpty())) {
        v = q->DEQUE();
        for (p = graph[v]; p; p = p->next) {
            int index;
            for (int i = 1; i <= size; i++) {
                if (graph[i]->data == p->data) {
                    index = i;
                    break;
                }
            }
            if (!visited[index]) {
                q->ENQUE(index);
                visited[index] = true;
                cout << p->data << ' ';
            }
        }
    }
}

void Graph::settingVisited()
{
    for (int i = 1; i <= size; i++)
    {
        visited[i] = false;
    }
}