/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:20:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/17 13:04:35 by gyoon            ###   ########.fr       */
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

void BitcoinExchange::setDatabase() throw(FileNotFoundException,
                                          BadDatabaseException)
{
    setDatabase("data.csv");
}

void BitcoinExchange::setDatabase(const std::string &filename) throw(
    FileNotFoundException, BadDatabaseException)
{
    std::fstream fs;
    fs.open(filename.c_str(), std::ios::in);
    if (!fs.is_open())
        throw FileNotFoundException();

    std::string line;
    std::getline(fs, line);
    if (line.find(',') == std::string::npos)
        throw BadDatabaseException();

    line.replace(line.find(','), 1, " ");
    std::string part1, part2;
    std::stringstream ss(line);
    ss >> part1 >> part2;

    if (!ss.eof() || part1 != "date" || part2 != "exchange_rate")
        throw BadDatabaseException();

    while (std::getline(fs, line))
    {
        try
        {
            if (line.find(',') == std::string::npos)
                throw BadDatabaseException();

            line.replace(line.find(','), 1, " ");
            part1.clear();
            part2.clear();
            std::stringstream ss(line);
            ss >> part1 >> part2;

            if (!ss.eof())
                throw BadDatabaseException();

            Date d(part1);
            float rate = stof(part2);
            if (!(database.insert(std::pair<Date, float>(d, rate)).second))
                throw BadDatabaseException();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void BitcoinExchange::exchangeBitcoin(const std::string &filename) throw(
    FileNotFoundException, BadInputException)
{
    std::fstream fs;
    fs.open(filename.c_str(), std::ios::in);
    if (!fs.is_open())
        throw FileNotFoundException();

    std::string line;
    std::getline(fs, line);

    std::string part1, part2, part3;
    std::stringstream ss(line);
    ss >> part1 >> part2 >> part3;

    if (!ss.eof() || part1 != "date" || part2 != "|" || part3 != "value")
        throw BadInputException();

    while (std::getline(fs, line))
    {
        try
        {
            std::stringstream ss(line);
            part1.clear();
            part2.clear();
            part3.clear();
            ss >> part1 >> part2 >> part3;

            if (!ss.eof() || part2 != "|")
                throw BadInputException(line);

            Date d(part1);
            float v = stof(part3);

            if (d < (*database.begin()).first)
                throw NoDataException(part1);
            else if (v < 0)
                throw NegativeNumberException();
            else if (v > 1000)
                throw LargeNumberException();

            std::cout << line << " = ";
            std::cout << (*(--database.upper_bound(d))).second * v;
            std::cout << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << '\n';
        }
    }
}

float BitcoinExchange::stof(const std::string &s)
{
    std::stringstream ss(s);
    float f;
    ss >> f;
    if (ss.fail() || ss.bad() || !ss.eof())
        throw FloatWrongFormatException();
    return f;
}
