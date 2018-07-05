/*-------------------------------------------------------------------
    file : main.cpp
    국민대학교 소프트웨어학부 
    Author : 20171596 김수진
    Description : escape a maze using stack
---------------------------------------------------------------------*/

#include <iostream>
#include "stack.h"

void mazeFunc();  // function of exploration the maze

int main() {  
    // declaration of maze 
    // 0 : road     1 : wall
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
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };

    // declaration of mark
    int mark[14][17]= {0};

    // structures with coordinates
    typedef struct {short int vert; short int horiz; short int dir;}offset;
    offset move[8];

    // setting coordinates movement value   
    move[0].vert = -1; move[0].horiz = 0; move[0].dir = 0; // N
    move[1].vert = -1; move[1].horiz = 1; move[1].dir = 1; // NE
    move[2].vert = 0; move[2].horiz = 1; move[2].dir = 2; // E
    move[3].vert = 1; move[3].horiz = 1; move[3].dir = 3; // SE
    move[4].vert = 1; move[4].horiz = 0; move[4].dir = 4; // S
    move[5].vert = 1; move[5].horiz = -1; move[5].dir = 5; // SW
    move[6].vert = 0; move[6].horiz = -1; move[6].dir = 6; // W
    move[7].vert = -1; move[7].horiz = -1; move[7].dir = 7; // NW  

    int Exit_row = 12;
    int Exit_col = 15;

    Stack stack;

    mark[1][1] = 1; // start from (1, 1)
    stack.push(Position(1,1,0));  // store entrance coordinates and direction(N) to stack

    // i : current x coordinate
    // j : current y coordinate
    // d : current direction
    short int i, j, d;

    while (!stack.isEmpty()) {  // stack is not empty
        Position position = stack.pop();
        i = position.x;
        j = position.y;
        d = position.dir;
        while (d < 8) {  // possible to keep moving
            // (g, h) : next move coordinates
            int g = i + move[d].vert;
            int h = j + move[d].horiz;
            
            // exit arrival
            if ((g == Exit_row) && (h == Exit_col)) {
                // print mark
                    for (int p = 0; p < 14; p++) {
                        for (int q = 0; q < 17; q++) {
                            std::cout << mark[p][q] << " ";
                        }
                        std::cout << std::endl;
                    }
                return 0;
            }
        

            if ((!maze[g][h]) && (!mark[g][h])) {
                mark[g][h] = 1;
                Position temp(i, j, d + 1);               
                stack.push(temp);  // inserting to stack
                i = g; j = h; d = 0;  // move to (g, h) 
            }
            else d++;
        }
    }
        std::cout << "no path in maze" << std::endl;
    
}

