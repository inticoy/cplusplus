/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:08:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/14 20:46:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef unsigned int value_t;

typedef struct element_s element_t;
struct element_s
{
    value_t largest;
    element_t *big;
    element_t *small;
};

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(size_t size);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);

    bool addValue(const std::string &str);
    void printValues() const;
    void printSortedValues() const;

    void sortByVector();

private:
    value_t *values;
    size_t size;

    static unsigned int stoui(const std::string &str);
};

#endif