/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeException.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:09:09 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/17 11:02:41 by gyoon            ###   ########.fr       */
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

BitcoinExchange::BadDatabaseException::BadDatabaseException()
    : msg("bad database")
{
}
BitcoinExchange::BadDatabaseException::~BadDatabaseException() throw() {}
const char *BitcoinExchange::BadDatabaseException::what() const throw()
{
    return msg.c_str();
}

BitcoinExchange::FloatWrongFormatException::FloatWrongFormatException()
    : msg("float wrong format")
{
}
BitcoinExchange::FloatWrongFormatException::~FloatWrongFormatException() throw()
{
}
const char *BitcoinExchange::FloatWrongFormatException::what() const throw()
{
    return msg.c_str();
}

BitcoinExchange::BadInputException::BadInputException() : msg("bad input") {}
BitcoinExchange::BadInputException::BadInputException(const std::string &detail)
    : msg("bad input => " + detail)
{
}
BitcoinExchange::BadInputException::~BadInputException() throw() {}
const char *BitcoinExchange::BadInputException::what() const throw()
{
    return msg.c_str();
}

BitcoinExchange::NoDataException::NoDataException() : msg("no data in database")
{
}
BitcoinExchange::NoDataException::NoDataException(const std::string &detail)
    : msg("no data in database => " + detail)
{
}
BitcoinExchange::NoDataException::~NoDataException() throw() {}
const char *BitcoinExchange::NoDataException::what() const throw()
{
    return msg.c_str();
}

BitcoinExchange::NegativeNumberException::NegativeNumberException()
    : msg("not a positive number.")
{
}
BitcoinExchange::NegativeNumberException::~NegativeNumberException() throw() {}
const char *BitcoinExchange::NegativeNumberException::what() const throw()
{
    return msg.c_str();
}

BitcoinExchange::LargeNumberException::LargeNumberException()
    : msg("too large number.")
{
}
BitcoinExchange::LargeNumberException::~LargeNumberException() throw() {}
const char *BitcoinExchange::LargeNumberException::what() const throw()
{
    return msg.c_str();
}