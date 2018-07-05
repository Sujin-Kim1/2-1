#include <iostream>
#include <fstream>

bool isYoon(int days);
int monthDays(int year, int month);
int dayOfWeek(int year, int month);
void output(std::ifstream &inStream);

int main(void)
{
    std::ifstream inStream;
    inStream.open("input.txt");

    if (inStream.fail())
    {
        std::cerr << "opening file is failed\n";
        return -1;
    }

    int numTestcases;
    inStream >> numTestcases;

    for (int i = 0; i < numTestcases; i++)
    {
        output(inStream);
    }
}

bool isYoon(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int monthDays(int year, int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 2:
        if (!isYoon(year))
            return 28;
        return 29;
    default:
        return 30;
    }
}

/* judge what day is the 1st day */
int dayOfWeek(int Y, int M)
{
    int days = 0;

    for (int i = 1582; i < Y; ++i)
    {
        if (!isYoon(i))
            days += 365;
        else
            days += 366;
    }

    for (int i = 1; i < M; ++i)
    {
        days += monthDays(Y, i);
    }

    days += 5;

    return days % 7;
}

void output(std::ifstream &inStream)
{
    int Y, M, day, cursor = 0;
    inStream >> Y >> M;

    day = dayOfWeek(Y, M);

    std::cout << Y << " " << M << std::endl;

    for (int i = 0; i < day; i++)
    {
        std::cout << 0 << " ";
        cursor++;
    }

    for (int i = 1; i <= monthDays(Y, M); i++)
    {
        if (cursor != 7)
        {
            std::cout << i << " ";
            cursor++;
        }
        else 
        {   
            cursor = 1;
            std::cout << "\n" << i << " ";
        }
    }

    for (int i = cursor; cursor != 7; i++)
    {
        std::cout << 0 << " ";
        cursor++;
    }
    std::cout << std::endl;
}