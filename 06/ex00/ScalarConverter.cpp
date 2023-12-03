/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:25:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 17:10:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
    std::cout << std::fixed << std::setprecision(1);
    switch (Scalar::getScalarType(str))
    {
    case Scalar::CHAR: {
        char c = str.at(1);
        Scalar::printChar(c);
        Scalar::printInt(static_cast<int>(c));
        Scalar::printFloat(static_cast<float>(c));
        Scalar::printDouble(static_cast<double>(c));
        break;
    }
    case Scalar::INT: {
        std::stringstream ss(str);
        int i;
        ss >> i;
        if (ss.fail() || ss.bad() || !ss.eof())
        {
            std::cout << "char:\timpossible\n";
            std::cout << "int:\toverflow\n";
            std::cout << "float:\timpossible\n";
            std::cout << "double:\timpossible\n";
        }
        else
        {
            if (i > CHAR_MAX || i < CHAR_MIN)
                std::cout << "char:\timpossible\n";
            else
                Scalar::printChar(static_cast<char>(i));
            Scalar::printInt(i);
            Scalar::printFloat(static_cast<float>(i));
            Scalar::printDouble(static_cast<double>(i));
        }
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
        {
            std::cout << "char:\timpossible\n";
            std::cout << "int:\timpossible\n";
            std::cout << "float:\toverflow\n";
            std::cout << "double:\timpossible\n";
        }
        else
        {
            if (f > CHAR_MAX || f < CHAR_MIN || std::isinf(f) || std::isnan(f))
                std::cout << "char:\timpossible" << std::endl;
            else
                Scalar::printChar(static_cast<char>(f));
            if (f > INT_MAX || f < INT_MIN || std::isinf(f) || std::isnan(f))
                std::cout << "int:\timpossible" << std::endl;
            else
                Scalar::printInt(static_cast<int>(f));
            Scalar::printFloat(f);
            Scalar::printDouble(static_cast<double>(f));
        }
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
        {
            std::cout << "char:\timpossible\n";
            std::cout << "int:\timpossible\n";
            std::cout << "float:\timpossible\n";
            std::cout << "double:\tovefflow\n";
        }
        else
        {
            if (d > CHAR_MAX || d < CHAR_MIN || std::isinf(d) || std::isnan(d))
                std::cout << "char:\timpossible" << std::endl;
            else
                Scalar::printChar(static_cast<char>(d));
            if (d > INT_MAX || d < INT_MIN || std::isinf(d) || std::isnan(d))
                std::cout << "int:\timpossible" << std::endl;
            else
                Scalar::printInt(static_cast<int>(d));
            Scalar::printFloat(static_cast<float>(d));
            Scalar::printDouble(d);
        }
        break;
    }
    default:
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