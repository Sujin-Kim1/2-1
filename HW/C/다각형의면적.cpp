#include <iostream>
#include <fstream>

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
    int n, S = 0; // number of vertices(꼭지점), Signed Area * 2
    inStream >> n;
    n *= 2; // number of coordinates
    
    int verticesArr[n + 4];  

    for (int i = 0; i < n; i++) {   // stores coordinates
        int x;
        inStream >> x;
        verticesArr[i] = x;
    } 
    // Pn = P0
    verticesArr[n] = verticesArr[0];  
    verticesArr[n + 1] = verticesArr[1];  
    

    for (int i = 0; i < n ; i += 2) {
        S += verticesArr[i] * verticesArr[i + 3] - verticesArr[i + 1] * verticesArr[i + 2];
    }
    if (S >= 0) std::cout << S << " " << 1 << std::endl;
    else std::cout << -S << " " << -1 << std::endl;
}