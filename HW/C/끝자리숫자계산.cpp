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
    int numTest, mul;
    inStream >> numTest;
    mul = 1;
    for(int i = 0; i < numTest; i++) {
        int in;
        inStream >> in;
        mul *= in % 10;        
        if (mul >= 10) {
            mul %= 10;
        }
    }
    std::cout << mul << std::endl;
}
