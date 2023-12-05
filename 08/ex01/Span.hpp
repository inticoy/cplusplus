/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:48:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/05 14:22:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

class Span
{
public:
    class DuplicatedElementException : public std::exception
    {
    public:
        DuplicatedElementException();
        virtual ~DuplicatedElementException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    class FullContainerException : public std::exception
    {
    public:
        FullContainerException();
        virtual ~FullContainerException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    class EmptyContainerException : public std::exception
    {
    public:
        EmptyContainerException();
        virtual ~EmptyContainerException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    class SingleElementException : public std::exception
    {
    public:
        SingleElementException();
        virtual ~SingleElementException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    class WrongUsageException : public std::exception
    {
    public:
        WrongUsageException();
        virtual ~WrongUsageException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    Span();
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();
    Span &operator=(const Span &other);

    size_t getSize() const;
    void addNumber(int n) throw(FullContainerException,
                                DuplicatedElementException);
    int shortestSpan() const
        throw(EmptyContainerException, SingleElementException);
    int longestSpan() const
        throw(EmptyContainerException, SingleElementException);
    void printElements() const;

    template <typename Iterator>
    void addNumbers(Iterator begin,
                    Iterator end) throw(FullContainerException,
                                        DuplicatedElementException,
                                        WrongUsageException)
    {
        if (end - begin < 0)
            throw WrongUsageException();
        else if (isDuplicated(begin, end))
            throw DuplicatedElementException();
        else if (set.size() + (end - begin) > nMax)
            throw FullContainerException();
        else if (isExist(begin, end))
            throw DuplicatedElementException();
        else
            set.insert(begin, end);
    }

private:
    unsigned int nMax;
    std::set<int> set;

    template <typename Iterator>
    bool isExist(Iterator begin, Iterator end) const
    {
        for (Iterator it = begin; it != end; ++it)
        {
            if (set.find(*it) != set.end())
                return true;
        }
        return false;
    }

    template <typename Iterator>
    bool isDuplicated(Iterator begin, Iterator end) const
    {
        Iterator beforeEnd = end - 1;
        for (Iterator i = begin; i != beforeEnd; ++i)
            for (Iterator j = i + 1; j != end; ++j)
                if (*i == *j)
                    return true;
        return false;
    }
};

#endif