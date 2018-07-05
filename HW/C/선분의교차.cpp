#include <iostream>
#include <fstream>
#include <cstdlib>

int getSignedArea(int, int, int, int, int, int);
int ProblemSolving(std::ifstream &inStream);

int main()
{
    // read the file
    std::ifstream inStream;
    inStream.open("input.txt");
    // print the error message if the file is wrong
    if (inStream.fail())
    {
        std::cerr << "Input file opening failed." << std::endl;
        std::exit(1);
    }
    // store the test cases
    int numTestCases;
    inStream >> numTestCases;
    // solving
    for (int i = 0; i < numTestCases; i++)
    {
        std::cout << ProblemSolving(inStream) << std::endl;
    }
    return 0;
}

int getSignedArea(int px, int py, int qx, int qy, int rx, int ry)
{
    return px * qy - py * qx + py * rx - px * ry + qx * ry - rx * qy;
}

int ProblemSolving(std::ifstream &inStream)
{
    int ax, ay, bx, by, cx, cy, dx, dy;
    inStream >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    if (getSignedArea(ax, ay, bx, by, cx, cy) * getSignedArea(ax, ay, bx, by, dx, dy) < 0
    && getSignedArea(cx, cy, dx, dy, ax, ay) * getSignedArea(cx, cy, dx, dy, bx, by) < 0)
        return 1;
    else if (getSignedArea(ax, ay, bx, by, cx, cy) * getSignedArea(ax, ay, bx, by, dx, dy) == 0
    || getSignedArea(cx, cy, dx, dy, ax, ay) * getSignedArea(cx, cy, dx, dy, bx, by) == 0)
        return 2;
    else 
        return 0;
}   