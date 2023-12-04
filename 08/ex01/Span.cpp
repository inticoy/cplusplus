/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:09:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/04 15:36:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : nMax(0), set(std::set<int>()) {}
Span::Span(unsigned int n) : nMax(n), set(std::set<int>()) {}
Span::Span(const Span &other) : nMax(other.nMax), set(std::set<int>(other.set))
{
}
Span::~Span() { set.clear(); }

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        set.clear();
        nMax = other.nMax;
        set = std::set<int>(other.set);
    }
    return *this;
}

size_t Span::getSize() const { return set.size(); }

void Span::addNumber(int n) throw(FullContainerException,
                                  DuplicatedElementException)
{
    if (set.size() == nMax)
        throw FullContainerException();
    else if (!set.insert(n).second)
        throw DuplicatedElementException();
}

int Span::shortestSpan() const
    throw(EmptyContainerException, SingleElementException)
{
    if (set.size() == 0)
        throw EmptyContainerException();
    else if (set.size() == 1)
        throw SingleElementException();
    else
    {
        int min = 0;
        std::set<int>::iterator it = set.begin();
        int prev = *it;
        ++it;
        for (; it != set.end(); ++it)
        {
            if (min == 0 || *it - prev < min)
                min = *it - prev;
            prev = *it;
        }
        return min;
    }
}

int Span::longestSpan() const
    throw(EmptyContainerException, SingleElementException)
{
    if (set.size() == 0)
        throw EmptyContainerException();
    else if (set.size() == 1)
        throw SingleElementException();
    else
    {
        int max = *(--set.end()) - *set.begin();
        return max;
    }
}

void Span::printElements() const
{
    for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
        std::cout << *it << " ";
    std::cout << ", nMax: " << nMax << std::endl;
}
