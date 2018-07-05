#include <iostream>
#include <cstdlib>
#include <cstdio>

int g;

void func(int& i) // integer reference
void cfunc(int* p); // C version - don't use pointer that is able to 
// !!!!!! pointer 무조건 4bytes !!!!!!

int main()
{
    int l;
    l = 2;
    func(l);  // change from 2 to 5 by func()
    cfunc(&l);

    void* p;
    p = malloc(1000);
    // 그 객체의 절대적인 위치
    int* i;
    i = (int*)malloc(1000); 

    return 0;
}

void func(int& i) {
    i = 5;   // 메모리 자체, 실체를 넘겨받음
}

void cfunc(*int p)  // * : p의 주소를 가지고 있는 공간. 그곳에 가면 int가 있을거임.
{
    /* pointer가 type을 가지고 있는 이유 : 땅 크기. 주소로부터 얼마만큼 더 보아야 하는가를 정하기 위해서.
    
     ex) double : 8 bytes - p가 100번지라고 하면 100번지부터 8bytes를 볼 지 결정 */

     // void pointer : 모든 pointer의 조상. 
    *p = 5;  // 실체.
}