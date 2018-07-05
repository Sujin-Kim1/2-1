#include <iostream>
#include <fstream>

int ProblemSolving(std::ifstream& inStream);

int main() {
    // read the file
    std::ifstream inStream;
    inStream.open("input.txt");
    // print the error message if the file is wrong
    if (inStream.fail()) {
        std::cerr << "Input file opening failed.\n" << std::endl;
        return -1;
    }
    // store the test cases
    int numTestCases;
    inStream >> numTestCases;
    // solving
    for (int i = 0; i < numTestCases; i++) {
        std::cout << ProblemSolving(inStream) << std::endl;
    }
    return 0;
}

int ProblemSolving(std::ifstream& inStream) {
    // output : if testCases is decimal return 1 else 0

    long numTest, i;
    inStream >> numTest;

    for (i = 2; i <= numTest / 2; i++) {
        if (numTest % i == 0) {
            return 0;
        }
    }
    return 1;  
}