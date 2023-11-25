/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:25:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 14:32:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    if (this != &other)
    {
    }
    return *this;
}

std::string ScalarConverter::strtolower(const std::string &str)
{
    std::string lower = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        lower += std::tolower(str.at(i));
    }
    return lower;
}

int ScalarConverter::getScalarType(const std::string &str)
{
    if (isChar(str))
    {
        return CHAR;
    }
    else if (isInt(str))
    {
        return INT;
    }
    else if (isFloat(str))
    {
        return FLOAT;
    }
    else if (isDouble(str))
    {
        return DOUBLE;
    }
    else
    {
        return NOT_A_SCALAR;
    }
}

bool ScalarConverter::isChar(const std::string &str)
{
    if (str.size() != 3)
    {
        return false;
    }
    else if (str.at(0) == '\'' && str.at(2) == '\'')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ScalarConverter::isInt(const std::string &str)
{
    int isSigned = (str.at(0) == '+' || str.at(0) == '-') ? 1 : 0;
    int digits = 0;
    size_t idx = isSigned;
    for (; idx < str.length(); idx++)
    {
        if (!std::isdigit(str.at(idx)))
        {
            return false;
        }
        ++digits;
    }
    if (digits > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ScalarConverter::isFloat(const std::string &str)
{
    if (strtolower(str) == "-inff" || strtolower(str) == "+inff" ||
        strtolower(str) == "-nanf" || strtolower(str) == "+nanf" ||
        strtolower(str) == "inff" || strtolower(str) == "nanf")
    {
        return true;
    }

    size_t floatIdx = str.find('f');
    if (floatIdx == std::string::npos || floatIdx != str.length() - 1)
    {
        return false;
    }
    size_t dotIdx = str.find('.');
    if (dotIdx == std::string::npos)
    {
        return false;
    }
    size_t isSigned = (str.at(0) == '+' || str.at(0) == '-') ? 1 : 0;
    size_t idx = isSigned;
    size_t digits = 0;
    std::string integer = str.substr(idx, dotIdx - isSigned);
    std::string decimal = str.substr(dotIdx + 1, str.length() - dotIdx - 2);
    for (size_t i = 0; i < integer.length(); i++)
    {
        if (!std::isdigit(integer.at(i)))
        {
            return false;
        }
        ++digits;
    }
    for (size_t i = 0; i < decimal.length(); i++)
    {
        if (!std::isdigit(decimal.at(i)))
        {
            return false;
        }
        ++digits;
    }
    if (digits > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ScalarConverter::isDouble(const std::string &str)
{
    if (strtolower(str) == "-inf" || strtolower(str) == "+inf" ||
        strtolower(str) == "-nan" || strtolower(str) == "+nan" ||
        strtolower(str) == "inf" || strtolower(str) == "nan")
    {
        return true;
    }

    size_t dotIdx = str.find('.');
    if (dotIdx == std::string::npos)
    {
        return false;
    }
    size_t isSigned = (str.at(0) == '+' || str.at(0) == '-') ? 1 : 0;
    size_t idx = isSigned;
    size_t digits = 0;
    std::string integer = str.substr(idx, dotIdx - isSigned);
    std::string decimal = str.substr(dotIdx + 1, str.length() - dotIdx - 1);
    for (size_t i = 0; i < integer.length(); i++)
    {
        if (!std::isdigit(integer.at(i)))
        {
            return false;
        }
        ++digits;
    }
    for (size_t i = 0; i < decimal.length(); i++)
    {
        if (!std::isdigit(decimal.at(i)))
        {
            return false;
        }
        ++digits;
    }
    if (digits > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ScalarConverter::convert(const std::string &str)
{
    std::cout << std::fixed << std::setprecision(1);
    switch (getScalarType(str))
    {
    case CHAR:
        printAsChar(str);
        break;
    case INT:
        printAsInt(str);
        break;
    case FLOAT:
        printAsFloat(str);
        break;
    case DOUBLE:
        printAsDouble(str);
        break;
    default:
        printNotAScalar(str);
        break;
    }
}

void ScalarConverter::printAsChar(const std::string &str)
{
    std::stringstream ss(str.substr(1, 1));
    char c;
    ss >> c;
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::printAsInt(const std::string &str)
{
    std::stringstream ss(str);
    int i;
    ss >> i;

    if (i > CHAR_MAX || i < CHAR_MIN)
    {
        std::cout << "char:\timpossible" << std::endl;
    }
    else
    {
        printChar(static_cast<char>(i));
    }
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::printAsFloat(const std::string &str)
{
    std::string scalar = str.substr(0, str.size() - 1);
    size_t decimal = scalar.size() - scalar.find('.') - 1;
    std::cout << std::fixed;
    if (decimal > 1)
    {
        std::cout << std::setprecision(decimal);
    }
    std::stringstream ss(scalar);
    float f;
    ss >> f;
    if (f > CHAR_MAX || f < CHAR_MIN || std::isinf(f) || std::isnan(f))
    {
        std::cout << "char:\timpossible" << std::endl;
    }
    else
    {
        printChar(static_cast<char>(f));
    }
    if (f > INT_MAX || f < INT_MIN || std::isinf(f) || std::isnan(f))
    {
        std::cout << "int:\timpossible" << std::endl;
    }
    else
    {
        printInt(static_cast<int>(f));
    }

    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::printAsDouble(const std::string &str)
{
    size_t decimal = str.size() - str.find('.') - 1;
    std::cout << std::fixed;
    if (decimal > 1)
    {
        std::cout << std::setprecision(decimal);
    }
    std::stringstream ss(str);
    double d;
    ss >> d;
    if (d > CHAR_MAX || d < CHAR_MIN || std::isinf(d) || std::isnan(d))
    {
        std::cout << "char:\timpossible" << std::endl;
    }
    else
    {
        printChar(static_cast<char>(d));
    }
    if (d > INT_MAX || d < INT_MIN || std::isinf(d) || std::isnan(d))
    {
        std::cout << "int:\timpossible" << std::endl;
    }
    else
    {
        printInt(static_cast<int>(d));
    }
    printFloat(static_cast<float>(d));
    printDouble(d);
}

void ScalarConverter::printNotAScalar(const std::string &str)
{
    (void)str;
}

void ScalarConverter::printChar(char c)
{
    if (std::isprint(c))
    {
        std::cout << "char:\t'" << c << "'" << std::endl;
    }
    else
    {
        std::cout << "char:\tNon displayable" << std::endl;
    }
}

void ScalarConverter::printInt(int i)
{
    std::cout << "int:\t" << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    std::cout << "float:\t" << f << "f" << std::endl;
}
void ScalarConverter::printDouble(double d)
{
    std::cout << "double:\t" << d << std::endl;
}