/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:18:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/12 21:15:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

#include <exception>
#include <string>

class Date
{
public:
    class WrongFormatException : public std::exception
    {
    public:
        WrongFormatException();
        ~WrongFormatException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    Date();
    Date(const Date &other);
    Date(unsigned int year, unsigned int month, unsigned day);
    ~Date();
    Date &operator=(const Date &other);
    bool operator<(const Date &rhs) const;

    static bool isLeapYear(unsigned int year);

private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

    static const unsigned int daysInMonth[12];
};

#endif
