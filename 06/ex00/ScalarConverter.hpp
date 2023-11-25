/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:23:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 14:25:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter
{
  public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &other);

    enum scalarType
    {
        NOT_A_SCALAR = 0,
        CHAR = 1,
        INT = 2,
        FLOAT = 3,
        DOUBLE = 4
    };

    static int getScalarType(const std::string &str);
    static bool isChar(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static bool isDouble(const std::string &str);

    static std::string strtolower(const std::string &str);
    static void convert(const std::string &str);

    static void printAsChar(const std::string &str);
    static void printAsInt(const std::string &str);
    static void printAsFloat(const std::string &str);
    static void printAsDouble(const std::string &str);
    static void printNotAScalar(const std::string &str);

    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

  private:
};

#endif