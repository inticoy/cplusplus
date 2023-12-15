/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:23:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/15 14:11:42 by gyoon            ###   ########.fr       */
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

PmergeMe::Element *PmergeMe::newElement(value_t value)
{
    Element *element = new Element();
    element->largest = value;
    element->big = NULL;
    element->small = NULL;
    return element;
}

void PmergeMe::analyzeSortByVector()
{
    std::vector<Element *> vec;
    for (size_t i = 0; i < size; ++i)
        vec.push_back(newElement(values[i]));

    std::cout << "before : ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec.at(i)->largest << " ";
    std::cout << std::endl;

    sortByVector(vec);

    std::cout << "after : ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec.at(i)->largest << " ";
    std::cout << std::endl;
    deleteVector(vec);
}

void PmergeMe::insertInVector(std::vector<Element *> &vec, size_t len,
                              Element *toInsert)
{
    size_t start = 0, end = len - 1;
    size_t mid;
    value_t midValue;

    while (start <= end)
    {
        mid = (start + end) / 2;
        midValue = (*std::next(vec.begin(), mid))->largest;
        if (midValue > toInsert->largest)
            end = mid - 1;
        else if (midValue < toInsert->largest)
            start = mid + 1;
        else
        {
            vec.insert(vec.begin() + mid, toInsert);
            return;
        }
    }
    vec.insert(vec.begin() + start, toInsert);
}

void PmergeMe::sortByVector(std::vector<Element *> &vec) // in ascending order
{
    std::cout << std::endl << "sorting : ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec.at(i)->largest << " ";
    std::cout << std::endl;

    if (vec.size() == 1)
        return;

    std::vector<Element *> paired;
    for (size_t i = 1; i < vec.size(); i += 2)
    {
        Element *pair = new Element;
        if (vec.at(i - 1)->largest > vec.at(i)->largest)
        {
            pair->largest = vec.at(i - 1)->largest;
            pair->big = vec.at(i - 1);
            pair->small = vec.at(i);
        }
        else
        {
            pair->largest = vec.at(i)->largest;
            pair->big = vec.at(i);
            pair->small = vec.at(i - 1);
        }
        paired.push_back(pair);
    };

    sortByVector(paired);

    std::cout << "finish sorting paired" << std::endl;

    std::vector<Element *> sorted;

    std::cout << "<1>";
    sorted.push_back(paired.at(0)->small);
    for (size_t i = 0; i < paired.size(); ++i)
        sorted.push_back(paired.at(i)->big);

    std::cout << "<2>";
    for (size_t i = 1; i < paired.size(); ++i)
        insertInVector(sorted, sorted.size(), paired.at(i)->small);

    std::cout << "<3>";
    if (vec.size() % 2 == 1)
        insertInVector(sorted, sorted.size(), vec.at(vec.size() - 1));

    std::cout << "<4>";
    deleteVector(paired);
    vec = sorted;
    // n_half;
}

void PmergeMe::deleteVector(std::vector<Element *> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        delete vec.at(i);
}