#include <iostream>
#include <cstdlib>
#include "BST.h"

/* **********************************************************************
 * funtion : main
 * description : insert, delete, search, print를 테스트한다.
 * variables : 
 *      choice, key - 선택지를 저장하기 위한 변수
 *      bst - class BST의 객체
 *      *temp - search 결과로 반환한 Node를 저장하기 위한 변수
************************************************************************ */

int main()
{
    int choice, key;
    BST bst;
    Node *temp;
    while (1)
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "         Menu" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "1.Insert" << std::endl;
        std::cout << "2.Delete" << std::endl;
        std::cout << "3.Search" << std::endl;
        std::cout << "4.Print" << std::endl;
        std::cout << "5.Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1: /* Insert */
            std::cout << "Enter number to insert: ";
            std::cin >> key;
            bst.insert(bst.getRoot(), key);
            break;
        case 2: /* Delete */
            if (bst.getRoot() != NULL)
            {
                std::cout << "Enter number to delete: ";
                std::cin >> key;
                bst.del(bst.getRoot(), key);
                break;
            }
            std::cout << "Tree is empty" << std::endl; /* when root is NULL */
            break;
        case 3: /* Search */
            if (bst.getRoot() != NULL)
            {
                std::cout << "Enter number to search: ";
                std::cin >> key;
                temp = bst.search(bst.getRoot(), key);
                if (temp == NULL)
                    std::cout << "NOT found" << std::endl;
                else
                    std::cout << "found" << std::endl;
                break;
            }
            else
            {
                std::cout << "Tree is empty" << std::endl; /* when root is NULL */
                break;
            }
        case 4: /* Print */
            bst.drawTree();
            break;
        case 5: /* Quit */
            std::exit(1);
        default: /* 1~5 외의 다른 숫자가 들어왔을 때 */
            std::cout << "Wrong number" << std::endl;
        }
    }
}