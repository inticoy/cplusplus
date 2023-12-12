/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:54:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/13 00:28:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: btc [input file]" << std::endl;
        return 1;
    }
    else
    {
        try
        {
            BitcoinExchange bitcoinExchange;
            std::string inputFile = std::string(argv[1]);
            bitcoinExchange.setDatabase();
            bitcoinExchange.printDatabase();
            bitcoinExchange.exchangeBitcoinByFile(inputFile);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}