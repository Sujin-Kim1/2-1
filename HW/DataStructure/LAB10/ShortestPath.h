#ifndef LAB10_SHORTESTPATH_H
#define LAB10_SHORTESTPATH_H

#define MAX 6

#include <iostream>


class ShortestPath {
public:
    void initCostMatrix();  // initialize
    void shortestPath(int v);
    int choose();
    void settingCost(int row, int col, int val);
    void print() const;

private:
    int cost[MAX][MAX];
    bool found[MAX];
    int distance[MAX];
};


#endif //LAB10_SHORTESTPATH_H
