#include <iostream>
#include <cstdlib>
#include "Graph.h"
#include "queue.h"

using namespace std;

/* **********************************************************************
 * constructor :  Graph(int size, vector <vector<int>> inputMatrix)
 * description : 생성자. graph 의 크기와 데이터를 초기화 한다.
 * ************************************************************************ */

Graph::Graph(int size, vector < vector< int > > inputMatrix)
        : size(size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            graph[i][j] = inputMatrix[i][j];
        }
    }
}

/* **********************************************************************
 * function : isEmpty() const
 * description : 그래프가 비어있는지 확인한다.
 * ************************************************************************ */

bool Graph::isEmpty() const {
    return size == 0;
}

/* **********************************************************************
 * function : isFull() const
 * description : 그래프가 MAX_SIZE 와 같은지 확인한다.
 * ************************************************************************ */

bool Graph::isFull() const {
    return size == MAX_SIZE;
}

/* **********************************************************************
 * function : BFS(int v, Queue *q)
 * description : graph 의 각 level 마다 인접된 노드를 찾아 출력한다.
 * variables
 *      - visited[] - 노드 방문 여부를 저장하는 배열
 *      - v : vertex
 *      - q : Queue 객체
 * ************************************************************************ */

void Graph::BFS(int v, Queue *q) {
    cout << "*****  Breadth First Search (BFS)" << endl;
    visited[v] = true;
    q->ENQUE(v);  // starting node
    cout << "v" << v << " "; // print starting node

    while (!(q->QEmpty())) {
        v = q->DEQUE(); // there isn't adjacent node
        for (int i = v; i < size; i++) { // all of adjacent nodes
            if (!visited[i]) {  // if not visited
                q->ENQUE(i);
                visited[i] = true;
                cout << "v" << i << ' '; // print
            }
        }
    }
}

void Graph::Implement_BFS(int v, Queue *q) {
    visited[v] = true;
    q->EnQueue(v);
    cout << 'v' << v << ' ';
    while (!(q->IsEmpty())) {
        v = q->DeQueue();
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graphMatrix[v][i]) {
                q->EnQueue(i);
                visited[i] = true;
                cout << 'v' << i << ' ';
            }
        }
    }
}

/* **********************************************************************
 * function : settingVisited()
 * description : visited 배열을 false 로 초기화 한다.
 * ************************************************************************ */

void Graph::settingVisited() {
    for (int i = 1; i <= size; i++) {
        visited[i] = false;
    }
}

/* **********************************************************************
 * function : print_matrix() const
 * description : 그래프 데이터를 출력한다.
 * ************************************************************************ */

void Graph::print_matrix() const {
    cout << "*****  Adjacent Matrix" << endl;
    cout << "    ";
    for (int i = 0; i < size; i++) {
        cout << "v" << i << " "; // column header
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "v" << i << "  "; // row header
        for (int j = 0; j < size; j++) {
            cout << graph[i][j] << "  "; // nodes
        }
        cout << endl;
    }
}
