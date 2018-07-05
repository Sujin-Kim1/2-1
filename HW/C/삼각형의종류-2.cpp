#include <iostream>
#include <fstream>
#include <cmath>

int ProblemSolving(std::ifstream& inStream);
void swap_value (float &data1, float &data2);

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
        std::cout << ProblemSolving(inStream) << std::endl;
    }
    return 0;
}

int ProblemSolving(std::ifstream& inStream) {
    // not : 0    /    right : 1    
    // obtuse angle : 2    /    acute angle : 3
    
    // coordinates, length of side
    int ax, ay, bx, by, cx, cy;
    float a, b, c;
    inStream >> ax >> ay >> bx >> by >> cx >> cy;
    
    a = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);   // side AB's length ^2
    b = (cx - bx) * (cx - bx) + (cy - by) * (cy - by);  // side BC's length ^2
    c = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy);  // side CA's length ^2

    // sort a, b, c by size (a <= b <= c)
    if (a >= b) swap_value(a, b);
    if (b >= c) swap_value(b, c);
    if (a >= b) swap_value(a, b);

    // sort out what triangle it is
    if (sqrt(a) + sqrt(b) <= sqrt(c)) return 0; // 삼각형X
    else {
        if (a + b == c) return 1;  // 직각
        else if (a + b < c) return 2;  // 예각
        else return 3;  // 둔각
    }
}

void swap_value(float &data1, float &data2) {
    float temp = data1;
    data1 = data2;
    data2 = temp;
}