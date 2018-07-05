#include <iostream>
#include "BST.h"

Node::Node()
{
}

/* **********************************************************************
 * constructor : Node(int) 
 * description : 생성자. 인자로 받은 int 값이 Node의 data값이 되며,
 *              *left, *right를 NULL값으로 초기화한다.
************************************************************************ */

Node::Node(int key)
    : data(key), left(NULL), right(NULL)
{
}

/* **********************************************************************
 * constructor : BST() 
 * description : 생성자. root를 NULL값으로 초기화한다.
************************************************************************ */

BST::BST()
    : root(NULL)
{
}

/* **********************************************************************
 * destructor : ~BST() 
 * description : 소멸자. 트리의 데이터를 지운다.
 * variables : *t - root를 임시적으로 가리키기 위한 Node.
 *                  root가 이동하면 t를 지운다.
************************************************************************ */

BST::~BST()
{
    Node *t;
    while (root != NULL)
    {
        t = root;
        root = root->left;
        root = root->right;
        delete t;
    }
}

/* **********************************************************************
 * funtion : insert(Node *ptr, int key)
 * description : Node를 삽입한다.
 * variables : key - 사용자가 key를 입력하면 Node ptr의 data와 비교하여 적절한
 *                   위치에 삽입되도록 하는 데 필요하다.
************************************************************************ */

Node *BST::insert(Node *ptr, int key)
{
    if (ptr == NULL)
    {
        ptr = new Node(key);
        if (root == NULL)
            root = ptr;
    }
    /* key가 ptr의 data보다 작은 경우 왼쪽 하위 트리로 이동 */    
    else if (key < ptr->data) 
        ptr->left = insert(ptr->left, key);
    /* key가 ptr의 data보다 큰 경우 오른쪽 하위 트리로 이동 */            
    else if (key > ptr->data)
        ptr->right = insert(ptr->right, key);
    return ptr;
}

/* **********************************************************************
 * funtion : del(Node *ptr, int key)
 * description : Node를 삭제한다.
 * variables : 
 *      key - 사용자가 key를 입력하면 *ptr의 data와 비교하며 key와
 *            data가 같은 Node를 찾는 데 사용된다. 
 *      *p - *ptr을 가리키기 위한 Node 포인터. ptr이 이동하면 p를 지운다.
 *      *temp : 오른쪽 하위트리의 최솟값을 나타내는 Node 포인터. ptr의 
 *              data를 temp의 data 값으로 설정한다. 
************************************************************************ */

Node *BST::del(Node *ptr, int key)
{
    if (ptr != NULL)
    {
        if (key < ptr->data)
            ptr->left = del(ptr->left, key); /* move to the node */
        else if (key > ptr->data)            /* arrived at the node */
            ptr->right = del(ptr->right, key);
        else if (ptr->left == NULL && ptr->right == NULL)
            ptr = NULL;             /* leaf */
        else if (ptr->left == NULL) /* rightchild only */
        {
            Node *p = ptr;
            ptr = ptr->right;
            delete (p);
        }
        else if (ptr->right == NULL) /* leftchild only */
        {
            Node *p = ptr;
            ptr = ptr->left;
            delete (p);
        }
        else /* both child exists */
        {
            Node *temp = findMin(ptr->right);
            ptr->data = temp->data;
            ptr->right = del(ptr->right, ptr->data);
        }
    }
    return ptr;
}

/* **********************************************************************
 * funtion : findMin(Node *ptr)
 * description : 오른쪽 하위 트리의 최솟값을 선택한다.
 * variables : *ptr - 현재 트리의 Node를 가리키는 포인터. ptr->left가 NULL이
 *                    될 때까지 반복한다.
************************************************************************ */

Node *BST::findMin(Node *ptr) /* right subtree에서 가장 작은 것 선택 */
{
    if (ptr->left == NULL)
        return ptr;
    return findMin(ptr->left);
}

/* **********************************************************************
 * funtion : search(Node *ptr, int key)
 * description : Node의 data 중 key와 동일한 Node가 존재하는지 찾는 함수
 * variables : *ptr - 현재 트리의 Node를 가리키는 포인터. key와 ptr의 데이터
 *                    를 비교하여 key가 작으면 왼쪽 하위 트리를, 크면 오른쪽
 *                    하위 트리를 재귀적으로 검사함. key와 data 값이 같으면
 *                     ptr을 return 하고, 찾지 못하면 NULL을 return한다.
************************************************************************ */

Node *BST::search(Node *ptr, int key)
{
    if (ptr == NULL) /* search unsuccessful */
    {
        return NULL;
    }
    else
    {
        if (key == ptr->data)
            return ptr;
        else if (key < ptr->data)
            ptr = search(ptr->left, key); /* search leftsubtree */
        else if (key > ptr->data)
            ptr = search(ptr->right, key); /* search rightsubtree */
    }
    return ptr;
}

/* **********************************************************************
 * funtion : drawTree()
 * description : Node가 root, level이 1인 drawBSTtree함수를 호출한다.
************************************************************************ */

void BST::drawTree() { drawBSTree(root, 1); }

/* **********************************************************************
 * funtion : drawBSTtree(Node *p, int level)
 * description : BST를 출력한다.
 * variables : level - 트리의 level을 나타냄. level - 1만큼 공백을 추가하는
 *                     데 사용된다.
************************************************************************ */

void BST::drawBSTree(Node *p, int level)
{
    if (p != 0 && level <= 7)
    {
        drawBSTree(p->right, level + 1);
        for (int i = 1; i <= (level - 1); i++)
            std::cout << " ";
        std::cout << p->data;
        if (p->left != 0 && p->right != 0)
            std::cout << " <" << std::endl;
        else if (p->right != 0)
            std::cout << " /" << std::endl;
        else if (p->left != 0)
            std::cout << " \\" << std::endl;
        else
            std::cout << std::endl;
        drawBSTree(p->left, level + 1);    
    }
}

/* **********************************************************************
 * funtion : getRoot() const
 * description : root를 반환한다.
************************************************************************ */

Node *BST::getRoot() const { return root; }