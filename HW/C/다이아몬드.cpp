#include <iostream>
#include <fstream>

void ProblemSolving(std::ifstream& inStream);

int main() {
    // open the input file
    std::ifstream inStream;
    inStream.open("input.txt");

    // read the number of test cases
    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; ++i) {
        ProblemSolving(inStream);
    }

    return 0;
}

void ProblemSolving(std::ifstream& inStream) {
    int test;
    inStream >> test;
    for (int i = 0; i < test / 2 + 1; i++) { 
        for(int j = 0; j < test / 2 - i; j++) {    
            std::cout << "*";
        }
        for(int k = 0; k <= 2 * i; k++) {   
            std::cout << "+";
        }
        for(int j = 0; j < test / 2 - i; j++) {  
            std::cout << "*";
    }
      std::cout << std::endl;
}
    for (int i = 0; i < test / 2; i++) {  
        for (int j = 0; j <= i; j++) {   
            std::cout << "*";
        }
        for (int k = 0; k < test - 2 - i * 2; k++) {
            std::cout << "+";
        }

        for (int j = 0; j <= i; j++) {   
            std::cout << "*";
        }
    std::cout <<std::endl;
    }
}