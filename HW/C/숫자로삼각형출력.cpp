#include <iostream>
#include <fstream>

void ProblemSolving(std::ifstream& inStream);

int main() {
    std::ifstream inStream;
    
    inStream.open("input.txt");

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; ++i) {
        ProblemSolving(inStream);
    } 

    inStream.close();
    return 0;
}

void ProblemSolving(std::ifstream& inStream) {

/*   0    1            2               3
0    1
1    2 2+(4-1)  
2    3 3+(4-1)  3+(4-1)+(4-2)
3    4 4+(4-1)  4+(4-1)+(4-2) 4+(4-1)+(4-2)+(4-3)
*/

    int numTest;
    inStream >> numTest;


    for (int i = 0; i < numTest; i++) {
        int tmp = i + 1;
        for (int j = 0; j <= i; j++) {
            if (j != 0) {
                tmp += numTest - j;
            }
            std::cout << tmp << " ";
            
        }
        std::cout << std::endl;
    }
}