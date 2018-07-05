#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Graph.h"

using namespace std;

Graph::Graph(int size, vector<vector<int> > AdjacentMatrix)
        : size(size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (AdjacentMatrix[i - 1][j - 1] == 0)
                graphMatrix[i][j] = MAX_INT;
            else
                graphMatrix[i][j] = AdjacentMatrix[i - 1][j - 1];
        }
        visited[i - 1] = false;
    }
}

bool Graph::isEmpty() const {
    return size == 0;
}

bool Graph::isFull() const {
    return size == MAX_SIZE;
}

void Graph::print_weight() const {
    cout << "*****  Prim *****" << endl;
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            if (i == 0) {
                if (j != 0) {
                    cout << 'v' << j << '\t';
                }
                else {
                    cout << '\t';
                }
            }
            else if (j == 0) {
                cout << 'v' << i << '\t';
            }
            else {
                cout << graphMatrix[i][j] << '\t';
            }
        }
        cout << endl;
    }
}

void Graph::Prim() {
    cout << "*****  Wighted Matrix *****" << endl;
    int weight = Prim_Implementation(1);
    cout << endl;
    cout << "Weight : " << weight << endl;
    for (int i = 1; i <= size; i++) {
        visited[i] = false;
    }
}

void Graph::ModifiedPrim() {
    cout << "*****  Modified Prim *****" << endl;
    int weight = ModifiedPrim_Implementation(1);
    cout << endl;
    cout << "Weight : " << weight << endl;
    for (int i = 1; i <= size; i++) {
        visited[i] = false;
    }
}

int Graph::Prim_Implementation(int v) {  // v = 1
    int weight = 0;
    const int SIZE = size;
    vector<vector<int> > T;
    int lowcost[SIZE];  // 6
    while (T.size() < SIZE - 1) {
        visited[v] = true;
        for (int i = 1; i <= SIZE; i++) {
            lowcost[i] = graphMatrix[v][i];
        }
        int u;
        int min = MAX_INT;
        for (int i = 1; i <= SIZE; i++) {
            if (!visited[i]) {
                if (lowcost[i] < min) {
                    min = lowcost[i];
                    u = i;
                }
            }
        }
        T.push_back({v, u});
        weight += lowcost[u];
        v = u;
    }
    cout << "Output : ";
    for (auto edge : T) {
        cout << edge[0] << ", " << edge[1] << " / ";
    }
    return weight;
}

int Graph::ModifiedPrim_Implementation(int v) {
    int weight = 0;
    const int SIZE = size;
    vector<vector<int> > T;
    vertex lowcost[SIZE];
    for (int i = 1; i <= SIZE; i++) {
        lowcost[i].cost = graphMatrix[v][i];
        lowcost[i].parentVertex = v;
    }
    while (T.size() < SIZE - 1) {
        visited[v] = true;
        int u;
        int min = MAX_INT;
        for (int i = 1; i <= SIZE; i++) {
            if (!visited[i]) {
                if (lowcost[i].cost < min) {
                    min = lowcost[i].cost;
                    u = i;  // min 값의 index
                }
            }
        }
        v = lowcost[u].parentVertex;
        T.push_back({v, u});
        for (int i = 1; i <= SIZE; i++) {
            if (graphMatrix[u][i] != MAX_INT && graphMatrix[u][i] < lowcost[i].cost) {
                lowcost[i].cost = graphMatrix[u][i];
                lowcost[i].parentVertex = u;
            }
        }
        weight += lowcost[u].cost;
        v = u;
    }
    cout << "Output: ";
    for (auto edge : T) {
        cout << edge[0] << " , " << edge[1] << " / ";
    }
    return weight;
}
