/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:23:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/15 15:23:56 by gyoon            ###   ########.fr       */
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
    std::vector<value_t> sorted(values, values + size);
    std::sort(sorted.begin(), sorted.end());

    std::vector<Element *> vec;
    for (size_t i = 0; i < size; ++i)
        vec.push_back(newElement(values[i]));

    clock_t before = std::clock();
    sortByVector(vec);
    clock_t after = std::clock();
    std::cout << before << " " << after << std::endl;

    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec.at(i)->largest != sorted.at(i))
            return;
    }

    double time = static_cast<double>(after - before) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << size << " ";
    std::cout << "elements with std::vector : " << time << "ms";
    std::cout << std::endl;
    deleteVector(vec);
}

void PmergeMe::insertInVector(std::vector<Element *> &vec, size_t len,
                              Element *toInsert)
{

    int start = 0, end = len - 1;
    int mid;
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
    // std::cout << std::endl << "sorting : ";
    // for (size_t i = 0; i < vec.size(); ++i)
    //     std::cout << vec.at(i)->largest << " ";
    // std::cout << std::endl;

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

    std::vector<Element *> sorted;

    sorted.push_back(paired.at(0)->small);
    for (size_t i = 0; i < paired.size(); ++i)
        sorted.push_back(paired.at(i)->big);

    for (size_t i = 1; i < paired.size(); ++i)
        insertInVector(sorted, sorted.size(), paired.at(i)->small);

    if (vec.size() % 2 == 1)
        insertInVector(sorted, sorted.size(), vec.at(vec.size() - 1));

    deleteVector(paired);
    vec = sorted;
    // n_half;
}

void PmergeMe::deleteVector(std::vector<Element *> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        delete vec.at(i);
}

///////////////////////// list

void PmergeMe::analyzeSortByList()
{
    std::vector<value_t> sorted(values, values + size);
    std::sort(sorted.begin(), sorted.end());

    std::list<Element *> lst;
    for (size_t i = 0; i < size; ++i)
        lst.push_back(newElement(values[i]));

    clock_t before = std::clock();
    sortByList(lst);
    clock_t after = std::clock();

    for (size_t i = 0; i < lst.size(); ++i)
    {
        if ((*std::next(lst.begin(), i))->largest != (sorted.at(i)))
        {
            std::cout << "lst: " << (*std::next(lst.begin(), i))->largest;
            std::cout << " sort: " << sorted.at(i) << std::endl;
            return;
        }
    }

    double time = static_cast<double>(after - before) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << size << " ";
    std::cout << "elements with std::list : " << time << "ms";
    std::cout << std::endl;
    deleteList(lst);
}

void PmergeMe::insertInList(std::list<Element *> &lst, size_t len,
                            Element *toInsert)
{

    int start = 0, end = len - 1;
    int mid;
    value_t midValue;

    while (start <= end)
    {
        mid = (start + end) / 2;
        midValue = (*std::next(lst.begin(), mid))->largest;
        if (midValue > toInsert->largest)
            end = mid - 1;
        else if (midValue < toInsert->largest)
            start = mid + 1;
        else
        {
            lst.insert(std::next(lst.begin(), mid), toInsert);
            return;
        }
    }
    lst.insert(std::next(lst.begin(), start), toInsert);
}

void PmergeMe::sortByList(std::list<Element *> &lst) // in ascending order
{
    // std::cout << std::endl << "sorting : ";
    // for (size_t i = 0; i < vec.size(); ++i)
    //     std::cout << vec.at(i)->largest << " ";
    // std::cout << std::endl;

    if (lst.size() == 1)
        return;

    std::list<Element *> paired;
    for (size_t i = 1; i < lst.size(); i += 2)
    {
        Element *pair = new Element;
        if ((*std::next(lst.begin(), i - 1))->largest >
            (*std::next(lst.begin(), i))->largest)
        {
            pair->largest = (*std::next(lst.begin(), i - 1))->largest;
            pair->big = (*std::next(lst.begin(), i - 1));
            pair->small = (*std::next(lst.begin(), i));
        }
        else
        {
            pair->largest = (*std::next(lst.begin(), i))->largest;
            pair->big = (*std::next(lst.begin(), i));
            pair->small = (*std::next(lst.begin(), i - 1));
        }
        paired.push_back(pair);
    };

    sortByList(paired);

    std::list<Element *> sorted;

    sorted.push_back((*std::next(paired.begin(), 0))->small);
    for (size_t i = 0; i < paired.size(); ++i)
        sorted.push_back((*std::next(paired.begin(), i))->big);

    for (size_t i = 1; i < paired.size(); ++i)
        insertInList(sorted, sorted.size(),
                     (*std::next(paired.begin(), i))->small);

    if (lst.size() % 2 == 1)
        insertInList(sorted, sorted.size(),
                     (*std::next(lst.begin(), lst.size() - 1)));

    deleteList(paired);
    lst = sorted;
    // n_half;
}

void PmergeMe::deleteList(std::list<Element *> &lst)
{
    for (size_t i = 0; i < lst.size(); ++i)
        delete *std::next(lst.begin(), i);
}
