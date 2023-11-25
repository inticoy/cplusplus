/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:18:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 19:13:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> empty;
    Array<int> five(5);

    for (size_t i = 0; i < 5; i++)
    {
        five[i] = i * i;
    }
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << five[i] << std::endl;
    }

    return 0;
}