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
    return 0;
}

void ProblemSolving(std::ifstream& inStream) {
    // output : 2 * Area, clockwise : -1, counterclockwise : 1, a straight line : 0

    // coordinates, 2 * SignedArea, 2 * UnsigendArea (|SignedArea|)
    int ax, ay, bx, by, cx, cy, S, U;
    inStream >> ax >> ay >> bx >> by >> cx >> cy;

    S = ((bx - ax) * (cy - ay) - (cx - ax) * (by - ay));
    U = -S;

    if (S < 0) std::cout << U << " " << -1 << std::endl;
    else if (S > 0) std::cout << S << " " << 1 << std::endl;
    else std::cout << 0 << " " << 0 << std::endl;

}