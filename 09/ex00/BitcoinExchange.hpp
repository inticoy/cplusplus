/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:54:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/12 23:41:26 by gyoon            ###   ########.fr       */
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

    void setDatabase() throw(FileNotFoundException);
    void setDatabase(const std::string &filename) throw(FileNotFoundException);
    void printDatabase() const;
    void exchangeBitcoinByFile(const std::string &filename) throw(
        FileNotFoundException, BadInputException);

private:
    std::map<Date, float> database;

    int stoi(const std::string &s);
    float stof(const std::string &s);
};

#endif