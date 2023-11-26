/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:58:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/26 14:47:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    {
        std::cout << "TEST 1" << std::endl;
        std::vector<int> vec;
        for (size_t i = 0; i < 10; i++)
        {
            vec.push_back(i * i);
        }
        if (easyfind(vec, 1) != vec.end())
        {
            std::cout << "1 exists in the vector" << std::endl;
        }
        else
        {
            std::cout << "1 does not exists in the vector" << std::endl;
        }
    }

    {
        std::cout << std::endl << "TEST 2" << std::endl;
        std::list<int> lst;
        for (size_t i = 0; i < 10; i++)
        {
            lst.push_back(i * i);
        }
        if (easyfind(lst, 10) != lst.end())
        {
            std::cout << "10 exists in the list" << std::endl;
        }
        else
        {
            std::cout << "10 does not exists in the list" << std::endl;
        }
    }

    {
        std::cout << std::endl << "TEST 3" << std::endl;
        std::deque<int> deq;
        for (size_t i = 0; i < 10; i++)
        {
            deq.push_back(i * i);
        }
        if (easyfind(deq, 16) != deq.end())
        {
            std::cout << "16 exists in the deque" << std::endl;
        }
        else
        {
            std::cout << "16 does not exists in the deque" << std::endl;
        }
    }
    return 0;
}