#include <iostream>
#include "SLL.h"
#include "Graph.h"
#include "Queue.h"

using namespace std;

int Graph::GetNum() const {
    return n;
}

bool Graph::IsEmpty() {
    return n == 0;
}

bool Graph::IsFull() {
    return n == MAX_SIZE;
}

void Graph::Insert(List *l) {
    if (IsFull()) {
        return;
    }
    headnodes[++n] = l->head;
    visited[n] = false;
}

void Graph::Print() {
    for (int i = 1; i <= n; i++) {
        cout << headnodes[i]->data << ' ';
    }
    cout << endl;
}

void Graph::DFS(int v) {
    Node *w;
    visited[v] = true;
    cout << headnodes[v]->data << ' ';
    for (w = headnodes[v]; w != 0; w = w->next) {
        int index;
        for (int i = 1; i <= n; i++) {
            if (headnodes[i]->data == w->data) {
                index = i;
                break;
            }
        }
        if (!visited[index]) {
            DFS(index);
        }
    }
}

void Graph::BFS(int v, Queue *q) {
    Node *p;
    visited[v] = true;
    q->EnQueue(v);
    cout << headnodes[v]->data << ' ';
    while (!(q->IsEmpty())) {
        v = q->DeQueue();
        for (p = headnodes[v]; p != 0; p = p->next) {
            int index;
            for (int i = 1; i <= n; i++) {
                if (headnodes[i]->data == p->data) {
                    index = i;
                    break;
                }
            }
            if (!visited[index]) {
                q->EnQueue(index);
                visited[index] = true;
                cout << p->data << ' ';
            }
        }
    }
}

void Graph::SetVisitedFalse() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}