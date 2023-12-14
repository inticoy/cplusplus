/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:23:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/14 20:45:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : values(0), size(0) {}
PmergeMe::PmergeMe(size_t size) : values(new value_t[size]), size(size) {}
PmergeMe::PmergeMe(const PmergeMe &other)
    : values(new value_t[other.size]), size(other.size)
{
}
PmergeMe::~PmergeMe() { delete[] values; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        delete[] values;
        values = new value_t[other.size];
        for (size_t i = 0; i < other.size; ++i)
            values[i] = other.values[i];
        size = other.size;
    }
    return *this;
}

bool PmergeMe::addValue(const std::string &str)
{
    value_t value = stoui(str);
    for (size_t i = 0; i < size; ++i)
    {
        if (values[i] == 0)
        {
            values[i] = value;
            return true;
        }
    }
    return false;
}

void PmergeMe::printValues() const
{
    for (size_t i = 0; i < size; ++i)
        std::cout << values[i] << " ";
}

void PmergeMe::printSortedValues() const
{
    std::vector<unsigned int> vec(values, values + size);
    std::sort(vec.begin(), vec.end());
    for (size_t i = 0; i < size; ++i)
        std::cout << vec.at(i) << " ";
}

unsigned int PmergeMe::stoui(const std::string &str)
{
    unsigned int ui;
    std::stringstream ss(str);
    ss >> ui;
    // TODO: exception like ss.fail();
    return ui;
}
