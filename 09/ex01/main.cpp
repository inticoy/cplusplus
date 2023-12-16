/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:54:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/16 20:01:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: RPN \"reverse polish notation\"" << '\n';
        return 1;
    }
    else
    {
        try
        {
            std::string input(argv[1]);
            std::cout << RPN::calculate(input) << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
    return 0;
}