/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:19:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/24 21:32:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "error: invalid argument\n";
        return -1;
    }
    else
    {
        std::string literal(argv[1]);
        std::cout << ScalarConverter::getScalarType(literal) << std::endl;
        // std::cout << ScalarConverter::convertChar(literal) << std::endl;
        // std::cout << ScalarConverter::convertInt(literal) << std::endl;
        // std::cout << ScalarConverter::convertFloat(literal) << std::endl;
        // std::cout << ScalarConverter::convertDouble(literal) << std::endl;
        return 0;
    }
}