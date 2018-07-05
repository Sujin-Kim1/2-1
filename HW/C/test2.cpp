#include <iostream>
#include <fstream>
#include <cstdlib>

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
    inStream.close();
    return 0;
}

void ProblemSolving(std::ifstream& inStream) {
    int numTest;
    inStream >> numTest;

    int first;
    int second;
    inStream >> first;
    inStream >> second;
    if (first <= second) {
        int temp = second;
        first = second;
        second = temp;
    }

    for (int i = 0; i < numTest - 2; ++i) {
        int tmp;
        inStream >> tmp;

        if (tmp >= first) {
            if (first >= second) second = first;
            std::cout <<"sec :" << second <<std::endl;
            
            first = tmp;
            std::cout <<"fir :" << first <<std::endl;
            
            
        }
    }
    std::cout << second << std::endl;
}
