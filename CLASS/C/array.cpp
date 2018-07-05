// 배열의 이름 = 배열 시작 주소 = 실체가 있는 곳의 위치

#include <iostream>
#include <Cstdlib>
#include <cstdio>

void update_array(int* p, unsigned int size);   
// 사이즈를 모르기 때문에 unsigned int size 적어놓고 main에서 arr[10]이니까 길이 10인 배열 생성
// == void update_array(int p[], unsigned int size);
// == void update_array(int p[10]); 

int main() {
    int arr[10]; // dynamic arr를 만들지 않는 이상 stack에 저장
    // int* p;    
    char* p; // 받은 메모리 안에서는 어떤 방법으로 사용해도 괜찮
    update_array(arr);  // !!!!!!!배열의 이름 == 위치

    arr[0] = -3;
    
    // p = arr;   // 배열의 이름 = arr[0]의 주소 = &arr[0] = 위치
    p = (char*) arr;   // type : char로 저장. 
    p[0] = 5;

    std::cout << arr[0] <<std::endl;   // 5


    return 0;
}

void update_array(int* p, unsigned int size) 
{
    p[0] = -3;    // call by reference 같지만 call by value
}