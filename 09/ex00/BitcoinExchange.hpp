/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:54:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/13 14:44:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Date.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class BitcoinExchange
{
public:
    class FileNotFoundException : public std::exception
    {
    public:
        FileNotFoundException();
        ~FileNotFoundException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };
    class BadDatabaseException : public std::exception
    {
    public:
        BadDatabaseException();
        ~BadDatabaseException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };
    class FloatWrongFormatException : public std::exception
    {
    public:
        FloatWrongFormatException();
        ~FloatWrongFormatException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };
    class BadInputException : public std::exception
    {
    public:
        BadInputException();
        BadInputException(const std::string &detail);
        ~BadInputException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };
    class NoDataException : public std::exception
    {
    public:
        NoDataException();
        NoDataException(const std::string &detail);
        ~NoDataException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };
    class NegativeNumberException : public std::exception
    {
    public:
        NegativeNumberException();
        ~NegativeNumberException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };
    class LargeNumberException : public std::exception
    {
    public:
        LargeNumberException();
        ~LargeNumberException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void setDatabase() throw(FileNotFoundException, BadDatabaseException);
    void setDatabase(const std::string &filename) throw(FileNotFoundException,
                                                        BadDatabaseException);
    void exchangeBitcoin(const std::string &filename) throw(
        FileNotFoundException, BadInputException);

private:
    std::map<Date, float> database;

    float stof(const std::string &s);
    std::vector<std::string> split(const std::string &str, char delimiter);
};

#endif