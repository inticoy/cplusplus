/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:18:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/04 14:28:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> empty;

    Array<int> five(5);
    for (size_t i = 0; i < five.size(); i++)
        five[i] = i * i;

    std::cout << "arr:\t";
    for (size_t i = 0; i < five.size(); i++)
        std::cout << five[i] << ' ';

    Array<int> newFive(five);
    newFive[1] = -5;

    std::cout << "\ncopy:\t";
    for (size_t i = 0; i < newFive.size(); i++)
        std::cout << newFive[i] << ' ';

    std::cout << "\narr:\t";
    for (size_t i = 0; i < five.size(); i++)
        std::cout << five[i] << ' ';

    return 0;
}