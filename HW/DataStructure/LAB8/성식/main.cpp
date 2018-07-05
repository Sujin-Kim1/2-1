#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Graph.h"
#include "SLL.h"
#include "Queue.h"

using namespace std;

int main() {
    ifstream infile("input.txt");
    if (infile.fail()) {
        cerr << "Input file opening failed" << endl;
        exit(1);
    }
    Graph g;
    int num_of_vertex;
    infile >> num_of_vertex;
    for (int i = 0; i < num_of_vertex; i++) {
        int size, num;
        infile >> size;
        List *temp = new List();
        for (int j = 0; j < size; j++) {
            infile >> num;
            cout << num << " ";            
            temp->Insert_back(num);
        }
        cout << endl;
        g.Insert(temp);
    }
    cout << endl;    
    g.DFS(1);
    cout << endl;
    g.SetVisitedFalse();
    Queue q;
    g.BFS(1, &q);
}