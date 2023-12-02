/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:25:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/02 11:05:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
        (void)other;
    return *this;
}

std::string ScalarConverter::strtolower(const std::string &str)
{
    std::string lower = "";
    for (size_t i = 0; i < str.length(); i++)
        lower += std::tolower(str.at(i));
    return lower;
}

bool ScalarConverter::isDigitsOnly(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str.at(i)))
            return false;
    return true;
}

int ScalarConverter::getScalarType(const std::string &str)
{
    if (isChar(str))
        return CHAR;
    else if (isInt(str))
        return INT;
    else if (isFloat(str))
        return FLOAT;
    else if (isDouble(str))
        return DOUBLE;
    else
        return NOT_A_SCALAR;
}

bool ScalarConverter::isChar(const std::string &str)
{
    if (str.size() != 3)
        return false;
    else if (str.at(0) == '\'' && str.at(2) == '\'')
        return true;
    else
        return false;
}

bool ScalarConverter::isInt(const std::string &str)
{
    size_t firstDigit = (str.at(0) == '+' || str.at(0) == '-') ? 1 : 0;
    std::string integer = str.substr(firstDigit, str.length() - firstDigit);
    if (!isDigitsOnly(integer))
        return false;
    else if (integer.length() == 0) // + or - is invalid
        return false;
    else
        return true;
}

bool ScalarConverter::isFloat(const std::string &str)
{
    // scalar float needs 'f' at last
    size_t floatIdx = str.find('f');
    bool fNotFound = (floatIdx == std::string::npos);
    bool fNotEndChar = (floatIdx != str.length() - 1);
    if (fNotFound || fNotEndChar)
        return false;

    // float without f is same as double
    std::string number = str.substr(0, str.length() - 1);
    return isDouble(number);
}

bool ScalarConverter::isDouble(const std::string &str)
{
    if (strtolower(str) == "-inf" || strtolower(str) == "+inf" ||
        strtolower(str) == "-nan" || strtolower(str) == "+nan" ||
        strtolower(str) == "inf" || strtolower(str) == "nan")
        return true;

    // scalar double needs a dot
    size_t dotIdx = str.find('.');
    bool dotNotFound = (dotIdx == std::string::npos);
    if (dotNotFound)
        return false;

    size_t firstDigit = (str.at(0) == '+' || str.at(0) == '-') ? 1 : 0;
    std::string integer = str.substr(firstDigit, dotIdx - firstDigit);
    std::string decimal = str.substr(dotIdx + 1, str.length() - dotIdx - 1);
    if (!isDigitsOnly(integer) || !isDigitsOnly(decimal))
        return false;
    else if (integer.length() + decimal.length() == 0) // . is invalid
        return false;
    else
        return true;
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
    char c = str.at(1);
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::printAsInt(const std::string &str)
{
    // TODO : int overflow
    std::stringstream ss(str);
    int i;
    ss >> i;

    // overflow
    if (ss.fail() || ss.bad() || !ss.eof())
    {
    }

    if (i > CHAR_MAX || i < CHAR_MIN)
        std::cout << "char:\timpossible" << std::endl;
    else
        printChar(static_cast<char>(i));
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
        std::cout << std::setprecision(decimal);

    std::stringstream ss(scalar);
    float f;
    ss >> f;
    if (f > std::numeric_limits<char>::min() ||
        f < std::numeric_limits<char>::max() || std::isinf(f) || std::isnan(f))
        std::cout << "char:\timpossible" << std::endl;
    else
        printChar(static_cast<char>(f));
    if (f > INT_MAX || f < INT_MIN || std::isinf(f) || std::isnan(f))
        std::cout << "int:\timpossible" << std::endl;
    else
        printInt(static_cast<int>(f));
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::printAsDouble(const std::string &str)
{
    size_t decimal = str.size() - str.find('.') - 1;
    std::cout << std::fixed;
    if (decimal > 1)
        std::cout << std::setprecision(decimal);

    std::stringstream ss(str);
    double d;
    ss >> d;
    if (d > CHAR_MAX || d < CHAR_MIN || std::isinf(d) || std::isnan(d))
        std::cout << "char:\timpossible" << std::endl;
    else
        printChar(static_cast<char>(d));
    if (d > INT_MAX || d < INT_MIN || std::isinf(d) || std::isnan(d))
        std::cout << "int:\timpossible" << std::endl;
    else
        printInt(static_cast<int>(d));
    printFloat(static_cast<float>(d));
    printDouble(d);
}

void ScalarConverter::printNotAScalar(const std::string &str) { (void)str; }

void ScalarConverter::printChar(char c)
{
    if (std::isprint(c))
        std::cout << "char:\t'" << c << "'" << '\n';
    else
        std::cout << "char:\tNon displayable" << '\n';
}

void ScalarConverter::printInt(int i) { std::cout << "int:\t" << i << '\n'; }

void ScalarConverter::printFloat(float f)
{
    std::cout << "float:\t" << f << "f" << '\n';
}
void ScalarConverter::printDouble(double d)
{
    std::cout << "double:\t" << d << '\n';
}