/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:25:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 22:45:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
    bool isValid = true;
    std::cout << std::fixed << std::setprecision(1);
    switch (Scalar::getScalarType(str))
    {
    case Scalar::CHAR: {
        char c = str.at(1);
        Scalar::printChar(c, isValid);
        Scalar::printInt(static_cast<int>(c), isValid);
        Scalar::printFloat(static_cast<float>(c), isValid);
        Scalar::printDouble(static_cast<double>(c), isValid);
        break;
    }
    case Scalar::INT: {
        std::stringstream ss(str);
        int i;
        ss >> i;
        if (ss.fail() || ss.bad() || !ss.eof())
            isValid = false;

        if (i > std::numeric_limits<char>::max() ||
            i < std::numeric_limits<char>::min())
            Scalar::printChar(static_cast<char>(i), false);
        else
            Scalar::printChar(static_cast<char>(i), isValid);
        Scalar::printInt(i, isValid);
        Scalar::printFloat(static_cast<float>(i), isValid);
        Scalar::printDouble(static_cast<double>(i), isValid);
        break;
    }
    case Scalar::FLOAT: {
        std::string scalar = str.substr(0, str.size() - 1);
        size_t decimal = scalar.size() - scalar.find('.') - 1;
        if (decimal > 1)
            std::cout << std::setprecision(decimal);

        std::stringstream ss(scalar);
        float f;
        ss >> f;
        if (ss.fail() || ss.bad() || !ss.eof())
            isValid = false;

        if (f > std::numeric_limits<char>::max() || std::isinf(f) ||
            f < std::numeric_limits<char>::min() || std::isnan(f))
            Scalar::printChar(static_cast<char>(f), false);
        else
            Scalar::printChar(static_cast<char>(f), isValid);

        if (f > std::numeric_limits<int>::max() || std::isinf(f) ||
            f < std::numeric_limits<int>::min() || std::isnan(f))
            Scalar::printInt(static_cast<int>(f), false);
        else
            Scalar::printInt(static_cast<int>(f), isValid);
        Scalar::printFloat(f, isValid);
        Scalar::printDouble(static_cast<double>(f), isValid);
        break;
    }
    case Scalar::DOUBLE: {
        size_t decimal = str.size() - str.find('.') - 1;
        if (decimal > 1)
            std::cout << std::setprecision(decimal);

        std::stringstream ss(str);
        double d;
        ss >> d;
        if (ss.fail() || ss.bad() || !ss.eof())
            isValid = false;

        if (d > std::numeric_limits<char>::max() || std::isinf(d) ||
            d < std::numeric_limits<char>::min() || std::isnan(d))
            Scalar::printChar(static_cast<char>(d), false);
        else
            Scalar::printChar(static_cast<char>(d), isValid);
        if (d > std::numeric_limits<int>::max() || std::isinf(d) ||
            d < std::numeric_limits<int>::min() || std::isnan(d))
            Scalar::printInt(static_cast<int>(d), false);
        else
            Scalar::printInt(static_cast<int>(d), isValid);
        Scalar::printFloat(static_cast<float>(d), isValid);
        Scalar::printDouble(d, isValid);
        break;
    }
    default:
        std::cout << str << " is a not scalar\n";
        break;
    }
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
        (void)other;
    return *this;
}