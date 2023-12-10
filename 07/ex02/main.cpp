/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:18:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/10 13:42:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_VAL 10

int main()
{
    {
        std::cout << "TEST 1" << std::endl;
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
    }

    std::cout << std::endl << std::endl;

    {
        std::cout << "TEST 2" << std::endl;
        Array<int> numbers(MAX_VAL);
        int *mirror = new int[MAX_VAL];
        std::srand(std::time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = std::rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        // SCOPE
        Array<int> tmp = numbers;
        tmp[3] = 33;
        Array<int> test(tmp);
        test[6] = 66;

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }

        std::cout << "numbers: ";
        for (size_t i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << ' ';

        std::cout << "\nmirror:  ";
        for (size_t i = 0; i < MAX_VAL; i++)
            std::cout << mirror[i] << ' ';

        std::cout << "\ntmp:     ";
        for (size_t i = 0; i < tmp.size(); i++)
            std::cout << tmp[i] << ' ';

        std::cout << "\ntest:    ";
        for (size_t i = 0; i < test.size(); i++)
            std::cout << test[i] << ' ';

        delete[] mirror;
    }

    return 0;
}