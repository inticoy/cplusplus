/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 17:03:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

bool Scalar::hasDigitsOnly(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str.at(i)))
            return false;
    return true;
}

int Scalar::getScalarType(const std::string &str)
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

bool Scalar::isChar(const std::string &str)
{
    if (str.size() != 3)
        return false;
    else if (str.at(0) == '\'' && str.at(2) == '\'')
        return true;
    else
        return false;
}

bool Scalar::isInt(const std::string &str)
{
    size_t firstDigit = (str.at(0) == '+' || str.at(0) == '-') ? 1 : 0;
    std::string integer = str.substr(firstDigit, str.length() - firstDigit);
    if (!hasDigitsOnly(integer))
        return false;
    else if (integer.length() == 0) // + or - is invalid
        return false;
    else
        return true;
}

bool Scalar::isFloat(const std::string &str)
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

bool Scalar::isDouble(const std::string &str)
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
    if (!hasDigitsOnly(integer) || !hasDigitsOnly(decimal))
        return false;
    else if (integer.length() + decimal.length() == 0) // . is invalid
        return false;
    else
        return true;
}

void Scalar::printChar(char c)
{
    if (std::isprint(c))
        std::cout << "char:\t'" << c << "'" << '\n';
    else
        std::cout << "char:\tNon displayable" << '\n';
}
void Scalar::printInt(int i) { std::cout << "int:\t" << i << '\n'; }
void Scalar::printFloat(float f) { std::cout << "float:\t" << f << "f\n"; }
void Scalar::printDouble(double d) { std::cout << "double:\t" << d << '\n'; }

std::string Scalar::strtolower(const std::string &str)
{
    std::string lower = "";
    for (size_t i = 0; i < str.length(); i++)
        lower += std::tolower(str.at(i));
    return lower;
}

Scalar::Scalar() {}
Scalar::Scalar(const Scalar &other) { (void)other; }
Scalar::~Scalar() {}
Scalar &Scalar::operator=(const Scalar &other)
{
    if (this != &other)
        (void)other;
    return *this;
}