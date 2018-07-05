/* **********************************************************************
 * Name : 김수진
 * Student ID : 20171596
 * Program ID : HW4
 * Description : BFS 구현, Adjacent Matrix 출력, Queue (initialization,
 * addQ, deleteQ)
 * ALgorithm
 *      [Graph]
 *      - Graph initialization : 사용자가 vertex 의 개수와 그래프를 입력하면,
 *        vertex 의 개수 즉 size 만큼 이중 for loop 을 돌면서 graph 를 채운다.
 *
 *      - BFS : root 부터 마지막 level 에 이르기까지 순차적으로 각각의 인접 노드를
 *      찾는다. 방법은 다음과 같다.
 *         1. 먼저 인접한 노드 중에서 방문하지 않았던 노드를 찾는다.
 *            그 노드를 반복했다는 표시를 한 후, queue 에 삽입한다.
 *         2. 만약 인접한 노드가 없을 경우, queue 에서 맨 처음 노드를 제거한다.
 *         3. 1과 2를 queue 가 비어있을 때까지 반복한다.
 *
 *      - print : size 만큼 이중 for loop 을 돌면서 graph 원소를 각각 출력한다.
 *
 *      [Queue] => FIFO (First-In-First-Out)
 *      - initialization : 아무 노드도 들어가지 않았으므로 front == rear == -1
 *      인 empty 상태의 queue 를 초기화한다.
 *
 *      - ENQUE : queue 가 full 이 아니면 queue 에 rear 를 계속 증가시키면서
 *      원소를 삽입한다.
 *
 *      - DEQUE : queue 가 empty 가 아니면 front 를 증가시켜 반환한다. 가장
 *      먼저 삽입된 노드가 먼저 제거된다.
 *
 *  Variables
 *      [Graph]
 *      - Graph(int, vector <vector<int>>) : 생성자. graph 의 크기와 데이터
 *      를 초기화한다.
 *      - isEmpty() const, isFull() const : 그래프의 empty, full 여부 판단.
 *      - BFS : graph 의 각 level 마다 인접된 노드를 찾아 출력한다. queue 와
 *      노드 방문 여부를 저장하는 visited 배열을 이용한다.
 *      - settingVisited() : visited 배열을 false 로 초기화 한다.
 *      - print_matrix() const : 그래프 데이터를 출력한다.
 *      - visited[MAX_SIZE] : 노드를 반복했는지 안했는지 저장하는 bool 형의 배열.
 *      - graph[MAX_SIZE][MAX_SIZE] : 데이터를 저장하는 그래프 배열.
 *      - size : 사용자로부터 입력받은 배열의 사이즈를 저장하는 멤버 변수.
 *
 *      [Queue]
 *      - Queue() : front, rear 를 -1로 초기화 하는 생성자.
 *      - ENQUE(int item) : item 을 queue 에 삽입하는 함수.
 *      - DEQUE() : 가장 최근의 node 를 반환하는 함수.
 *      - QEmpty() const, QFull() const : queue 의 empty / full 여부 판단.
 *      - queue[MAX_QUEUE_SIZE] : MAX_QUEUE_SIZE 크기의 queue 배열.
 *      - front, rear : 가장 먼저 삽입된 노드와 마지막에 삽입된 노드의 위치를 가리킴.
 ************************************************************************ */

#pragma once

#include <vector>
#include "queue.h"

#define MAX_SIZE 100

using namespace std;

class Graph {
public:
    Graph(int, vector < vector < int > >);

    bool isEmpty() const;

    bool isFull() const;

    void BFS(int, Queue *);

    void settingVisited();

    void print_matrix() const;

private:
    bool visited[MAX_SIZE];
    int graph[MAX_SIZE][MAX_SIZE];
    int size;
};