/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:08:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/15 15:01:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm> // std::sort
#include <ctime>     // std::clock
#include <iostream>  // std::cout
#include <list>      // std::list
#include <sstream>   // std::stringstream
#include <string>    // std::string
#include <vector>    // std::vector
// #include <iterator>  // std::distance

class PmergeMe
{
public:
    typedef unsigned int value_t;
    struct Element
    {
        // public:
        //     Element();
        //     Element(const Element &other);
        //     virtual ~Element();
        //     Element &operator=(const Element &other);
        // private:
        value_t largest;
        Element *big;
        Element *small;
    };
    typedef std::vector<Element *>::iterator vecIter;

    PmergeMe();
    PmergeMe(size_t size);
    PmergeMe(const PmergeMe &other);
    virtual ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);

    bool addValue(const std::string &str);
    void printValues() const;
    void printSortedValues() const;
    Element *newElement(value_t);

    void analyzeSortByVector();
    void sortByVector(std::vector<Element *> &vec);
    void insertInVector(std::vector<Element *> &vec, size_t len,
                        Element *toInsert);
    void deleteVector(std::vector<Element *> &vec);

    void analyzeSortByList();
    void sortByList(std::list<Element *> &lst);
    void insertInList(std::list<Element *> &lst, size_t len, Element *toInsert);
    void deleteList(std::list<Element *> &lst);

private:
    value_t *values;
    size_t size;

    static unsigned int stoui(const std::string &str);
};

#endif