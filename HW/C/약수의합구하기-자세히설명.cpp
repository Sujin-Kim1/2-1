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
    return 0;
}

void ProblemSolving(std::ifstream& inStream) {
    // output : number of proper divisors(진약수) and sum of all proper divisors
    
    long numTest, num = 0, sum = 0;
    inStream >> numTest;

    for (int i = 1; i <= sqrt(numTest); i++) {
        if (numTest % i == 0) {
            num += 2;
            sum += i + numTest / i;
        }
    }
    // except oneself
    --num; 
    sum -= numTest; 
    
    std::cout << num << " " << sum << std::endl;
}