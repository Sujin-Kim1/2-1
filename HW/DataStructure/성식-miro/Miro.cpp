//-------------------------------------------------------------------
// File : Miro.cpp
// 국민대학교 소프트웨어학부
// Author : 20171595 김성식
// Date : 2018.04.02
// Description : Algorithm to escape the maze using stack data
// structure
//-------------------------------------------------------------------

#include "Stack.h"
#include <iostream>

using namespace std;

// Class Name : offsets
// Global variables
// * vert, horiz - type : short int
// - purpose : to contain the vertical and
// horizontal variation
class offsets {
    public:
        short int vert;
        short int horiz;
};

void Maze() {
    // declare maze
    // 0 : able to pass 1 : unable to pass
    int maze[14][17] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
    {1,0,0,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
    {1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
    {1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
    {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
    {1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
    {1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    
    // declare mark
    // save the trace
    int mark[14][17] = {{0}};

    // prioritize clockwise from the east
    const int E = 0;
    const int SE = 1;
    const int S = 2;
    const int SW = 3;
    const int W = 4;
    const int NW = 5;
    const int N = 6;
    const int NE = 7;

    // to set offsets of each direction
    offsets move[8];
    move[E].vert = 0; move[E].horiz = 1;
    move[SE].vert = 1; move[SE].horiz = 1;
    move[S].vert = 1; move[S].horiz = 0;
    move[SW].vert = 1; move[SW].horiz = -1;
    move[W].vert = 0; move[W].horiz = -1;
    move[NW].vert = -1; move[NW].horiz = -1;
    move[N].vert = -1; move[N].horiz = 0;
    move[NE].vert = -1; move[NE].horiz = 1;

    // the coordinate value of destination
    int EXIT_Row = 12;
    int EXIT_Col = 15;

    Stack stack;

    // start at (1, 1)
    mark[1][1] = 1;
    
    // save the starting point in the stack
    // initialize the direction as east
    stack.Push(Position(1, 1, 0));

    // i : x-coordinate of current position
    // j : y-coordinate of current position
    // d : current direction
    int i, j, d;

    while (stack.top > -1) { // stack is not empty
        // pop position and direction of top in stack
        Position pos = stack.Pop(); 
        i = pos.x;
        j = pos.y;
        d = pos.dir;
        bool noFound = true;
        while (d < 8) {
            int g = i + move[d].vert;
            int h = j + move[d].horiz;
            if (g == EXIT_Row && h == EXIT_Col) { // find destination
                mark[g][h] = 1;
                // print path
                for (int a = 0; a < 14; a++) {
                    for (int b = 0; b < 17; b++) {
                        cout << mark[a][b] << ' ';
                    } cout << endl;
                }
                return;
            }
            if ((maze[g][h] == 0) && (mark[g][h] == 0)) { // new position
                mark[g][h] = 1;
                Position temp(i, j, d + 1);
                stack.Push(temp); // append current position to stack
                // move to (g, h)
                i = g;
                j = h;
                d = 0;
                bool noFound= false;
            } else {
                d++; // try new direction
            }
        }
        // if there is no new position(go back to position you come from),
        // change the mark to 0 and maze to 1 (not to go wrong way again)
        if (noFound) {
            maze[i][j] = 1;
            mark[i][j] = 0;
        }
    }
    cout << "no path in maze" << endl;
    return;
}

int main() {
    Maze();
    return 0;
}