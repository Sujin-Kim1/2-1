  /* **********************************************************************
 * Name : 김수진
 * Student ID : 20171596
 * Program ID : HW3
 * Description : BST 구현 및 insert, delete, search, print를 테스트
 * Algorithm 
 *      - insert : BST는 왼쪽 하위 트리에는 root의 값보다 작은 값이 저장되고,
 *                오른쪽 하위 트리에는 root의 값보다 큰 값이 저장된다. 그래서
 *                입력된 값 key와 root의 data를 비교하여 key < data일 땐 왼쪽
 *                하위 트리로, key > data일 때는 오른쪽 하위 트리로 이동한다.
 *                입력된 데이터가 NULL 즉, leaf Node가 될 때까지 재귀 함수를
 *                이용하여 움직인다. 만약 root가 존재하지 않으면, 입력된 값을 
 *                root로 설정한다.
 *                 
 *      - del : 재귀 함수로 입력된 key의 값과 data값이 같은 Node를 찾아 이동한다.
 *              del은 다음과 같이 3가지로 나눌 수 있다. 
 *              1) left node
 *                부모 Node의 left, right 포인터를 NULL로 만들어서 자식 Node를
 *                지운다.
 *              2) nonleaf node with one child
 *                 Node가 A, B, C 이렇게 있으면 A의 포인터가 C를 가리키도록 
 *                만들면 된다. 만약 오른쪽 자식 Node만 존재할 경우, 자기 자신을
 *                가리키는 temp Node를 하나 더 만들고, 자신은 오른쪽 Node로 이동
 *                한 뒤에 temp Node를 지운다. 만약 왼쪽 자식 Node만 존재할 경우,
 *                왼쪽 Node로 이동한 후 temp Node를 지운다.
 *             3) nonleaf node with two children
 *                오른쪽 하위 트리에 있는 최솟값과 교환하는 방식이다. findMin으로
 *                오른쪽 하위 트리의 최솟값을 갖는 Node와 위치를 바꾸고, 입력 값의
 *                오른쪽부터 del함수를 반복하며 양쪽 자식 Node를 가지지 않을 때 
 *                멈춘다.
 * 
 *      - findMin : BTS는 왼쪽 하위 트리는 작은 값이, 오른쪽 하위 트리에는 큰 값이
 *                  저장되는 구조이므로, 왼쪽 하위 트리가 NULL인 Node가 최솟값이다.
 *                  재귀함수를 사용해 ptr->left가 NULL이 될 때까지 반복한다.
 * 
 *      - search : 현재 Node 값보다 작으면 왼쪽, 크면 오른쪽으로 재귀 함수를 써서 
 *                 이동한 후, 입력 값 ptr의 data가 트리에 있으면 ptr을 return한다.
 *                 만약 찾지 못했을 경우, ptr을 NULL로 설정한 후 return한다.
 * 
 *      - drawBSTtree : level이 증가할 때마다 " "를 추가해 상위 트리와 하위 트리의
 *                      data 값을 보기 좋게 위치시킨다. 양쪽의 하위 트리가 0이 
 *                      아니면 <, 오른쪽의 하위 트리가 0이 아니면 /, 왼쪽의 하위 
 *                      트리가 0이 아니면 \를 추가하여 data 값과 함께 출력한다.
 *                      재귀 함수를 이용해 level이 7이하일 때까지 반복하면서 level
 *                      에 +1을 해준다.
 * 
 * 
 *      - main : while문을 사용하여 계속해서 입력을 받도록 하였다. switch 구문으로
 *               사용자가 입력한 값에 따라 insert, del 등의 함수가 실행되도록 한다.
 *               만약 5를 입력하면, std::exit(1)로 while문을 빠져나온다.
 * 
 * Variables : 
 *      - data : Node의 data값을 나타낸다.
 *      - *left, *right : Node의 왼쪽, 오른쪽 포인터
 *      - *root : 트리의 시작점인 root 값
 *      - Node() : 생성자
 *      - Node(int) : 생성자. 인자로 받은 int 값이 Node의 data값이 되며,
 *                    *left, *right를 NULL값으로 초기화한다.
 *      - BST() : 생성자. root 값을 NULL로 초기화한다.
 *      - ~BST() : 소멸자. root가 NULL이 될 때까지 Node들을 지운다.
 *      - insert(Node *, int) : Node를 삽입한다.
 *      - del(Node *, int) : int 값을 트리에서 삭제한다.
 *      - findMin(Node *) : 오른쪽 하위 트리의 최솟값을 찾는다.
 *      - search(Node *, int) : int 값이 트리에 있으면 Node *을, 없으면 NULL을 반환함.
 *      - drawTree(), drawBSTree(Node *, int) : 그래프를 출력한다.
 *      - getRoot() const : root 값을 반환한다.
 *      - main() : insert, delete, search, print를 테스트한다.
************************************************************************ */

#pragma once

class Node
{
  private:
    int data;
    Node *left;
    Node *right;
    Node();
    Node(int);
    friend class BST;
};

class BST
{
  private:
    Node *root;

  public:
    BST();
    ~BST();
    Node *insert(Node *, int);
    Node *del(Node *, int);
    Node *findMin(Node *);    
    Node *search(Node *, int);
    void drawTree();
    void drawBSTree(Node *, int);
    Node *getRoot() const;
};