#include <iostream>
#include <climits>
#include "ShortestPath.h"

int main() {
    ShortestPath s;
    s.initCostMatrix();
    s.settingCost(0, 1, 20);
    s.settingCost(0, 2, 15);
    s.settingCost(1, 4, 10);
    s.settingCost(1, 5, 30);
    s.settingCost(2, 1, 4);
    s.settingCost(2, 5, 10);
    s.settingCost(4, 3, 15);
    s.settingCost(5, 3, 4);
    s.settingCost(5, 4, 10);

    s.print();
    s.shortestPath(0);
    return 0;
}