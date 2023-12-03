/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:20:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 23:00:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <cmath> // isnan && isinf
#include <iostream>
#include <limits>
#include <string>

class Scalar
{
public:
    enum e_scalarType
    {
        NOT_A_SCALAR = 0,
        CHAR = 1,
        INT = 2,
        FLOAT = 3,
        DOUBLE = 4
    };

    static bool hasDigitsOnly(const std::string &str);
    static int getScalarType(const std::string &str);

    static bool isChar(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static bool isDouble(const std::string &str);

    static void printChar(char c, bool isValid);
    static void printInt(int i, bool isValid);
    static void printFloat(float f, bool isValid);
    static void printDouble(double d, bool isValid);

protected:
    Scalar();
    Scalar(const Scalar &other);
    ~Scalar();
    Scalar &operator=(const Scalar &other);

private:
    static std::string strtolower(const std::string &str);
};

#endif