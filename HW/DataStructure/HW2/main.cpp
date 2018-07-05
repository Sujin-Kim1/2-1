/**********************************************************************************************************
 * Name : 김수진
 * Student ID : 20171596
 * Program ID : HW2
 * Description : To manipulate an ordered list and variant records
 * Algorithm : Q1 - Create and print a list of student names (ascending alphabetical order).
 *                  (insert by name) Let's call the input data as temp. 
 *                  First, store the head in the variable 'p'.
 *                  While the name of p precedes the name of temp (Student's name), 
 *                  repeat 'q = p; p = p->next'. Then do 'temp->next = p; q->next = temp;'.
 *                  In this way, we insert data into the list in name order.
 *                  (Output) While the list isn't empty, p = head; print data; p = p->next;
 *
 *             Q2 - In the list created in 1), output only those who received grade "A" grades.              
 *                  (search) store the head in the variable 'p'. 
 *                  While the p isn't 0, if p's grade is 'A', print output then p = p->next; 
 * 
 *             Q3 - Combine the "data2" file and "data1" into a list, and print only CS students.
 *                  (insert by name) Read the "data1.dat" and "data2.dat" files as you did in Q1 
 *                  and insert them into the list in the order of name.
 *                  (search) store the head in the variable 'p'. 
 *                  While the p isn't 0, if p's major is "CS", print output then p = p->next;
 * 
 * Variables :      
 *          ~Link() : A function that returns each node of the linked list to the system 
 *          void insertNode(char, int, string, char) : A function to insert a node into a linked list
 *          void deleteNode(char) : A function to delete a node in a linked list
 *          bool isEmpty() : A function that check for empty link lists
 *          void traverse() : Output contents of nodes of linked list
 *          void search(char) : A function to find data with specific grades in a linked list
 *          void search(string) : A function to find data with a specific major in a linked list
 *          void addList(List&) : add list to previous list
 * ********************************************************************************************************/

#include <iostream>
#include <fstream>
#include "SLL.h"

/**********************************************************************************************************
* function : main
* description : By reading the file "data1.dat" and "data2.dat", make the lists and print out the results
* variables : l1 - List created by reading "data1.dat" file
*             l2 - List created by reading "data1.dat" and "data2.dat" files
* *********************************************************************************************************/

int main()
{
    List l1; // contents : "data1.dat"
    List l2; // contents : "data1.dat" + "data2.dat"

    // read the data
    std::ifstream inStream;
    inStream.open("data1.dat");

    for (int i = 0; i < 8; i++)
    {
        char name;
        int ID;
        std::string major;
        char grade;

        inStream >> name >> ID >> major >> grade;
        // insert data into the l1 in name order.
        l1.insertNode(name, ID, major, grade);
    }

    std::ifstream inFile;
    inFile.open("data2.dat");
    for (int i = 0; i < 3; i++)
    {
        char name;
        int ID;
        std::string major;
        char grade;

        inFile >> name >> ID >> major >> grade;

        // insert data into the l2 in name order.
        l2.insertNode(name, ID, major, grade);
    }

    // merge the list (l1 + l2)
    l2.addList(l1);

    // print out the results
    l1.traverse();
    std::cout << "-----------" << std::endl;
    l1.search('A');
    std::cout << "-----------" << std::endl;
    l2.search("CS");
}