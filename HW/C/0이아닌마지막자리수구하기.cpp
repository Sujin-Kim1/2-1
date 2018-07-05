#include <iostream>
#include <fstream>
#include <cmath>

void ProblemSolving(std::ifstream& inStream);

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
        ProblemSolving(inStream);
    }
    
    inStream.close();

    return 0;
}

void ProblemSolving(std::ifstream& inStream) {  
    long numZero, input, numTest, lastNum = 1, countFive = 0, countTwo = 0; 
    inStream >> numTest;

    for (int i = 0; i < numTest; i++) {
        inStream >> input;
            
        while (input % 5 == 0) {
            input /= 5;
            ++countFive;
        }
         
        while (input % 2 == 0) {
            input /= 2;
            ++countTwo;
        }

        lastNum *= input % 10;
        lastNum %= 10;
    }

    if (countFive == countTwo) {
        numZero = countFive;
        countFive = 0;
        countTwo = 0;
    } else if (countFive < countTwo) {
        numZero = countFive;
        countFive = 0;
        countTwo -= numZero;
    } else {
        numZero = countTwo;
        countFive -= numZero;
        countTwo = 0;
    }

    while (countFive != 0) {
        lastNum *= 5;
        lastNum %= 10;
        --countFive;
    }
    while (countTwo != 0) {
        lastNum *= 2;
        lastNum %= 10;
        --countTwo;
    }   
    
    std::cout << lastNum << " " << numZero << std::endl;
}