#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(ScalarConverter& obj)
{
    (void)obj;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& obj)
{
    (void)obj;
    return (*this);
}

ScalarConverter::~ScalarConverter(){};

bool is_scstr(std::string str);

bool is_char(std::string str)
{
    if (str.length() == 1 && isprint(str[0]))
        return (1);
    return (0);
}

bool is_float(std::string str)
{
    size_t i = 0;
    if (is_scstr(str))
    return (1);
    if (str[i] == '-')
        i++;
    while (i < str.length() && isdigit(str[i]))
        i++;
    if (str[i] == '.')
        i++;
    while (i < str.length() && isdigit(str[i]))
        i++;
    if (str[i] == 'f')
    {
        i++;
    }
    return (i == str.length());
}

bool is_scstr(std::string str)
{
    if (str == "nan" || str == "-nan" || str == "+nan" || str == "inf" || str == "-inf" || str == "+inf")
    return (1);
    if (str == "nanf" || str == "-nanf" || str == "+nanf" || str == "inff" || str == "-inff" || str == "+inff")
    {
        return (1);
    }
    
    return (0);
}

void info_print(char c, int int_num, float fl_num, double dl_num)
{
    std::cout << "char: ";
    if (std::isnan(dl_num) || std::isinf(dl_num))
        std::cout << "impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << c << std::endl;

    std::cout << "int: ";
    if (std::isnan(dl_num) || std::isinf(dl_num) || dl_num > static_cast<double> (INT_MAX) || dl_num < static_cast<double> (INT_MIN))
        std::cout << "impossible" << std::endl;
    else
        std::cout << int_num << std::endl;

    std::cout << "float: " << fl_num;
    if (fl_num == floor(fl_num) && !(std::isnan(fl_num) || std::isinf(fl_num)))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << dl_num;
    if (dl_num == floor(dl_num) && !(std::isnan(dl_num) || std::isinf(dl_num)))
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

void out_char(std::string str)
{
    char c = str[0];

    int int_num = static_cast<int> (c);
    float fl_num = static_cast<float> (c);
    double dl_num = static_cast<double> (c);

    info_print(c, int_num, fl_num, dl_num);
}

void out_double(std::string str)
{
    double dl_num = strtod(str.c_str(), NULL);
    int int_num = static_cast<int> (dl_num);
    char c;
    if (int_num >= 32 && int_num <= 126)
        c = static_cast<char> (dl_num);
    else
        c = 1;
    float fl_num = static_cast<float> (dl_num);
    info_print(c, int_num, fl_num, dl_num);
}

void ScalarConverter::convert(std::string str)
{
    if (is_float(str))
        out_double(str);
    else if (is_char(str))
        out_char(str);
    else
        std::cout << "something wrong" << std::endl;
}