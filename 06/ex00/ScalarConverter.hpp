/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:23:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/24 21:31:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

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

    static int getScalarType(std::string &str);
    static bool isChar(std::string &str);
    static bool isInt(std::string &str);
    static bool isFloat(std::string &str);
    static bool isDouble(std::string &str);

    static std::string strtolower(const std::string &str);
    // static void convert(std::string &str);

    // static char convertChar(std::string &str);
    // static int convertInt(std::string &str);
    // static float convertFloat(std::string &str);
    // static double convertDouble(std::string &str);

  private:
};

#endif