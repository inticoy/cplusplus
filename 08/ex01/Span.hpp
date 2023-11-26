/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:48:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/26 18:41:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <set>
#include <string>

class Span
{
  public:
    class DuplicatedSpanException : public std::exception
    {
      public:
        DuplicatedSpanException();
        virtual ~DuplicatedSpanException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    class FullSpanException : public std::exception
    {
      public:
        FullSpanException();
        virtual ~FullSpanException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    class EmptySpanException : public std::exception
    {
      public:
        EmptySpanException();
        virtual ~EmptySpanException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    class SingleSpanException : public std::exception
    {
      public:
        SingleSpanException();
        virtual ~SingleSpanException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    Span();
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();
    Span &operator=(const Span &other);

    void addNumber(int n) throw(FullSpanException, DuplicatedSpanException);
    int shortestSpan() throw(EmptySpanException, SingleSpanException);
    int longestSpan() throw(EmptySpanException, SingleSpanException);

    template <typename Iterator> bool isExist(Iterator begin, Iterator end)
    {
        // need to check itself dup;
        for (Iterator it = begin; it != end; ++it)
        {
            if (set.find(*it) != set.end())
                return true;
        }
        return false;
    }

    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) throw(FullSpanException,
                                                        DuplicatedSpanException)
    {
        size_t size = 0;
        for (Iterator it = begin; it != end; ++it)
        {
            ++size;
        }
        if (set.size() + size > nMax)
            throw FullSpanException();
        else if (isExist(begin, end))
            throw DuplicatedSpanException();
        else
            set.insert(begin, end);
    }

  private:
    unsigned int nMax;
    std::set<int> set;

    // template <typename Iterator> bool isDuplicated(Iterator begin, Iterator
    // end)
    // {
    //     for (Iterator i = begin; i != end; ++i)
    //     {
    //         for (Iterator j = i;)
    //     }
    // }
};

#endif