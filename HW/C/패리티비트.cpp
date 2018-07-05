#include <iostream>
#include <fstream>
#include <cmath>

unsigned int problemSolving(std::ifstream& inStream);

int main() {
    std::ifstream inStream;
    inStream.open("input.txt");

    if (inStream.fail()) {
        std::cerr << "Input file opening failed." << std::endl;
    }

    int numTestCases;
    inStream >> numTestCases;

    for(int i = 0; i < numTestCases; i++) {
        std::cout << problemSolving(inStream) << std::endl;
    }
}

unsigned int problemSolving(std::ifstream& inStream) {
    unsigned int testCase;
    inStream >> testCase;

    unsigned int temp = testCase;
    int cnt = 0;
    for (int i = 0; i < 31; i++) {
        if (temp % 2 == 1) {
            temp /= 2;
            ++cnt;
        }
        else temp /= 2;
    }
    if (cnt % 2 == 0) return testCase;
    else return pow(2, 31) + testCase;
}