#include <iostream>
#define MAX_TERMS 100
/* 
    main : 실행. 결과값 출력
    void attach : 새 항을 다항식에 첨가
    void padd : A(x) + B(x) = D(x)
 */

typedef struct
{
    float coef;
    int expon;
} Polynomial;

Polynomial terms[MAX_TERMS];

int starta, finisha, startb, finishb, startd, finishd, avail;

void padd(int starta, int finisha, int startb, int finishb, int &startd, int &finishd);
void attach(float coefficient, int exponent);

int main()
{
    float c; // 계수 입력을 위한 변수
    int e;   // 지수 입력을 위한 변수
    avail = 0;
    starta = 0;

    // A(X) 입력
    while (1)
    {
        std::cout << "A(x) 계수 : ";
        std::cin >> c;
        std::cout << "A(X) 지수 : ";
        std::cin >> e;
        std::cout << std::endl;

        terms[avail].coef = c;  // 다항식의 계수 저장
        terms[avail].expon = e;  // 다항식의 지수 저장

        avail++; // 저장 배열 위치 증가

        if (e == 0)
        {
            finisha = avail - 1; // 다항식의 끝을 표시
            startb = avail;
            break;
        }
    }

    // B(X) 입력
    while (1)
    {
        std::cout << "B(x) 계수 : ";
        std::cin >> c;
        std::cout << "B(X) 지수 : ";
        std::cin >> e;
        std::cout << std::endl;

        terms[avail].coef = c;  // 다항식의 계수 저장
        terms[avail].expon = e;  // 다항식의 지수 저장

        avail++;  // 저장 배열 위치 증가

        if (e == 0)
        {
            finishb = avail - 1;
            break;
        }
    }

    padd(starta, finisha, startb, finishb, startd, finishd);

    for (int i = startd; i <= finishd; i++)
    {
        if (terms[i].expon == 0)
        {
            std::cout << terms[i].coef;
            continue;
        }
        std::cout << terms[i].coef << "x^" << terms[i].expon;

        if (i != finishd)
            std::cout << " + ";
    }
    std::cout << std::endl;
}

void padd(int starta, int finisha, int startb, int finishb, int &startd, int &finishd)
{
    float coefficient;
    startd = avail;

    while (starta <= finisha && startb <= finishb)
    {
        if (terms[starta].expon < terms[startb].expon)
        {
            attach(terms[startb].coef, terms[startb].expon);
            startb++;
            break;
        }
        else if (terms[starta].expon == terms[startb].expon)
        {
            coefficient = terms[starta].coef + terms[startb].coef;
            if (coefficient)
            {
                attach(coefficient, terms[starta].expon);
                starta++;
                startb++;
                break;
            }
        }
        else
        {
            attach(terms[starta].coef, terms[starta].expon);
            starta++;
            break;
        }
    }

    while (starta <= finisha)
    {
        attach(terms[starta].coef, terms[starta].expon);
        starta++;
    }

    while (startb <= finishb)
    {
        attach(terms[startb].coef, terms[startb].expon);
        startb++;
    }

    finishd = avail - 1;
}

void attach(float coefficient, int exponent)
{
    if (avail >= MAX_TERMS)
    {
        std::cout << "too many elements" << std::endl;
        return;
    }
    terms[avail].coef = coefficient;
    terms[avail].expon = exponent;

    avail++;
}