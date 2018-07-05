#include <iostream>
#include <cstdlib>
#include <vector>
#include "Graph.h"

using namespace std;

int main() {
    vector<vector<int> > costArray = {{0, 6, 1, 5, 0, 0},
                                      {6, 0, 4, 0, 3, 0},
                                      {1, 4, 0, 5, 6, 5},
                                      {5, 0, 5, 0, 0, 2},
                                      {0, 3, 6, 0, 0, 6},
                                      {0, 0, 5, 2, 6, 0}};
    Graph g(6 , costArray);
    g.print_weight(); // Adjacent Matrix 출력
    g.Prim();
    g.ModifiedPrim();
    return 0;
}
