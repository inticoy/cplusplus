/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:54:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/12 21:33:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Date.hpp"
#include <exception>
#include <fstream>
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

    class WrongFormatException : public std::exception
    {
    public:
        WrongFormatException();
        ~WrongFormatException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void setDatabase() throw(FileNotFoundException, WrongFormatException);
    void setDatabase(const std::string &filename) throw(FileNotFoundException,
                                                        WrongFormatException);
    void exchangeBitcoinByFile(const std::string &filename) const
        throw(FileNotFoundException, WrongFormatException);

private:
    std::map<Date, int> database;
};

#endif