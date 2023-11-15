/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:57:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/15 17:13:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    {
        std::cout << "\n[TEST 1]\n";

        Bureaucrat president("Gyoon", 1);

        try
        {
            std::cout << president << std::endl;
            president.decrementGrade();
            std::cout << president << std::endl;
            president.incrementGrade();
            std::cout << president << std::endl;
            president.incrementGrade();
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "\n[TEST 2]\n";

        Bureaucrat servant("Gyoon", 150);

        try
        {
            std::cout << servant << std::endl;
            servant.incrementGrade();
            std::cout << servant << std::endl;
            servant.decrementGrade();
            std::cout << servant << std::endl;
            servant.decrementGrade();
            std::cout << servant << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "\n[TEST 3]\n";

        Bureaucrat high("Gyoon", 10);

        try
        {
            for (;;)
            {
                std::cout << high << std::endl;
                high.incrementGrade();
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "\n[TEST 4]\n";

        Bureaucrat low("Gyoon", 140);

        try
        {
            for (;;)
            {
                std::cout << low << std::endl;
                low.decrementGrade();
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}
