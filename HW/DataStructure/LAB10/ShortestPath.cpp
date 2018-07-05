#include "ShortestPath.h"
#include <iostream>

void ShortestPath::initCostMatrix() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
//            if (i == j)
//                cost[i][j] = 0;
//            else
//                cost[i][j] = 100;
            cost[i][j] = 100;
        }
    }
}

void ShortestPath::shortestPath(int v) {
    int u;
    for (int i = 0; i < MAX; i++) {
        found[i] = false;  // found all False
        distance[i] = cost[v][i];  // initial value assign
    }

    found[v] = true; // start vertex mark
    distance[v] = 0;  // start vertex 0

    for (int i = 0; i < MAX; i++) {
        u = choose(); // find min value node
        if (u == -1)
            continue;
        found[u] = true;  // mark the node

        for (int d = 0; d < MAX; d++) {
            std::cout << distance[d] << " ";  // print distance
        }
        std::cout << "(Selected Node : " << u << ")" << std::endl;

        for (int j = 0; j < MAX; j++) { // and replace if revised value
            if (!found[j]) { // if not marked
                if (distance[u] + cost[u][j] < distance[j]) // is smaller than original
                    distance[j] = distance[u] + cost[u][j]; // value
            }
        }

    }
}

int ShortestPath::choose() {
    int min = 9999, minNode = -1;
    for (int i = 0; i < MAX; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minNode = i;
        }
    }
    return minNode;
}

void ShortestPath::settingCost(int row, int col, int val) {
    cost[row][col] = val;
}

void ShortestPath::print() const {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (cost[i][j] == 9999)
                std::cout << " . ";
            else
                std::cout << cost[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
