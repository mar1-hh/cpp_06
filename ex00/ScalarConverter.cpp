#include "ScalarConverter.hpp"

bool is_scstr(std::string str);

bool is_float_num = 0;

bool is_char(std::string str)
{
    if (str.length() == 1 && isprint(str[0]))
        return (1);
    return (0);
}

bool is_int(std::string str)
{
    size_t i = 0;
    if (str[i] == '-')
        i++;
    while (i < str.length() && isdigit(str[i]))
        i++;
    return (i == str.length());
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
        is_float_num = 1;
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
        is_float_num = 1;
        return (1);
    }
    return (0);
}

void info_print(char c, int int_num, float fl_num, double dl_num)
{
    std::cout << "char: ";
    if (!isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << c << std::endl;
    std::cout << "int: " << int_num << std::endl;
    std::cout << "float: " << fl_num;
    if (fl_num == floor(fl_num))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << dl_num;
    if (fl_num == floor(fl_num))
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

void    out_int(std::string str)
{
    int int_num = atoi(str.c_str());
    char c;
    if (isprint(int_num))
        c = static_cast<char> (int_num);
    else
        c = 1;
    float fl_num = static_cast<float> (int_num);
    double dl_num = static_cast<double> (int_num);

    info_print(c, int_num, fl_num, dl_num);
}

void out_float(std::string str)
{
    float fl_num = atof(str.c_str());
    int int_num = static_cast<int> (fl_num);
    char c;
    if (isprint(isprint(int_num)))
        c = static_cast<char> (fl_num);
    else
        c = 1;
    double dl_num = static_cast<double> (fl_num);
    info_print(c, int_num, fl_num, dl_num);
}

void out_double(std::string str)
{
    double dl_num = strtod(str.c_str(), NULL);
    int int_num = static_cast<int> (dl_num);
    char c;
    if (isprint(int_num))
        c = static_cast<char> (dl_num);
    else
        c = 1;
    float fl_num = static_cast<float> (dl_num);
    info_print(c, int_num, fl_num, dl_num);
}

// void out_scterm(std::string str)
// {
    
// }

void ScalarConverter::convert(std::string str)
{
    if (is_int(str))
        out_int(str);
    else if (is_float(str) && is_float_num)
        out_float(str);
    else if (is_float(str))
        out_double(str);
    else if (is_char(str))
        out_char(str);
    else if (is_scstr(str))
        std::cout << "is scintifique term" << std::endl;
    else
        std::cout << "chi t5arbi9a" << std::endl;
}