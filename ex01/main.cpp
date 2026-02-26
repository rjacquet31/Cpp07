#include <iostream>
#include "iter.hpp"

void printInt(const int &x)
{
    std::cout << x << " ";
}

void printString(const std::string &s)
{
    std::cout << s << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string strs[] = {"hello", "world", "42"};

    std::cout << "Ints: ";
    iter(arr, 5, printInt);
    std::cout << std::endl;

    std::cout << "Strings: ";
    iter(strs, 3, printString);
    std::cout << std::endl;

    return 0;
}