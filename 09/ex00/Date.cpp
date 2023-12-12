/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:04:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/12 16:01:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

const unsigned int Date::daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                                            31, 31, 30, 31, 30, 31};

Date::Date() : year(1900), month(1), day(1) {}

Date::Date(const Date &other)
    : year(other.year), month(other.month), day(other.day)
{
}

Date::Date(unsigned int year, unsigned int month, unsigned day)
    : year(year), month(month), day(day)
{
    unsigned int isLeap = static_cast<unsigned int>(isLeapYear(year));

    if (year == 0 || month == 0 || month > 12 || day == 0)
        throw WrongFormatException();
    else if (month == 2 && day > daysInMonth[2] + isLeap)
        throw WrongFormatException();
    else if (day > daysInMonth[month])
        throw WrongFormatException();
}

Date::~Date() {}

Date &Date::operator=(const Date &other)
{
    if (this != &other)
    {
        year = other.year;
        month = other.month;
        day = other.day;
    }
    return *this;
}

bool Date::operator<(const Date &rhs) const
{
    if (year != rhs.year)
        return year < rhs.year;
    else if (month != rhs.month)
        return month < rhs.month;
    else if (day != rhs.day)
        return day < rhs.day;
    return true;
}

bool Date::isLeapYear(unsigned int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;
}
