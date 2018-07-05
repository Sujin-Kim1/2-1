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
    int d1, d2, rd1, rd2;
    /* data1,2      remainder of data1,2*/
    int hw1 = 0, hw2 = 0, hd = 0; 
    /* hamming weight1,2    hamming distance */

    inStream >> d1 >> d2;

    for (int i = 0; i < 32; i++)
    {
        rd1 = d1 % 2;
        if (rd1 == 1)
            hw1++;
        d1 /= 2;
        
        rd2 = d2 % 2;
        if (rd2 == 1)
            hw2++;
        d2 /= 2;

        if (rd1 != rd2)
            hd++;
    }
    std::cout << hw1 << " " << hw2 << " " << hd << std::endl;
}