#include <iostream>
#include "transpose.h"

/*
function name: init
function: a배열 초기화
*/

void init(term a[])
{
    a[0].row = 6;
    a[0].col = 6;
    a[0].val = 8;

    a[1].row = 0; a[1].col = 0; a[1].val = 15;
    a[2].row = 0; a[2].col = 3; a[2].val = 22;
    a[3].row = 0; a[3].col = 5; a[3].val = -15;
    a[4].row = 1; a[4].col = 1; a[4].val = 11;
    a[5].row = 1; a[5].col = 2; a[5].val = 3;
    a[6].row = 2; a[6].col = 3; a[6].val = -6;
    a[7].row = 4; a[7].col = 0; a[7].val = 91;
    a[8].row = 5; a[8].col = 2; a[8].val = 28;
}

/*
function name: transpose
function: a를 transpose하여 b 생성
O(col * elements)
*/

void transpose(term a[], term b[])
{
    int i;
    int j;
    int currentb;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    if (a[0].val > 0) // 0이 아닌 행렬
    {
        currentb = 1;
        for (i = 0; i < a[0].col; i++) // 열별로 전치
        {
            for (j = 0; j < a[0].row; j++)
            {
                // 현재 열에 있는 원소를 b에 첨가
                if (a[j].col == i)
                {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].val = a[j].val;
                    currentb++;
                }
            }
        }
    }
}

/*
function name: fast_transpose
function: transpose 함수보다 연산 시간을 절약하기 위한 알고리즘
원래 행렬의 각 열에 대한 원소 수를 먼저 구해서 전치 행렬의 각 행에
대한 원소 수를 결정한다. 이 정보로부터 전치 행렬에서 각 행의 시작
위치를 구하고 원래 행렬에 있는 원소를 하나씩 전치 행렬의 올바른 
위치로 옮기는 것이다.
*/

void fast_transpose(term a[], term b[])
{
    int row_terms[MAX_COL], starting_pos[MAX_COL];
    int i, j, num_cols = a[0].col, num_terms = a[0].val;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    if (num_terms > 0)
    {
        for (i = 0; i < num_cols; i++) // 열의 갯수만큼 반복하며 row_terms 배열을 0 으로 초기화
        {
            row_terms[i] = 0;
        }
        for (i = 1; i <= num_terms; i++) // 원소가 있는 열의 인덱스에 해당하는 row_terms 의 값을 ++
        {                                // ( 열에 존재하는 원소의 개수 )
            row_terms[a[i].col]++;
        }

        starting_pos[0] = 1; //  첫번째 원소는 b[1] 에 저장

        for (i = 1; i < num_cols; i++) // starting_pos[i] 는 전치행렬의 행 i 에 대한 시작위치를 나타낸다.
        {
            starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1]; // 바로 전 인덱스에 해당하는 row_terms 와 starting_pos
        }
             
        for (i = 1; i <= num_terms; i++)
        {
            j = starting_pos[a[i].col]++; // 각 행의 시작 위치
            b[j].row = a[i].col;          // 구한 올바른 위치에 원소를 옮긴다.
            b[j].col = a[i].row;          
            b[j].val = a[i].val;      
        }
        
        for (i = 1; i <= 8; i++)
        {
            std::cout << b[i].row << "  " << b[i].col << "  " << b[i].val << std::endl;
        }
    }
}

int main()
{
    term a[MAX_COL], b[MAX_COL];
    init(a);
    fast_transpose(a, b);
}
