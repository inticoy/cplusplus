/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:08:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/15 15:55:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm> // std::sort
#include <ctime>     // std::clock
#include <deque>     // std::deque
#include <iostream>  // std::cout
#include <sstream>   // std::stringstream
#include <string>    // std::string
#include <vector>    // std::vector
// #include <iterator>  // std::distance

class PmergeMe
{
public:
    typedef int value_t;
    // struct Element;
    // typedef std::vector<Element *>::iterator vecIter;

    struct Element
    {
        value_t largest;
        Element *big;
        Element *small;
    };

    PmergeMe();
    PmergeMe(size_t size);
    PmergeMe(const PmergeMe &other);
    virtual ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);

    bool addValue(const std::string &str);
    void printValues() const;
    void printSortedValues() const;
    Element *newElement(value_t);

    /* sort using std::vector */
    void analyzeSortByVector();
    void sortByVector(std::vector<Element *> &vec);
    void insertInVector(std::vector<Element *> &vec, size_t len,
                        Element *toInsert);
    void deleteVector(std::vector<Element *> &vec);

    /* sort using std::deque */
    void analyzeSortByDeque();
    void sortByDeque(std::deque<Element *> &lst);
    void insertInDeque(std::deque<Element *> &lst, size_t len,
                       Element *toInsert);
    void deleteDeque(std::deque<Element *> &lst);

private:
    value_t *values;
    size_t size;

    static unsigned int stoui(const std::string &str);
};

#endif