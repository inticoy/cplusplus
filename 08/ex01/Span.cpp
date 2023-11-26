/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:09:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/26 16:42:52 by gyoon            ###   ########.fr       */
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
        return *std::min_element(set.begin(), set.end());
}

int Span::longestSpan() throw(EmptySpanException, SingleSpanException)
{
    if (set.size() == 0)
        throw EmptySpanException();
    else if (set.size() == 1)
        throw SingleSpanException();
    else
        return *std::max_element(set.begin(), set.end());
}
