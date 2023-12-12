/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:04:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/13 00:28:06 by gyoon            ###   ########.fr       */
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

#include <iostream>
Date::Date(const std::string &date) throw(WrongFormatException)
{
    if (std::count(date.begin(), date.end(), '-') != 2)
        throw WrongFormatException();

    std::stringstream ss(date);
    std::string y, m, d;
    unsigned int year, month, day;
    std::getline(ss, y, '-');
    std::getline(ss, m, '-');
    std::getline(ss, d, '-');
    year = stoui(y);
    month = stoui(m);
    day = stoui(d);

    if (!isValidDate(year, month, day))
        throw WrongFormatException();

    this->year = year;
    this->month = month;
    this->day = day;
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
    return false;
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

bool Date::isValidDate(unsigned int year, unsigned int month, unsigned day)
{
    if (year == 0 || month == 0 || month > 12 || day == 0)
        return false;
    else if (isLeapYear(year) && month == 2 && day <= daysInMonth[1] + 1)
        return true;
    else if (day > daysInMonth[month - 1])
        return false;
    return true;
}

unsigned int Date::stoui(const std::string &s) throw(WrongFormatException)
{
    std::stringstream ss(s);
    unsigned int ui;
    ss >> ui;
    // if (ss.fail() || ss.bad() || !ss.eof())
    //     throw WrongFormatException();
    return ui;
}
