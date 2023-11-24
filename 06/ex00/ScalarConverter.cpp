/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:25:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/24 21:37:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>

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

int ScalarConverter::getScalarType(std::string &str)
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

bool ScalarConverter::isChar(std::string &str)
{
    if (str.size() == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ScalarConverter::isInt(std::string &str)
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

bool ScalarConverter::isFloat(std::string &str)
{
    if (strtolower(str) == "-inff" || strtolower(str) == "+inff" ||
        strtolower(str) == "nanf")
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

bool ScalarConverter::isDouble(std::string &str)
{
    if (strtolower(str) == "-inf" || strtolower(str) == "+inf" ||
        strtolower(str) == "nan")
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

// void ScalarConverter::convert(std::string &literal)
// {
// }