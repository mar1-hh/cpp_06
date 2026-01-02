#include <iostream>


int main()
{
    // for (int i = 128; i < 599; i++)
    //     std::cout << isprint(i) << std::endl;

    double d = strtod("nanf", NULL);
    std::cout << d << std::endl;
    return (0);
}