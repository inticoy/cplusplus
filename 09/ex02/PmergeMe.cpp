/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:23:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/15 16:54:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : values(NULL), size(0) {}
PmergeMe::PmergeMe(size_t size) : values(new int[size]), size(size) {}
PmergeMe::PmergeMe(const PmergeMe &other)
    : values(new int[other.size]), size(other.size)
{
    for (size_t i = 0; i < other.size; ++i)
        values[i] = other.values[i];
}
PmergeMe::~PmergeMe() { delete[] values; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        delete[] values;
        values = new int[other.size];
        for (size_t i = 0; i < other.size; ++i)
            values[i] = other.values[i];
        size = other.size;
    }
    return *this;
}

bool PmergeMe::addValue(const std::string &str)
{
    int value = stoi(str);
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

int PmergeMe::stoi(const std::string &str)
{
    int i;
    std::stringstream ss(str);
    ss >> i;
    // TODO: exception like ss.fail();
    return i;
}

PmergeMe::Element *PmergeMe::newElement(int max, Element *big, Element *small)
{
    Element *element = new Element();
    element->max = max;
    element->big = big;
    element->small = small;
    return element;
}

void PmergeMe::deleteElement(Element *ptr) { delete ptr; }

void PmergeMe::analyzeSortingByVector()
{
    std::vector<int> sorted(values, values + size);
    std::sort(sorted.begin(), sorted.end());

    std::vector<Element *> vec;
    for (size_t i = 0; i < size; ++i)
        vec.push_back(newElement(values[i], NULL, NULL));

    clock_t before = std::clock();

    sort(vec);

    clock_t after = std::clock();

    for (size_t i = 0; i < vec.size(); ++i)
        if (vec.at(i)->max != sorted.at(i))
            return;

    double time = static_cast<double>(after - before) / CLOCKS_PER_SEC * 1000;

    std::cout << "Time to process a range of " << size << " ";
    std::cout << "elements with std::vector : " << time << "ms";
    std::cout << std::endl;

    std::for_each(vec.begin(), vec.end(), deleteElement);
}

void PmergeMe::analyzeSortingByDeque()
{
    std::deque<int> sorted(values, values + size);
    std::sort(sorted.begin(), sorted.end());

    std::deque<Element *> deq;
    for (size_t i = 0; i < size; ++i)
        deq.push_back(newElement(values[i], NULL, NULL));

    clock_t before = std::clock();

    sort(deq);

    clock_t after = std::clock();

    for (size_t i = 0; i < deq.size(); ++i)
        if (deq.at(i)->max != sorted.at(i))
            return;

    double time = static_cast<double>(after - before) / CLOCKS_PER_SEC * 1000;

    std::cout << "Time to process a range of " << size << " ";
    std::cout << "elements with std::deque : " << time << "ms";
    std::cout << std::endl;

    std::for_each(deq.begin(), deq.end(), deleteElement);
}

void PmergeMe::insert(std::vector<Element *> &vec, size_t len,
                      Element *toInsert)
{
    int start, end, mid, midValue;

    start = 0;
    end = len - 1;

    while (start <= end)
    {
        mid = (start + end) / 2;
        midValue = vec.at(mid)->max;

        if (midValue > toInsert->max)
            end = mid - 1;
        else if (midValue < toInsert->max)
            start = mid + 1;
        else
        {
            vec.insert(vec.begin() + mid, toInsert);
            return;
        }
    }
    vec.insert(vec.begin() + start, toInsert);
}

void PmergeMe::insert(std::deque<Element *> &deq, size_t len, Element *toInsert)
{
    int start, end, mid, midValue;

    start = 0;
    end = len - 1;

    while (start <= end)
    {
        mid = (start + end) / 2;
        midValue = deq.at(mid)->max;

        if (midValue > toInsert->max)
            end = mid - 1;
        else if (midValue < toInsert->max)
            start = mid + 1;
        else
        {
            deq.insert(deq.begin() + mid, toInsert);
            return;
        }
    }
    deq.insert(deq.begin() + start, toInsert);
}

void PmergeMe::sort(std::vector<Element *> &vec)
{
    // 0. FOR RECURSIVE
    if (vec.size() == 1)
        return;

    // 1. MAKE PAIR
    std::vector<Element *> paired;
    Element *pair;
    for (size_t i = 1; i < vec.size(); i += 2)
    {
        if (vec.at(i - 1)->max > vec.at(i)->max)
            pair = newElement(vec.at(i - 1)->max, vec.at(i - 1), vec.at(i));
        else
            pair = newElement(vec.at(i)->max, vec.at(i), vec.at(i - 1));
        paired.push_back(pair);
    };

    // 2. SORT PAIRS RECURSIVELY
    sort(paired);

    // 3. INIT MAIN CHAIN
    std::vector<Element *> sort;
    sort.push_back(paired.at(0)->small);
    for (size_t i = 0; i < paired.size(); ++i)
        sort.push_back(paired.at(i)->big);

    // 4. SORT THE REST
    for (size_t i = 1; i < paired.size(); ++i)
        insert(sort, sort.size(), paired.at(i)->small);
    if (vec.size() % 2 == 1)
        insert(sort, sort.size(), vec.at(vec.size() - 1));

    // 4. DELETE PAIR MEMORIES
    std::for_each(paired.begin(), paired.end(), deleteElement);
    vec = sort;
}

void PmergeMe::sort(std::deque<Element *> &deq)
{
    // 0. FOR RECURSIVE
    if (deq.size() == 1)
        return;

    // 1. MAKE PAIR
    std::deque<Element *> paired;
    Element *pair;
    for (size_t i = 1; i < deq.size(); i += 2)
    {
        if (deq.at(i - 1)->max > deq.at(i)->max)
            pair = newElement(deq.at(i - 1)->max, deq.at(i - 1), deq.at(i));
        else
            pair = newElement(deq.at(i)->max, deq.at(i), deq.at(i - 1));
        paired.push_back(pair);
    };

    // 2. SORT PAIRS RECURSIVELY
    sort(paired);

    // 3. INIT MAIN CHAIN
    std::deque<Element *> sort;
    sort.push_back(paired.at(0)->small);
    for (size_t i = 0; i < paired.size(); ++i)
        sort.push_back(paired.at(i)->big);

    // 4. SORT THE REST
    for (size_t i = 1; i < paired.size(); ++i)
        insert(sort, sort.size(), paired.at(i)->small);
    if (deq.size() % 2 == 1)
        insert(sort, sort.size(), deq.at(deq.size() - 1));

    // 4. DELETE PAIR MEMORIES
    std::for_each(paired.begin(), paired.end(), deleteElement);
    deq = sort;
}
