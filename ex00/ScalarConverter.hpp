#pragma once

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <limits.h>

class ScalarConverter
{
    public:
    ScalarConverter();
    ScalarConverter(ScalarConverter& obj);
    ScalarConverter& operator=(ScalarConverter& obj);
    ~ScalarConverter();
    static void convert(std::string str);
};