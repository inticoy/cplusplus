/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:54:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/15 16:51:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

void leaks() { system("leaks PmergeMe"); }

int main(int argc, char *argv[])
{
    // atexit(leaks);
    if (argc < 2)
    {
        std::cerr << "usage: PmergeMe (sequence of positive integers)" << '\n';
        return 1;
    }
    else
    {
        PmergeMe pMergeMe(static_cast<size_t>(argc - 1));
        for (int i = 1; i < argc; ++i)
            pMergeMe.addValue(argv[i]);

        std::cout << "Before:\t";
        pMergeMe.printValues();
        std::cout << std::endl;
        std::cout << "After:\t";
        pMergeMe.printSortedValues();
        std::cout << std::endl;

        pMergeMe.analyzeSortingByVector();
        pMergeMe.analyzeSortingByDeque();

        return 0;
    }
}