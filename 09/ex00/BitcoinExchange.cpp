/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:20:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/12 21:47:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : database(std::map<Date, int>()) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : database(std::map<Date, int>(other.database))
{
}

BitcoinExchange::~BitcoinExchange() { database.clear(); }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        database.clear();
        database = other.database;
    }
    return *this;
}

void BitcoinExchange::setDatabase() throw(FileNotFoundException,
                                          WrongFormatException)
{
    setDatabase("data.csv");
}

// #include <iostream>
void BitcoinExchange::setDatabase(const std::string &filename) throw(
    FileNotFoundException, WrongFormatException)
{
    std::fstream fs;
    fs.open(filename.c_str(), std::ios::in);
    if (!fs.is_open())
        throw FileNotFoundException();

    std::string line;
    std::getline(fs, line);
    // size_t delimIdx = line.find(',');
    // if (!(line.substr(0, line.find(',')) == "date") ||
    //     !(line.substr(line.find(',') + 1, line.size() - line.find(',')) ==
    //       "exchange_rate"))
    //     throw WrongFormatException();

    while (std::getline(fs, line))
    {
        // check;
    }
}

void BitcoinExchange::exchangeBitcoinByFile(const std::string &filename) const
    throw(FileNotFoundException, WrongFormatException)
{
    std::fstream fs;
    fs.open(filename.c_str(), std::ios::in);
    if (!fs.is_open())
        throw FileNotFoundException();
}