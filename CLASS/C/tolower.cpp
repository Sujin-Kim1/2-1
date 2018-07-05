#include <iostream>
#include <string>

void toLower(char& cv);

int main()
{
    std::string str;
    std::cin >> str;
    int i = 0;
    while (str[i] != '\0')
    {
        char cv = str[i];
        toLower(cv);
        std::cout << cv;
        i++;
    }
    std::cout << std::endl;
}

void toLower(char& cv)
{
    if (cv >= 'A' && cv <= 'Z')
    {
        cv += ('a' - 'A');
    }
}