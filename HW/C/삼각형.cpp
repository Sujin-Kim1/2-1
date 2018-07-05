#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

int getArea(const int, const int, const int, const int, const int, const int, int &, int &, int &);
int getArea(const int, const int, const int, const int, const int, const int);
void swap(int &a, int &b);
int typeOfTriangle(const int &, const int &, const int &);
int angleOfTriangle(const int &, const int &, const int &);
int positionOfT(const int, const int, const int, const int, const int, const int, const int, const int);

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
        int px, py, qx, qy, rx, ry, tx, ty;
        int a, b, c; // length of side
        inStream >> px >> py >> qx >> qy >> rx >> ry >> tx >> ty;

        if (getArea(px, py, qx, qy, rx, ry, a, b, c) == 0)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        else
        {
            // output : 삼각형 X -> 0 / 삼각형 O -> 2S
            std::cout << getArea(px, py, qx, qy, rx, ry, a, b, c) << " ";
            //          정, 직각, 이등변, 일반 -> 1 2 3 4
            std::cout << typeOfTriangle(a, b, c) << " ";
            //          직각 둔각 예각 -> 1 2 3
            std::cout << angleOfTriangle(a, b, c) << " ";
            //          t 내부 변 외부 -> 1 2 3
            std::cout << positionOfT(px, py, qx, qy, rx, ry, tx, ty) << std::endl;
        }
    }
    inStream.close();
    return 0;
}

int getArea(const int ax, const int ay, const int bx, const int by, const int cx, const int cy, int &a, int &b, int &c)
{
    a = (bx - ax) * (bx - ax) + (by - ay) * (by - ay); // side AB's length ^2
    b = (cx - bx) * (cx - bx) + (cy - by) * (cy - by); // side BC's length ^2
    c = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy); // side CA's length ^2

    // sort a, b, c by size (a <= b <= c)
    if (a >= b)
        swap(a, b);
    if (b >= c)
        swap(b, c);
    if (a >= b)
        swap(a, b);

    // sort out what triangle it is
    if (sqrt(a) + sqrt(b) <= sqrt(c))
        return 0; // 삼각형 X
    else
    {
        int S = ((bx - ax) * (cy - ay) - (cx - ax) * (by - ay)); // 2 * area
        if (S < 0)
            S = -S;
        return S;
    }
}

int getArea(const int ax, const int ay, const int bx, const int by, const int cx, const int cy)
{
    int S = ((bx - ax) * (cy - ay) - (cx - ax) * (by - ay)); // 2 * area
    if (S < 0)
        S = -S;
    return S;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int typeOfTriangle(const int &a, const int &b, const int &c)
{
    if (a == b && b == c)
        return 1; // 정삼각형
    else if (a + b == c)
        return 2; // 직각삼각형
    else if (a == b || b == c || c == a)
        return 3; // 이등변 삼각형
    else
        return 4; // 일반 삼각형
}

int angleOfTriangle(const int &a, const int &b, const int &c)
{
    if (a + b == c)
        return 1; // 직각
    else if (a + b < c)
        return 2; // 둔각
    else
        return 3; // 예각
}

int positionOfT(const int ax, const int ay, const int bx, const int by, const int cx, const int cy, const int tx, const int ty)
{
    if (getArea(ax, ay, bx, by, tx, ty) + getArea(bx, by, cx, cy, tx, ty) + getArea(cx, cy, ax, ay, tx, ty)
    == getArea(ax, ay, bx, by, cx, cy))
    {
        if (getArea(ax, ay, bx, by, tx, ty) == 0 || getArea(bx, by, cx, cy, tx, ty) == 0 ||
        getArea(cx, cy, ax, ay, tx, ty) == 0)
            return 2;
        else
            return 1;
    }
    else
        return 3;
}