/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:08:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/16 14:53:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class PmergeMe
{
public:
    static const int jacobsthalNumbers[];

    struct Element
    {
        int max;
        Element *big;
        Element *small;
    };

    class UnexpectedValueException : public std::exception
    {
    public:
        UnexpectedValueException();
        virtual ~UnexpectedValueException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    static int stoi(const std::string &str) throw(UnexpectedValueException);
    static Element *newElement(int max, Element *big, Element *small);
    static void deleteElement(Element *ptr);

    PmergeMe();
    PmergeMe(size_t size);
    PmergeMe(const PmergeMe &other);
    virtual ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);

    void addValue(const std::string &str) throw(UnexpectedValueException);
    void printValues() const;
    void printSortedValues() const;

    void analyzeSortingByVector();
    void analyzeSortingByDeque();
    void sort(std::vector<Element *> &vec);
    void sort(std::deque<Element *> &deq);
    void insert(std::vector<Element *> &vec, size_t len, Element *toInsert);
    void insert(std::deque<Element *> &deq, size_t len, Element *toInsert);

private:
    int *values;
    size_t size;
};

#endif