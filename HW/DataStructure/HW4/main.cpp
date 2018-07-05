#include <iostream>
#include <cstdlib>
#include <vector>
#include "Graph.h"
#include "queue.h"

using namespace std;

int main() {
    vector < vector< int > > dataArray = {{0, 1, 1, 0, 0, 0, 0, 0},
                                      {1, 0, 0, 1, 1, 0, 0, 0},
                                      {1, 0, 0, 0, 0, 1, 1, 0},
                                      {0, 1, 0, 0, 0, 0, 0, 1},
                                      {0, 1, 0, 0, 0, 0, 0, 1},
                                      {0, 0, 1, 0, 0, 0, 0, 1},
                                      {0, 0, 1, 0, 0, 0, 0, 1},
                                      {0, 0, 0, 1, 1, 1, 1, 0}};
    Graph g(8, dataArray);
    Queue queue;
    g.print_matrix(); // Adjacent Matrix 출력
    g.settingVisited(); // 방문 검사 배열 false 로 초기화
    g.BFS(0, &queue);  // 첫 번째 노드 0부터 시작
    return 0;
}
