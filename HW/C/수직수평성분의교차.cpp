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
    }
    // store the test cases
    int numTestCases;
    inStream >> numTestCases;
    // solving
    for (int i = 0; i < numTestCases; i++) {
        ProblemSolving(inStream);
    }
}

void ProblemSolving(std::ifstream& inStream) {
    // full intersection : 1  /  tangent : 2  /  else : 0

    // store coordinates
    int x1,x2,x3,x4,y1,y2,y3,y4;
    inStream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    if (x1 == x2) {  // x1x2 is vertical
        if (((y1 <= y3) && (y3 <= y2)) || ((y2 <= y3) && (y3 <= y1))) {
            if ((x3 == x1) || (x4 == x1) || (((y1 == y3) || (y2 == y3)) && (((x3 <= x1) && (x1 <= x4)) || ((x4 <= x1) && (x1 <= x3))))) {
                std::cout << 2 << std::endl;
            } else if (((x3 < x1) && (x1 < x4)) || ((x4 < x1) && (x1 < x3))) {
                std::cout << 1 << std::endl;
            } else std::cout << 0 << std::endl;
         } else std::cout << 0 << std::endl;
    } else {  // x1x2 is horizon
        if (((y3 <= y1) && (y1 <= y4)) || ((y4 <= y1) && (y1 <= y3))) {
            if ((x1 == x3) || (x2 == x3) || (((y3 == y1) || (y4 == y1)) && (((x1 <= x3) && (x3 <= x2)) || ((x2 <= x3) && (x3 <= x1))))) {  
                std::cout << 2 << std::endl;
            } else if (((x1 < x3) && (x3 < x2)) || ((x2 < x3) && (x3 < x1))) {
                std::cout << 1 << std::endl;
            } else std::cout << 0 << std::endl;
        } else std::cout << 0 << std::endl; 
    }
    
}