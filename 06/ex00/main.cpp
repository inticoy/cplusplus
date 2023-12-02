/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:19:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 17:37:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "error: invalid argument" << '\n';
        return -1;
    }
    else
    {
        std::string scalar(argv[1]);
        ScalarConverter::convert(scalar);
        return 0;
    }
}