#include <iostream>
#include <string>

void toUpper(char& cv);

int main() {
    std::string str;
    std::cin >> str;
    int i = 0;
    while (str[i] != '\0')
    {
        char cv = str[i];
        toUpper(cv);
        i++;
        std::cout << cv;
    }
    std::cout << std::endl;
}

void toUpper(char& cv)
{
    if (cv >= 'a' && cv <= 'z')
    {
        cv -= ('a' - 'A');
    }
}
