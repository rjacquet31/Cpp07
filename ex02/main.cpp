#include <iostream>
#include <string>
#include "Array.hpp"

static void test_int_array()
{
    std::cout << "\n=== test_int_array ===" << std::endl;

    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = static_cast<int>(i) * 10;

    std::cout << "a contents: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "a.size() = " << a.size() << std::endl;
}

static void test_copy_and_assignment()
{
    std::cout << "\n=== test_copy_and_assignment ===" << std::endl;

    Array<int> a(3);
    a[0] = 1; a[1] = 2; a[2] = 3;

    std::cout << "Copy construction b(a)" << std::endl;
    Array<int> b(a);

    std::cout << "Modify b[0] = 999 (should NOT change a[0])" << std::endl;
    b[0] = 999;

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "b: ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "Assignment c = a" << std::endl;
    Array<int> c;
    c = a;

    std::cout << "Modify c[1] = 777 (should NOT change a[1])" << std::endl;
    c[1] = 777;

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "c: ";
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;
}

static void test_out_of_bounds()
{
    std::cout << "\n=== test_out_of_bounds ===" << std::endl;

    Array<int> a(2);
    a[0] = 10;
    a[1] = 20;

    try
    {
        std::cout << "Access a[2] (should throw)..." << std::endl;
        std::cout << a[2] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

static void test_string_array()
{
    std::cout << "\n=== test_string_array ===" << std::endl;

    Array<std::string> s(3);
    s[0] = "hello";
    s[1] = "world";
    s[2] = "42";

    std::cout << "s contents: ";
    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::cout << "===== Array<T> tests =====" << std::endl;

    test_int_array();
    test_copy_and_assignment();
    test_out_of_bounds();
    test_string_array();

    std::cout << "\n===== End =====" << std::endl;
    return 0;
}
