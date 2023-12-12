/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeException.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:09:09 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/12 21:15:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::FileNotFoundException::FileNotFoundException()
    : msg("file not found")
{
}

BitcoinExchange::FileNotFoundException::~FileNotFoundException() throw() {}

const char *BitcoinExchange::FileNotFoundException::what() const throw()
{
    return msg.c_str();
}

BitcoinExchange::WrongFormatException::WrongFormatException()
    : msg("wrong format")
{
}

BitcoinExchange::WrongFormatException::~WrongFormatException() throw() {}

const char *BitcoinExchange::WrongFormatException::what() const throw()
{
    return msg.c_str();
}
