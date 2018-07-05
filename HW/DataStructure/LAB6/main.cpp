#include <iostream>
#include "buildingTree.h"

using namespace std;

int main()
{
    char *data1 = "8+9-2*3;
    Tree tree;
    tree.buildTree(data1);
    cout << "Inorder: ";
    tree.InorderTraverse(tree.getRoot());
    cout << endl;
    cout << "Postorder: ";
    tree.PostorderTraverse(tree.getRoot());    
    cout << endl;
    cout << "Preorder: ";
    tree.PreorderTraverse(tree.getRoot());
    cout << endl;
    cout << "Evaluation: " << tree.evalTree(tree.getRoot()) << endl;
    cout << endl;

    
    char *data2 = "a+b*c-d";
    /*
     *                -
     *          *           d
     *      +                   c
     * a                            b*/
    Tree tree1;
    tree1.buildTree(data2);    
    cout << "Inorder: ";  //
    tree1.InorderTraverse(tree1.getRoot());
    cout << endl;
    cout << "Postorder: "; 
    tree1.PostorderTraverse(tree1.getRoot());    
    cout << endl;
    cout << "Preorder: ";
    tree1.PreorderTraverse(tree1.getRoot());
    cout << endl;
    
}