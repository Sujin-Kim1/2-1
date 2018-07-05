#include <iostream>
#include <fstream>

void ProblemSolving(std::ifstream& inStream);

int main(void) {
    std::ifstream inStream;
    inStream.open("input.txt");

    if (inStream.fail()) {
        std::cerr << "Input file opening failed.\n";
        return -1;
    }

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++) {
        ProblemSolving(inStream);
    }

    return 0;
}

void ProblemSolving(std::ifstream& inStream) {
    int numTest;
    inStream >> numTest;

/*
n == 7
  0123456      -    *    +
0 *+*+*+*      0    4    3
1 -*+*+*-      2    3    2
2 --*+*--      4    2    1
3 ---*---      6    1    0
4 --*+*--      4    2    1
5 -*+*+*-      2    3    2
6 *+*+*+*      0    4    3    

*/

    for (int i = 0; i < numTest; i++) {
        if (i < numTest / 2 + 1) {    
            for (int j = 0; j < i; j++) { 
            std::cout << "-";
            }
            for (int j = 0; j < numTest / 2 - i + 1; j++) { 
                std::cout << "*";
                if (j != numTest / 2 - i) {
                    std::cout << "+";
                }
            } 
            for (int j = 0; j < i; j++) {
                std::cout << "-";
            }
            std::cout << std::endl;
            }
         
        else {  
            for (int j= 0; j < numTest - i - 1; j++) {    
                std::cout << "-";
            } 
            for (int j = 0; j < i - numTest / 2 + 1; j++) {  
                std::cout << "*";
                if (j != i - (numTest / 2)) {
                    std::cout << "+";
                }
            }

            for (int j= 0; j < numTest - i - 1; j++) {  
                std::cout << "-";
            } 

        std::cout << std::endl;   
        } 
    }
}