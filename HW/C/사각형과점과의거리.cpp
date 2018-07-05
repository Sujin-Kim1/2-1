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
    // output : d2^   d1

    // store coordinates, euclidean distance ^ 2, rectilinear distance
    long x1, y1, x2, y2, x, y, d1, d2;
    inStream >> x1 >> y1 >> x2 >> y2 >> x >> y;

    if (((x1 <= x) && (x <= x2)) && ((y1 <= y) && (y <= y2))) {
        d2 = 0; d1 = 0;
    }
    else if ((x < x1) && (y < y1)) {
        d2 = pow((x1 - x), 2) + pow((y1 - y), 2);
        d1 = x1 - x + y1 - y;
    } else if (((x1 <= x) && (x <= x2)) && (y <= y1)) {
        d2 = pow((y1 - y), 2);
        d1 = y1 - y;
    } else if ((x2 < x) && (y < y1)) {
        d2 = pow((x2 - x), 2) + pow((y1 - y), 2);
        d1 = x - x2 + y1 - y;
    } else if ((x2 <= x) && ((y1 <= y) && (y <= y2))) {
        d2 = pow((x2 - x),2);
        d1 = x - x2;
    } else if ((x2 < x) && (y2 < y)) {
        d2 = pow((x2 - x), 2) + pow((y2 - y), 2);
        d1 = x - x2 + y - y2;
    } else if (((x1 <= x) && (x <= x2)) && (y2 <= y)) {
        d2 = pow((y2 - y), 2);
        d1 = y - y2;
    } else if ((x < x1) && (y2 < y)) {
        d2 = pow((x1 - x), 2) + pow((y2 - y), 2);
        d1 = x1 - x + y - y2;
    } else {
        d2 = pow((x1 - x), 2);
        d1 = x1 - x;
    }

    std::cout << d2 << " " << d1 << std::endl;
}