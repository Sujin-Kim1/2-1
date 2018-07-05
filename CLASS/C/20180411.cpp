#include <iostream>
#include <cstring>
#include <cstdio>   // C의 stdio.h


void my_strcpy(char* dst, const char* src) {
    int len = strlen(src);
    memcpy(dst, src, 1 + sizeof(char)*n);  // 마지막에 끝낸다는 표시는 복사를 안했기 때문에 
    
}

void my_strcat(char* dst, const char* src) {
    int dst_len = strlen(dst);
    int src_len = strlen(src);

    memcpy(&dst[dst_len], str);  // '\0' 에서부터 str를 복사해라
    dst[dst_len + src_len] = '\0';
}

int main() {
    char a[256] = "3.141592";   // 숫자의미가 아닌 상형문자로 저장됨.
    char b[512];
    
    // float f = atof(a);   // 문자열 -> 숫자
    
    int i = 3;
    float f = 1.2f;
    double d = 1.23;
    char str[500];   // 변수는 아니지만 pointer처럼 행동함. str은 실존 X, str[0]은 실존 O
    // str = &i; (X)

    printf("HelloWorld\n");
    printf("i = %d %f %lf", i, f, d);   // file_name == 화면.
    fprintf(file_name, "");   // 파일에 적는다
    sprintf(str, "Hello");   // std::string cpp_str = "Hello";
    // str = "Hello"; (X)

    std::cin >> i;
    scanf("%d", &i);   // i위치에 적어라
    scanf("%s", str);  // 문자열 다 출력하고 싶을때. str이 배열 시작 위치이기 때문에
    scanf("%s", &str);     // (X) str은 위치. &str는 위치의 위치니까 
    scanf("%s", &str[0]);   // 굳이 &배열을 쓰고 싶을 때
    scanf("%s", &str[10]);    // 일부러 str[0]부터는 안적고 str[10]부터 적을 때
    
    fscanf(file_name, "");   // 파일을 읽는다.
}

void printf(...) 

void scanf(const char* s, int i) {
    
}
