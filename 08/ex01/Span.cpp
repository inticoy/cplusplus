/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:09:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/26 18:15:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : nMax(0), set(std::set<int>())
{
}

Span::Span(unsigned int n) : nMax(n), set(std::set<int>())
{
}

Span::Span(const Span &other) : nMax(other.nMax), set(std::set<int>(other.set))
{
}

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

Span::~Span()
{
    set.clear();
}

void Span::addNumber(int n) throw(FullSpanException, DuplicatedSpanException)
{
    if (set.size() == nMax)
        throw FullSpanException();
    else if (!set.insert(n).second)
        throw DuplicatedSpanException();
}

int Span::shortestSpan() throw(EmptySpanException, SingleSpanException)
{
    if (set.size() == 0)
        throw EmptySpanException();
    else if (set.size() == 1)
        throw SingleSpanException();
    else
    {
        int min = 0;
        int prev = *set.begin();
        std::set<int>::iterator it = set.begin();
        ++it;
        for (; it != set.end(); ++it)
        {
            if (min == 0 || *it - prev < min)
            {
                min = *it - prev;
            }
            prev = *it;
        }
        return min;
    }
}

int Span::longestSpan() throw(EmptySpanException, SingleSpanException)
{
    if (set.size() == 0)
        throw EmptySpanException();
    else if (set.size() == 1)
        throw SingleSpanException();
    else
    {
        int max = *--set.end() - *set.begin();
        return max;
    }
}