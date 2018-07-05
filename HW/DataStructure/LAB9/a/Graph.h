#pragma once

#include <vector>
#define MAX_INT 100
#define MAX_SIZE 10

using namespace std;

struct vertex {
    int cost;
    int parentVertex;
};

class Graph {
public:
    Graph(int, vector < vector < int > >);

    bool isEmpty() const;

    bool isFull() const;

    void print_weight() const;

    void Prim();

    void ModifiedPrim();

    int Prim_Implementation(int v);

    int ModifiedPrim_Implementation(int v);


private:
    bool visited[MAX_SIZE];
    int graphMatrix[MAX_SIZE][MAX_SIZE];
    int size;
};