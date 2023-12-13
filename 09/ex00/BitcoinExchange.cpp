/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:20:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/13 14:44:42 by gyoon            ###   ########.fr       */
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
    std::vector<std::string> head = split(line, ',');
    if (head.size() != 2 || head[0] != "date" || head[1] != "exchange_rate")
        throw BadDatabaseException();

    while (std::getline(fs, line))
    {
        try
        {
            std::vector<std::string> contents = split(line, ',');
            if (contents.size() != 2)
                throw BadDatabaseException();

            Date d(contents[0]);
            float rate = stof(contents[1]);
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
    std::vector<std::string> head = split(line, '|');
    if (head.size() != 2 || head[0] != "date" || head[1] != "value")
        throw BadInputException(line);

    while (std::getline(fs, line))
    {
        try
        {
            std::vector<std::string> contents = split(line, '|');
            if (head.size() != 2)
                throw BadInputException(line);

            Date d(contents[0]);
            float v = stof(contents[1]);

            if (d < (*database.begin()).first)
                throw NoDataException(contents[0]);
            else if (v < 0)
                throw NegativeNumberException();
            else if (v > 1000)
                throw LargeNumberException();

            std::cout << contents[0] << " | " << contents[1] << " = ";
            std::cout << (*(--database.upper_bound(d))).second * v;
            std::cout << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << '\n';
        }
    }
}

// int BitcoinExchange::stoi(const std::string &s)
// {
//     std::stringstream ss(s);
//     int i;
//     ss >> i;
//     // if (ss.fail() || ss.bad() || !ss.eof())
//     //     throw WrongFormatException();
//     return i;
// }

float BitcoinExchange::stof(const std::string &s)
{
    std::stringstream ss(s);
    float f;
    ss >> f;
    if (ss.fail() || ss.bad() || !ss.eof())
        throw FloatWrongFormatException();
    return f;
}

std::vector<std::string> BitcoinExchange::split(const std::string &str,
                                                char delimiter)
{
    std::vector<std::string> vec;
    std::stringstream ss(str);
    std::string section;
    while (std::getline(ss, section, delimiter))
    {
        std::stringstream sector(section);
        std::string trimmed;
        sector >> trimmed;
        vec.push_back(trimmed);
    }
    return vec;
}
