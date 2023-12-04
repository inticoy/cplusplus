/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:59:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 23:06:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int main()
{
    {
        std::cout << "TEST 1\n";
        int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        size_t len = sizeof(arr) / sizeof(int);
        iter(arr, len, ::println);
    }

    {
        std::cout << "\nTEST 2\n";
        double arr[] = {42.0, 4.2, 0.42, 0.042};
        size_t len = sizeof(arr) / sizeof(double);
        iter(arr, len, ::println);
    }

    {
        std::cout << "\nTEST 3\n";
        std::string arr[] = {"42", "seoul", ",", "Korea"};
        size_t len = 4;
        iter(arr, len, ::println);
    }
    return 0;
}