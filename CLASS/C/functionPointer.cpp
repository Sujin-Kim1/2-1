// 함수의 이름 = 함수의 주소

#include <iostream>
#include <cstdlib>
#include <cstdio>

void update_array(int p[10]);

void (*_key_press)(char);

void my_press(char c){
    std::cout << c << "key is pressed" << std::endl;
}

int main() {
    // int arr[10];
    // update_array(arr);  // 함수의 이름 = 주소 function pointer

    // void (* p)(int p[10]);  // 변수 이름 : p
    // // g = f, g(2x) = ?f(x)
    // // functor라고 함
    // // 이 함수가 불리게 해줘 
    // // 함수의 이름 == function pointer
    
    // p = update_array;

    // p(arr); // == update_array(arr);
    _key_press = NULL;

    _key_press = my_key_press; // event listener 호출

    while (true) {
        // event listening
        int signal;
        if (signal == KEY_PRESS) {
            if (_key_press != NULL)  // _key_press 알고 있으면 아래 코드 실행
            _key_press(char c);
        }
    }
 }