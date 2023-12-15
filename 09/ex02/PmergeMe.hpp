/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:08:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/15 16:51:33 by gyoon            ###   ########.fr       */
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
    struct Element
    {
        int max;
        Element *big;
        Element *small;
    };

    static int stoi(const std::string &str);
    static Element *newElement(int max, Element *big, Element *small);
    static void deleteElement(Element *ptr);

    PmergeMe();
    PmergeMe(size_t size);
    PmergeMe(const PmergeMe &other);
    virtual ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);

    bool addValue(const std::string &str);
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