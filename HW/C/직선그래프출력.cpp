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
    
    for (int i = 0; i < numTest; i++) {  // horizontal 
        for (int j = 0; j < numTest; j++) {  // vertical 
            if (j != numTest / 2 && i == numTest / 2) std::cout << "+";   // x axis          
            else if (j == numTest / 2 && i != numTest / 2) std::cout << "I"; // y axis
            else if (j == numTest / 2 && i == numTest / 2) std::cout << "O"; // origin       
            else if (j == numTest - i - 1) std::cout << "*";  // straight
            else std::cout << ".";
        } std::cout << std::endl;
    }

}