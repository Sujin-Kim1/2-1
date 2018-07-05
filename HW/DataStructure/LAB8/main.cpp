#include <iostream>
#include <cstdlib>
#include <fstream>
#include "SLL.h"
#include "Graph.h"
#include "queue.h"

using namespace std;

int main()
{
    Graph g1;
    Queue q1;
    /* V0: 1->2 V1: 0-> 2->3 V2: 0->1->5 V3: 1->4->5 V4: 3->5 V5: 2->3->4 */
    const int numList = 6;
    const int maxNum = 4;
    int dataArray[numList][maxNum] = {
        {0, 1, 2, -1},
        {1, 0, 2, 3},
        {2, 0, 1, 5},
        {3, 1, 4, 5},
        {4, 3, 5, -1},
        {5, 2, 3, 4}};

    for (int i = 0; i < numList; i++)
    {
        List *temp = new List();
        for (int j = 0; j < maxNum; j++)
        {
            if (dataArray[i][j] == -1)
                continue;
            temp->insertNode(dataArray[i][j]);
            std::cout << dataArray[i][j] << " ";
        }
        g1.insert(temp);
        std::cout << std::endl;
    }

    g1.DFS(1);
    g1.settingVisited();
    g1.BFS(1, &q1);

    return 0;
}
