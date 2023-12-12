/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:20:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/13 00:13:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : database(std::map<Date, float>()) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : database(std::map<Date, float>(other.database))
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

void BitcoinExchange::setDatabase() throw(FileNotFoundException)
{
    setDatabase("data.csv");
}

void BitcoinExchange::setDatabase(const std::string &filename) throw(
    FileNotFoundException)
{
    std::fstream fs;
    fs.open(filename.c_str(), std::ios::in);
    if (!fs.is_open())
        throw FileNotFoundException();

    std::string line;
    std::getline(fs, line);

    while (std::getline(fs, line))
    {
        std::stringstream ss(line);
        std::string date, exchangeRate;
        std::getline(ss, date, ',');
        std::getline(ss, exchangeRate, ',');

        Date d(date);

        float rate = stof(exchangeRate);

        database.insert(std::pair<Date, float>(d, rate));
    }
}

void BitcoinExchange::printDatabase() const
{
    // std::cout << database << std::endl;
}

void BitcoinExchange::exchangeBitcoinByFile(const std::string &filename) throw(
    FileNotFoundException, BadInputException)
{
    std::fstream fs;
    fs.open(filename.c_str(), std::ios::in);
    if (!fs.is_open())
        throw FileNotFoundException();

    std::string line;
    std::getline(fs, line);

    while (std::getline(fs, line))
    {
        try
        {
            if (std::count(line.begin(), line.end(), '|') != 1)
                throw BadInputException(line);

            std::stringstream ss(line);
            std::string date, value;
            std::getline(ss, date, '|');
            std::getline(ss, value, '|');
            Date d(date);
            float v = stof(value);

            if (v < 0)
                throw NegativeNumberException();
            else if (v > 1000)
                throw LargeNumberException();

            std::map<Date, float>::iterator it = database.upper_bound(d);

            std::cout << date << " | " << value << " = "
                      << (*(--it)).second * v;
            std::cout << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << '\n';
        }
    }
}

int BitcoinExchange::stoi(const std::string &s)
{
    std::stringstream ss(s);
    int i;
    ss >> i;
    // if (ss.fail() || ss.bad() || !ss.eof())
    //     throw WrongFormatException();
    return i;
}

float BitcoinExchange::stof(const std::string &s)
{
    std::stringstream ss(s);
    float f;
    ss >> f;
    // if (ss.fail() || ss.bad() || !ss.eof())
    //     throw WrongFormatException();
    return f;
}